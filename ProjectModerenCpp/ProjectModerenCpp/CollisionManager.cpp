#include "CollisionManager.h"
//#include "Map.h"
//#include "PlayerManager.h"
#include "Game.h"
#include <algorithm>
#include <memory>
#include <map>


CollisionManager::CollisionManager(std::shared_ptr<Map> map, std::shared_ptr<PlayerManager> playerManager)
    : m_map(map), m_playerManager(playerManager) {}

bool CollisionManager::IsValidPosition(uint16_t x, uint16_t y) const {
    if (x < 0 || y < 0 || x >= m_map->GetWidth() || y >= m_map->GetHeight()) {
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
        auto [x, y] = movement.GetPosition(false);

        auto [targetX, targetY] = movement.GetPosition(true);

        if (!IsValidPosition(targetX, targetY)) {
            std::cout << "Invalid position (" << targetX << ", " << targetY << "). Movement blocked.\n";
            continue;
        }

        bool isOccupiedByTank = std::any_of(players.begin(), players.end(),
            [&](const auto& targetPlayer) {
                if (player == targetPlayer) return false;
                auto& targetMovement = targetPlayer->GetMovementObject();
                auto [otherX, otherY] = targetMovement.GetPosition(false);
                return targetX == otherX && targetY == otherY;
            });

        if (isOccupiedByTank) {
            std::cout << "Position (" << targetX << ", " << targetY << ") is occupied by another tank. Movement blocked.\n";
            continue;
        }

        movement.SetPosition(targetX, targetY);
    }
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
