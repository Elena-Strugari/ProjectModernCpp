#include "Game.h"
#include "Map.h"
#include "Wall.h"
//P.S. voi testa putin sa vad daca functioneaza initializarea hartii Map.

Game::Game() 
{
    InitializeMap();
}
void Game::TestRun()
{
    DisplayMap();
}
void Game::InitializeMap() {
    std::vector<std::vector<Wall*>> grid(5, std::vector<Wall*>(10, nullptr));
    grid[1][1] = new Wall(1, 1, Wall::Destructible::indestructible, true, 0);
    grid[2][3] = new Wall(2, 3, Wall::Destructible::destructible, true, 0);
    m_map = Map(10, 10, grid);
}

void Game::DisplayMap() const {
    for (uint16_t i = 0; i < m_map.GetHeight(); ++i) {
        for (uint16_t j = 0; j < m_map.GetWidth(); ++j) {
            if (auto wall = m_map.GetWallAt(i, j)) {
                std::cout << (wall->IsDestructible() == Wall::Destructible::indestructible ? '#' : '*');
            }
            else {
                std::cout << '0';
            }
        }
        std::cout << std::endl;
    }
}
//void Game::InitializeMap() {
//    
//    std::vector<std::vector<Wall*>> grid(5, std::vector<Wall*>(10, nullptr));
//
//    // Inițializăm harta
//    m_map = Map(10, 5, grid);
//
//    // Adăugăm câteva ziduri pe hartă folosind funcția AddWall din Map
//    m_map.AddWall(1, 1, Wall::Destructible::indestructible);
//    m_map.AddWall(2, 3, Wall::Destructible::destructible);
//    m_map.AddWall(4, 6, Wall::Destructible::indestructible);
//}

// Funcția pentru a afișa harta
//void Game::DisplayMap() const {
//    for (uint16_t i = 0; i < m_map.GetHeight(); ++i) {
//        for (uint16_t j = 0; j < m_map.GetWidth(); ++j) {
//            if (auto wall = m_map.GetWallAt(i, j)) {
//                // Afișează # pentru ziduri indestructibile și * pentru ziduri destructibile
//                std::cout << (wall->IsDistructible() == Wall::Destructible::indestructible ? '#' : '*');
//            }
//            else {
//                // Afișează 0 pentru spațiile goale
//                std::cout << '0';
//            }
//        }
//        std::cout << std::endl;
//    }
//}

void Game::start()
{
}

void Game::update()
{
}

void Game::checkCollisions()
{
}

void Game::HandleInput()
{
}

void Game::Run()
{
}
