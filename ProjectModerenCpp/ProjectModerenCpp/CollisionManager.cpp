#include "CollisionManager.h"
#include "Game.h"
#include <algorithm>
#include <memory>
#include <map>


CollisionManager::CollisionManager(std::shared_ptr<Map> map, std::shared_ptr<PlayerManager> playerManager)
    : m_map(map), m_playerManager(playerManager) {}

bool CollisionManager::IsValidPosition(uint16_t x, uint16_t y) const {
    if (x >= m_map->GetWidth() || y >= m_map->GetHeight()) {
        return false;
    }
    auto& cell = m_map->GetCell(x, y);
    if (typeid(cell.content) == typeid(Wall)) {
        return false;
    }

    return true;
}

void CollisionManager::HandleBulletCollisions() {
    auto players = m_playerManager->GetAllPlayers();
    for (auto& player : players) {
        auto& movement = player->GetMovementObject();

        if (!movement.IsBulletActive()) continue;

        auto [x, y] = movement.GetPosition(true);

        if (!IsValidPosition(x, y)) {
            movement.DeactivateBullet();
            continue;
        }

        for (auto& targetPlayer : players) {
            if (player == targetPlayer) continue;

            auto& targetMovement = targetPlayer->GetMovementObject();
            if (targetMovement.IsBulletActive()) {
                auto [targetX, targetY] = targetMovement.GetPosition(true);
                if (x == targetX && y == targetY) {
                    movement.DeactivateBullet();
                    targetMovement.DeactivateBullet();
                }
            }
        }
    }
}

void CollisionManager::HandleTankCollisions() {
    auto players = m_playerManager->GetAllPlayers();
    for (auto& player : players) {
        auto& movement = player->GetMovementObject();
        auto [currentX, currentY] = movement.GetPosition(false);
        auto [targetX, targetY] = movement.GetPosition(true);

        if (!IsValidPosition(targetX, targetY) || isOccupiedByAnotherTank(players, targetX, targetY, player)) {
            std::cout << "Movement blocked: Invalid position or occupied (" << targetX << ", " << targetY << ").\n";
            continue;
        }

        movement.SetPosition(targetX, targetY);
        m_map->SetCellContent(currentX, currentY, Map::Empty{});
        m_map->SetCellContent(targetX, targetY, Map::Tank{});
    }
}
bool CollisionManager::isOccupiedByAnotherTank(const std::vector<std::shared_ptr<Player>>& players, uint16_t x, uint16_t y, const std::shared_ptr<Player>& currentPlayer) {
    return std::any_of(players.begin(), players.end(), [&](const auto& player) {
        if (player == currentPlayer) return false;
        auto [px, py] = player->GetMovementObject().GetPosition(false);
        return (px == x && py == y);
        });
}



void CollisionManager::HandleBulletTankCollisions() {
    auto players = m_playerManager->GetAllPlayers();
    for (auto& player : players) {
        auto& movement = player->GetMovementObject();
        if (movement.IsBulletActive()) {
            auto [bulletX, bulletY] = movement.GetPosition(true);

            for (auto& targetPlayer : players) {
                if (player != targetPlayer) {
                    auto& targetMovement = targetPlayer->GetMovementObject();
                    auto [tankX, tankY] = targetMovement.GetPosition(false);
                    if (bulletX == tankX && bulletY == tankY) {
                        targetPlayer->LoseLife();
                        movement.DeactivateBullet();
                        if (!targetPlayer->HasLife()) {
                            m_playerManager->RemovePlayer(targetPlayer->GetName());
                        }
                    }
                }
            }
        }
    }
}