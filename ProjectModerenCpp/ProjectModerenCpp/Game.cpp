//#include "Game.h"
//
//Game::Game(uint8_t level)
//    : m_map(level), m_playerManager(std::make_shared<PlayerManager>()) {}
//
//// Adaugă jucători în manager
//
//void Game::AddPlayer(const std::shared_ptr<Player>& player) {
//    m_playerManager->AddPlayer(player);
//    std::cout << "Player " << player->GetName() << " added to the game." << std::endl;
//
//    // Place the player on the map
//    PlacePlayerOnMap(player);
//}
//
//void Game::PlacePlayerOnMap(const std::shared_ptr<Player>& player) {
//    auto& movement = player->GetMovementObject();
//    uint16_t startX=0, startY=0;
//
//    // Find a valid position on the map to place the player
//   /* do {
//        startX = rand() % m_map.GetWidth();
//        startY = rand() % m_map.GetHeight();
//    } while (!m_map.IsValidPosition(startX, startY) || m_map.GetCell(startX, startY).typeWall != Wall::TypeWall::destructible);*/
//
//    // Set the player's position
//   // movement.SetPosition(startX, startY);
//
//    // Update the map to reflect the player's presence
//    //auto& cell = m_map.GetCell(startX, startY);
//   // cell.space = 'P'; // Use 'P' to represent the player on the map
//    std::cout << "Player placed at (" << startX << ", " << startY << ")." << std::endl;
//}
//
//
//// Pornește jocul
//void Game::Start() {
//    std::cout << "Starting game..." << std::endl;
//    m_map.DisplayMap();
//    std::cout << "Number of players: " << m_playerManager->GetPlayerCount() << std::endl;
//}
//
//// Mută un jucător într-o direcție specificată
//void Game::MovePlayer(const std::string& playerName, MovementObject::Direction direction) {
//    auto player = m_playerManager->GetPlayer(playerName);
//    if (!player) {
//        std::cerr << "Player \"" << playerName << "\" not found!" << std::endl;
//        return;
//    }
//
//    auto& movement = player->GetMovementObject();
//    auto [x, y] = movement.GetPosition();
//
//    movement.Move(direction);
//    auto [newX, newY] = movement.GetPosition();
//
//    //if (!m_map.IsValidPosition(newX, newY) || m_map.GetCell(newX, newY).typeWall == Wall::TypeWall::indestructible) {
//    //    std::cerr << "Invalid move. Player remains at (" << x << ", " << y << ")." << std::endl;
//    //    movement.SetPosition(x, y); // Reset position
//    //    return;
//    //}
//
//    // Update the map to reflect the movement
//   // m_map.GetCell(x, y).space = '_'; // Clear old position
//    //m_map.GetCell(newX, newY).space = 'P'; // Mark new position
//
//    std::cout << "Player \"" << playerName << "\" moved to (" << newX << ", " << newY << ")." << std::endl;
//}


#include "Game.h"
#include <iostream>
#include <stdexcept>

Game::Game(uint8_t level)
    : m_map(level), m_playerManager(std::make_shared<PlayerManager>()) {
    std::cout << "Game initialized at level " << static_cast<int>(level) << std::endl;
}

void Game::AddPlayer(const std::shared_ptr<Player>& player) {
    m_playerManager->AddPlayer(player);
    PlacePlayerOnMap(player);
    std::cout << "Player " << player->GetName() << " added to the game." << std::endl;
}

void Game::Start() {
    std::cout << "Starting game..." << std::endl;
    m_map.DisplayMap();
    std::cout << "Number of players: " << m_playerManager->GetPlayerCount() << std::endl;
}

void Game::PlacePlayerOnMap(const std::shared_ptr<Player>& player) {
    auto& movement = player->GetMovementObject();
    uint16_t startX, startY;

    do {
        startX = rand() % m_map.GetWidth();
        startY = rand() % m_map.GetHeight();
    } while (!m_map.IsValidPosition(startX, startY) ||
        !std::holds_alternative<Map::Empty>(m_map.GetCell(startX, startY).content));

    movement.SetPosition(startX, startY);
    m_map.SetCellContent(startX, startY, Map::Tank{});
    std::cout << "Player " << player->GetName() << " placed at (" << startX << ", " << startY << ")." << std::endl;
}

void Game::MovePlayer(const std::shared_ptr<Player>& player, MovementObject::Direction direction) {
    auto& movement = player->GetMovementObject();
    auto [currentX, currentY] = movement.GetPosition();

    uint16_t newX = currentX, newY = currentY;

    switch (direction) {
    case MovementObject::Direction::Up:    newY--; break;
    case MovementObject::Direction::Down:  newY++; break;
    case MovementObject::Direction::Left:  newX--; break;
    case MovementObject::Direction::Right: newX++; break;
    }

    if (IsValidMove(newX, newY)) {
        // Update the map
        m_map.SetCellContent(currentX, currentY, Map::Empty{}); // Clear the old position
        m_map.SetCellContent(newX, newY, Map::Tank{});          // Set the new position

        // Update the player's movement object
        movement.SetPosition(newX, newY);
        std::cout << "Player " << player->GetName() << " moved to (" << newX << ", " << newY << ")." << std::endl;
    }
    else {
        std::cout << "Invalid move for player " << player->GetName() << " to (" << newX << ", " << newY << ")." << std::endl;
    }
}

bool Game::IsValidMove(uint16_t x, uint16_t y) const {
    return m_map.IsValidPosition(x, y) && std::holds_alternative<Map::Empty>(m_map.GetCell(x, y).content);
}


/*
void Game::MovePlayer(const std::shared_ptr<Player>& player, MovementObject::Direction direction) {
    auto& movement = player->GetMovementObject();
    auto [currentX, currentY] = movement.GetPosition();

    uint16_t newX = currentX, newY = currentY;

    switch (direction) {
    case MovementObject::Direction::Up:    newY--; break;
    case MovementObject::Direction::Down:  newY++; break;
    case MovementObject::Direction::Left:  newX--; break;
    case MovementObject::Direction::Right: newX++; break;
    }

    if (IsValidMove(newX, newY)) {
        // Update the map
        m_map.SetCellContent(currentX, currentY, Map::Empty{}); // Clear the old position
        m_map.SetCellContent(newX, newY, Map::Tank{});          // Set the new position

        // Update the player's movement object
        movement.SetPosition(newX, newY);
        std::cout << "Player " << player->GetName() << " moved to (" << newX << ", " << newY << ")." << std::endl;
    }
    else {
        std::cout << "Invalid move for player " << player->GetName() << " to (" << newX << ", " << newY << ")." << std::endl;
    }
}

bool Game::IsValidMove(uint16_t x, uint16_t y) const {
    return m_map.IsValidPosition(x, y) && std::holds_alternative<Map::Empty>(m_map.GetCell(x, y).content);
}


*/