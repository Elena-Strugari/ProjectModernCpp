#include "CollisionManager.h"
#include "Game.h"
#include <algorithm>
#include <memory>
#include <map>
#include <ranges>

struct PairHash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

CollisionManager::CollisionManager(std::shared_ptr<Map> map, std::shared_ptr<PlayerManager> playerManager)
    : m_map(map), m_playerManager(playerManager) {}

//bool CollisionManager::IsValidPosition(uint16_t x, uint16_t y) const {
//    if (x >= m_map->GetWidth() || y >= m_map->GetHeight()) {
//        return false;
//    }
//    auto& cell = m_map->GetCell(x, y);
//    if (typeid(cell.content) == typeid(Wall)) {
//        return false;
//    }
//
//    return true;
//}
template <typename T>
    requires std::is_integral_v<T>
bool CollisionManager::IsValidPosition(T x, T y) const {
    // Verificăm dacă poziția este în afara limitelor
    if (x < 0 || x >= static_cast<T>(m_map->GetWidth())) {
        return false; // Poziția este în afara limitelor
    }
    if (y < 0 || y >= static_cast<T>(m_map->GetHeight())) {
        return false; // Poziția este în afara limitelor
    }

    // Verificăm dacă poziția conține un zid
    const auto& cell = m_map->GetCell(static_cast<uint16_t>(x), static_cast<uint16_t>(y));
    //if (std::holds_alternative<Wall>(cell.content)) {
    //    return false; // Poziția este ocupată de un zid
    //}
    if (std::holds_alternative<Wall::TypeWall>(cell.content)) {
        const auto& wallType = std::get<Wall::TypeWall>(cell.content);
        if (wallType == Wall::TypeWall::indestructible || wallType == Wall::TypeWall::destructible) {
            return false; // Poziția este ocupată de un zid (indestructibil sau destructibil)
        }
    }


    return true; // Poziția este validă
}

std::optional<Map::Cell> CollisionManager::GetValidCell(uint16_t x, uint16_t y) const {
    if (x >= m_map->GetWidth() || y >= m_map->GetHeight()) {
        return std::nullopt; // Poziția este în afara limitelor
    }

    auto& cell = m_map->GetCell(x, y);
    if (typeid(cell.content) == typeid(Wall)) {
        return std::nullopt; // Poziția este ocupată de un zid
    }

    return cell; // Poziția este validă, returnăm celula
}


void CollisionManager::HandleBulletCollisions() {
    auto players = m_playerManager->GetAllPlayers();
    for (auto& player : players) {
        auto& movement = player->GetMovementObject();

        if (!movement.IsBulletActive()) continue;

        auto [x, y] = movement.GetPosition(true);


        /* if (!GetValidCell(x, y)) {
             movement.DeactivateBullet();
             continue;
         }*/
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

//void CollisionManager::HandleTankCollisions() {
//    auto players = m_playerManager->GetAllPlayers();
//    for (auto& player : players) {
//        auto& movement = player->GetMovementObject();
//        auto [currentX, currentY] = movement.GetPosition(false);
//        auto [targetX, targetY] = movement.GetPosition(true);
//
//        /*if (!IsValidPosition(targetX, targetY) || isOccupiedByAnotherTank(players, targetX, targetY, player)) {
//            std::cout << "Movement blocked: Invalid position or occupied (" << targetX << ", " << targetY << ").\n";
//            continue;
//        }*/
//        if (!GetValidCell(targetX, targetY) || isOccupiedByAnotherTank(players, targetX, targetY, player)) {
//            std::cout << "Movement blocked: Invalid position or occupied (" << targetX << ", " << targetY << ").\n";
//            continue;
//        }
//
//        movement.SetPosition(targetX, targetY);
//        m_map->SetCellContent(currentX, currentY, Map::Empty{});
//        m_map->SetCellContent(targetX, targetY, Map::Tank{});
//    }
//}

//void CollisionManager::HandleTankCollisions() {
//    auto players = m_playerManager->GetAllPlayers();
//    for (auto& player : players) {
//        auto& movement = player->GetMovementObject();
//        auto [currentX, currentY] = movement.GetPosition(false);
//        auto [targetX, targetY] = movement.GetPosition(true);
//
//        if (!IsValidPosition(targetX, targetY) || isOccupiedByAnotherTank(players, targetX, targetY, player)) {
//            std::cout << "Movement blocked: Invalid position or occupied (" << targetX << ", " << targetY << ").\n";
//            continue;
//        }
//
//        movement.SetPosition(targetX, targetY);
//        m_map->SetCellContent(currentX, currentY, Map::Empty{});
//        m_map->SetCellContent(targetX, targetY, Map::Tank{});
//    }
//}

void CollisionManager::HandleTankCollisions() {
    auto players = m_playerManager->GetAllPlayers();

    std::unordered_map<std::pair<uint16_t, uint16_t>, std::shared_ptr<Player>, PairHash> positionMap;

    for (auto& player : players) {
        auto [x, y] = player->GetMovementObject().GetPosition(false);
        positionMap[{x, y}] = player;
    }

    for (auto& player : players) {
        auto& movement = player->GetMovementObject();
        auto [currentX, currentY] = movement.GetPosition(false);
        auto [targetX, targetY] = movement.GetPosition(true);


        /* if (!GetValidCell(targetX, targetY) || positionMap.contains({ targetX, targetY })) {
             std::cout << "Movement blocked: Invalid position or occupied (" << targetX << ", " << targetY << ").\n";
             continue;
         }*/
        if (!IsValidPosition(targetX, targetY) || positionMap.contains({ targetX, targetY })) {
            std::cout << "Movement blocked: Invalid position or occupied (" << targetX << ", " << targetY << ").\n";
            continue;
        }

        movement.SetPosition(targetX, targetY);
        m_map->SetCellContent(currentX, currentY, Map::Empty{});
        m_map->SetCellContent(targetX, targetY, Map::Tank{});

        positionMap.erase({ currentX, currentY });
        positionMap[{targetX, targetY}] = player;
    }
}
//bool CollisionManager::isOccupiedByAnotherTank(const std::vector<std::shared_ptr<Player>>& players, uint16_t x, uint16_t y, const std::shared_ptr<Player>& currentPlayer) {
//    return std::any_of(players.begin(), players.end(), [&](const auto& player) {
//        if (player == currentPlayer) return false;
//        auto [px, py] = player->GetMovementObject().GetPosition(false);
//        return (px == x && py == y);
//        });
//} 

bool CollisionManager::isOccupiedByAnotherTank(const std::vector<std::shared_ptr<Player>>& players, uint16_t x, uint16_t y, const std::shared_ptr<Player>& currentPlayer) {
    // Folosim std::ranges::any_of pentru a verifica dacă poziția (x, y) este ocupată de alt tank
    auto positionOccupied = std::ranges::any_of(players, [&](const auto& player) {
        if (player == currentPlayer) return false; // Ignorăm tancul curent
        auto [px, py] = player->GetMovementObject().GetPosition(false);
        return (px == x && py == y); // Verificăm dacă alt tanc este la aceeași poziție
        });
    return positionOccupied;
}


//void CollisionManager::HandleBulletTankCollisions() {
//    auto players = m_playerManager->GetAllPlayers();
//    for (auto& player : players) {
//        auto& movement = player->GetMovementObject();
//        if (movement.IsBulletActive()) {
//            auto [bulletX, bulletY] = movement.GetPosition(true);
//
//            for (auto& targetPlayer : players) {
//                if (player != targetPlayer) {
//                    auto& targetMovement = targetPlayer->GetMovementObject();
//                    auto [tankX, tankY] = targetMovement.GetPosition(false);
//                    if (bulletX == tankX && bulletY == tankY) {
//                        targetPlayer->LoseLife();
//                        movement.DeactivateBullet();
//                        if (!targetPlayer->HasLife()) {
//                            m_playerManager->RemovePlayer(targetPlayer->GetName());
//                        }
//                    }
//                }
//            }
//        }
//    }
//}
void CollisionManager::HandleBulletTankCollisions() {
    auto players = m_playerManager->GetAllPlayers();

    // Lambda pentru a verifica și dezactiva glonțul dacă există coliziune cu un tanc
    auto deactivateIfColliding = [](auto& bullet, auto& target) {
        auto [bx, by] = bullet.GetPosition(true);  // Poziția glonțului
        auto [tx, ty] = target.GetPosition(false); // Poziția tancului
        if (bx == tx && by == ty) {
            bullet.DeactivateBullet();
            return true;
        }
        return false;
        };

    for (auto& player : players) {
        auto& movement = player->GetMovementObject();

        // Dacă glonțul nu este activ, trecem la următorul jucător
        if (!movement.IsBulletActive()) {
            continue;
        }

        // Poziția glonțului
        auto [bulletX, bulletY] = movement.GetPosition(true);

        for (auto& targetPlayer : players) {
            if (player != targetPlayer) {
                auto& targetMovement = targetPlayer->GetMovementObject();

                // Verifică coliziunea folosind lambda-ul
                if (deactivateIfColliding(movement, targetMovement)) {
                    targetPlayer->LoseLife();
                    if (!targetPlayer->HasLife()) {
                        m_playerManager->RemovePlayer(targetPlayer->GetName());
                    }
                }
            }
        }
    }
}
//void CollisionManager::AwardWinnerPoints(const std::shared_ptr<Player>& winner) {
//    if (winner) {
//        winner->AddScore(200);
//        std::cout << winner->GetName() << " a câștigat jocul și a primit 200 de puncte extra.\n";
//    }
//}
//
//void CollisionManager::TriggerBombExplosion(const Bomb& bomb)
//{
//    for (int dx = -1; dx <= 1; ++dx) {
//        for (int dy = -1; dy <= 1; ++dy) {
//            uint16_t nx = bomb.getX() + dx;
//            uint16_t ny = bomb.getY() + dy;
//
//            if (m_map->IsValidPosition(nx, ny)) {
//                auto& adjacentCell = m_map->GetCell(nx, ny).content;
//
//                std::visit(
//                    [&](auto&& cellContent) {
//                        using T = std::decay_t<decltype(cellContent)>;
//
//                        if constexpr (std::is_same_v<T, Bomb>) {
//                            TriggerBombExplosion(cellContent);
//                        }
//                        else if constexpr (std::is_same_v<T, Wall::TypeWall>) {
//                            if (cellContent == Wall::TypeWall::destructible) {
//                                m_map->SetCellContent(nx, ny, Map::Empty{});
//                                std::cout << "Zid distrus de explozie la (" << nx << ", " << ny << ").\n";
//                            }
//                        }
//                        else if constexpr (std::is_same_v<T, Tank>) {
//                            std::cout << "Tanc distrus de explozie la (" << nx << ", " << ny << ").\n";
//                            m_map->SetCellContent(nx, ny, Map::Empty{});
//                        }
//                    },
//                    adjacentCell);
//            }
//        }
//    }
//}