#include "Game.h"
#include "CollisionManager.h"
#include <iostream>
#include <stdexcept>

Game::Game(uint8_t level, const std::string& code)
    : m_map(level), m_playerManager(std::make_shared<PlayerManager>()),
    m_collision(std::make_shared<CollisionManager>(std::make_shared<Map>(m_map), m_playerManager)),
    m_gameCode(code), m_gameStarted(false) {
}

std::string Game::GenerateGameCode()
{
    std::string code;
    static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 6; ++i) {
        code += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return code;
   
}

void Game::AddPlayer(const std::shared_ptr<Player>& player) {
    player->AddPlayerObject();
    m_playerManager->AddPlayer(player);
    PlacePlayerOnMap(player);
}

void Game::Start() {
    std::cout << "Starting game..." << std::endl;
    m_map.DisplayMap();
}

void Game::PlacePlayerOnMap(const std::shared_ptr<Player>& player) {
    static std::vector<std::pair<uint16_t, uint16_t>> cornerPositions = {
        {1, 1},
        {1, m_map.GetHeight() - 2},
        {m_map.GetWidth() - 2, 1},
        {m_map.GetWidth() - 2, m_map.GetHeight() - 2}
    };

    static size_t nextCornerIndex = 0;

    auto [startX, startY] = cornerPositions[nextCornerIndex];
    nextCornerIndex = (nextCornerIndex + 1) % cornerPositions.size(); // Cycle through corners

    // Ensure the corner position is valid before placing the player
    /*if (!m_map.IsValidPosition(startX, startY) ||
        !std::holds_alternative<Map::Empty>(m_map.GetCell(startX, startY).content)) {
        throw std::runtime_error("Corner position is invalid for player placement.");
    }*/
    if (!m_map.IsValidPosition(startX, startY))
        std::cout << "erroare la valid";
    if (!std::holds_alternative<Map::Empty>(m_map.GetCell(startX, startY).content)) {
        std::cout << "eroare la cell";
    }

    auto& movement = player->GetMovementObject();
    movement.SetPosition(startX, startY);
    m_map.SetCellContent(startX, startY, Map::Tank{});
}



void Game::MovePlayer(const std::shared_ptr<Player>& player, MovementObject::Direction direction) {
    auto& movement = player->GetMovementObject();
    auto [currentX, currentY] = movement.GetPosition();

    auto [newX, newY] = movement.Move(direction);

    if (m_map.IsValidPosition(newX, newY)) {
        m_collision->HandleTankCollisions();
        m_map.SetCellContent(currentX, currentY, Map::Empty{});
        m_map.SetCellContent(newX, newY, Map::Tank{});

        movement.SetPosition(newX, newY);
        movement.SetDirection(direction);
    }
}

void Game::ShootBulletS(const std::shared_ptr<Player>& player) {
    auto& movement = player->GetMovementObject();
    movement.Shoot();
}

void Game::MoveBullets() {
    for (const auto& player : m_playerManager->GetAllPlayers()) {
        auto& movement = player->GetMovementObject();
        auto [currentX, currentY] = movement.GetPosition();

        if (movement.IsBulletActive()) {
            auto [newX, newY] = movement.Move(movement.GetDirection(), 1);
            if (m_map.IsValidPosition(newX, newY)) {
                m_collision->HandleBulletCollisions();

                if (std::holds_alternative<Map::Empty>(m_map.GetCell(newX, newY).content)) {
                    m_map.SetCellContent(currentX, currentY, Map::Empty{}); // Clear old position
                    m_map.SetCellContent(newX, newY, Map::Bullet{});
                }
                else {
                    movement.DeactivateBullet();
                    m_map.SetCellContent(currentX, currentY, Map::Empty{}); // Clear bullet
                }
            }
        }
    }

}