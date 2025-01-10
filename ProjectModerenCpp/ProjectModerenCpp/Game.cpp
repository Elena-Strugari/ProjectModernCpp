//#include "Game.h"
//#include <iostream>
//
//// Constructor
//Game::Game(uint8_t level)
//    : m_map(level), m_playerManager() {}//, m_collision(m_map) {}
//
//// Adaugă un jucător în joc
//void Game::AddPlayer(std::shared_ptr<Player> player) {
//    m_playerManager.AddPlayer(player);
//}
//
//// Mută un jucător într-o direcție specificată
//void Game::MovePlayer(const std::string& playerName, MovementObject::Direction direction) {
//    auto player = m_playerManager.GetPlayer(playerName);
//    if (player) {
//        player->GetMovementObject().Move(direction);
//        std::cout << "Player " << playerName << " moved.\n";
//
//        // Verificare coliziune după mutare
//       // m_collision.CheckPlayerCollision(*player);
//    }
//    else {
//        std::cerr << "Player " << playerName << " not found.\n";
//    }
//}
//
//// Actualizează starea jocului
////void Game::Update() {
////    for (const auto& player : m_playerManager.GetAllPlayers()) {
////        // Verifică coliziunile pentru fiecare jucător
////        //m_collision.CheckPlayerCollision(*player);
////    }
////}
//
//// Afișează starea jocului
//void Game::Display() const {
//    m_map.DisplayMap();
//    for (const auto& player : m_playerManager.GetAllPlayers()) {
//        auto position = player->GetMovementObject().GetPosition();
//        std::cout << "Player: " << player->GetName()
//            << " Position: (" << position.first << ", " << position.second << ")\n";
//    }
//}

#include "Game.h"

Game::Game(uint8_t level)
    : m_map(level), m_playerManager(std::make_shared<PlayerManager>()) {}

// Adaugă jucători în manager
void Game::AddPlayer(const std::shared_ptr<Player>& player) {
    m_playerManager->AddPlayer(player);
}

// Pornește jocul
void Game::Start() {
    std::cout << "Starting game..." << std::endl;
    m_map.DisplayMap();
    std::cout << "Number of players: " << m_playerManager->GetPlayerCount() << std::endl;
}

// Mută un jucător într-o direcție specificată
void Game::MovePlayer(const std::string& playerName, MovementObject::Direction direction) {
    auto player = m_playerManager->GetPlayer(playerName);
    if (!player) {
        std::cerr << "Player \"" << playerName << "\" not found!" << std::endl;
        return;
    }

    auto& movement = player->GetMovementObject();
    auto [x, y] = movement.GetPosition();

    movement.Move(direction);
    auto [newX, newY] = movement.GetPosition();

    if (!m_map.IsValidPosition(newX, newY)) {
        movement.SetPosition(x, y); 
        return;
    }
}