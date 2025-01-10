#include "Game.h"
#include <iostream>

Game::Game(uint8_t level)
    : m_map(level), m_collisionManager(m_map) {}

void Game::addPlayer(Player* player, MovementObject* movement) {
    m_players.emplace_back(player, movement);
}

void Game::update() {
    // Actualizează starea jocului (de exemplu, proiectile, coliziuni)
    for (const auto& [player, movement] : m_players) {
        auto [x, y] = movement->GetPosition();
        if (m_collisionManager.checkCollision(x, y)) {
           // std::cout << "Collision detected for player " << player->getName() << " at (" << x << ", " << y << ")." << std::endl;
           // player->loseLife(); // Pierde o viață dacă există coliziune
        }
    }
}

void Game::movePlayer(Player* player, MovementObject::Direction direction) {
    for (auto& [currentPlayer, movement] : m_players) {
        if (currentPlayer == player) {
            auto [x, y] = movement->GetPosition();
            uint16_t newX = x, newY = y;

            switch (direction) {
            case MovementObject::Direction::Up:    newY--; break;
            case MovementObject::Direction::Down:  newY++; break;
            case MovementObject::Direction::Left:  newX--; break;
            case MovementObject::Direction::Right: newX++; break;
            }

            if (m_collisionManager.isPositionValid(newX, newY) &&
                !m_collisionManager.checkCollision(newX, newY)) {
                movement->Move(direction);
                //std::cout << "Player " << player->getName() << " moved to (" << newX << ", " << newY << ")." << std::endl;
            }
            else {
               // std::cout << "Player " << player->getName() << " hit an obstacle at (" << newX << ", " << newY << ")." << std::endl;
            }
        }
    }
}




//#include "Game.h"
//#include "Map.h"
//#include "Wall.h"
////P.S. voi testa putin sa vad daca functioneaza initializarea hartii Map.
//
//Game::Game() 
//{
//    InitializeMap();
//}
//void Game::TestRun()
//{
//    DisplayMap();
//}
//void Game::InitializeMap() {
//    std::vector<std::vector<Wall*>> grid(5, std::vector<Wall*>(10, nullptr));
//    grid[1][1] = new Wall(1, 1, Wall::Destructible::indestructible, true, 0);
//    grid[2][3] = new Wall(2, 3, Wall::Destructible::destructible, true, 0);
//    m_map = Map(10, 10, grid);
//}
//
//void Game::DisplayMap() const {
//    for (uint16_t i = 0; i < m_map.GetHeight(); ++i) {
//        for (uint16_t j = 0; j < m_map.GetWidth(); ++j) {
//            if (auto wall = m_map.GetWallAt(i, j)) {
//                std::cout << (wall->IsDestructible() == Wall::Destructible::indestructible ? '#' : '*');
//            }
//            else {
//                std::cout << '0';
//            }
//        }
//        std::cout << std::endl;
//    }
//}
////void Game::InitializeMap() {
////    
////    std::vector<std::vector<Wall*>> grid(5, std::vector<Wall*>(10, nullptr));
////
////    // Inițializăm harta
////    m_map = Map(10, 5, grid);
////
////    // Adăugăm câteva ziduri pe hartă folosind funcția AddWall din Map
////    m_map.AddWall(1, 1, Wall::Destructible::indestructible);
////    m_map.AddWall(2, 3, Wall::Destructible::destructible);
////    m_map.AddWall(4, 6, Wall::Destructible::indestructible);
////}
//
//// Funcția pentru a afișa harta
////void Game::DisplayMap() const {
////    for (uint16_t i = 0; i < m_map.GetHeight(); ++i) {
////        for (uint16_t j = 0; j < m_map.GetWidth(); ++j) {
////            if (auto wall = m_map.GetWallAt(i, j)) {
////                // Afișează # pentru ziduri indestructibile și * pentru ziduri destructibile
////                std::cout << (wall->IsDistructible() == Wall::Destructible::indestructible ? '#' : '*');
////            }
////            else {
////                // Afișează 0 pentru spațiile goale
////                std::cout << '0';
////            }
////        }
////        std::cout << std::endl;
////    }
////}
//
//void Game::start()
//{
//}
//
//void Game::update()
//{
//}
//
//void Game::checkCollisions()
//{
//}
//
//void Game::HandleInput()
//{
//}
//
//void Game::Run()
//{
//}
