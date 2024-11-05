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
    m_map = Map(10, 5, grid);
}

void Game::DisplayMap() const {
    for (uint16_t i = 0; i < m_map.GetHeight(); ++i) {
        for (uint16_t j = 0; j < m_map.GetWidth(); ++j) {
            if (auto wall = m_map.GetWallAt(i, j)) {
                std::cout << (wall->IsDistructible() == Wall::Destructible::indestructible ? '#' : '*');
            }
            else {
                std::cout << '0';
            }
        }
        std::cout << std::endl;
    }
}

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
