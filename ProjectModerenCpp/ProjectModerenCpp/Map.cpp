#pragma once
#include "Map.h"
#include <cstdlib>  
#include <ctime>
#include<vector>

Map::Map() {}

Map::Map(uint8_t level)
{
    //std::cout << "sunt in costructor cu level "<<level;

    auto [minVal, maxVal] = getLevelBounds(level);

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    m_width = minVal + std::rand() % (maxVal - minVal + 1);
    m_height = minVal + std::rand() % (maxVal - minVal + 1);

    m_map.resize(m_width, std::vector<Map::Cell>(m_height));

    for (size_t i = 0; i < m_width; ++i) {
        for (size_t j = 0; j < m_height; ++j) {
            if (i == 0 || i == m_width - 1 || j == 0 || j == m_height - 1) {
                m_map[i][j] = { Wall::TypeWall::indestructible, ' ', 1 }; // Border 
            }
            else {
                m_map[i][j] = { Wall::TypeWall::destructible, '_', 0 };  // Spațiu interior
            }
        }
    }
}


std::pair<uint16_t, uint16_t> Map::getLevelBounds(uint8_t level) const
{
    switch (level) {
    case 1: return { 15, 20 };
    case 2: return { 20, 25 };
    case 3: return { 25, 30 };
    default:
        throw std::invalid_argument("Nivel invalid! Nivelul trebuie să fie 1, 2 sau 3.");
    }
}

//Get 
uint16_t Map::GetWidth() const
{
    return m_width;
}
uint16_t Map::GetHeight() const
{
    return m_height;
}
Map::Cell Map::GetType() const
{
    return m_cellType;
}

std::vector<std::vector<Map::Cell>> Map::GetMap() const
{
    return m_map;

}

//Add

void Map::AddWall(uint16_t x, uint16_t y, Wall::TypeWall typeWall)
{
    if (IsValidPosition(x, y))
    {
        Wall wall(typeWall);
        m_map[x][y].typeWall = typeWall;

        // Dacă peretele este destructibil, setăm simbolul 'space' la '@', altfel la '#'
        m_map[x][y].space = (typeWall == Wall::TypeWall::destructible) ? '@' : '#';
        // m_wall.push_back(wall);
    }
}

// validation
bool Map::IsValidPosition(uint16_t x, uint16_t y) const {
    return x >= 0 && x < m_width && y >= 0 && y < m_height;
}




//display 
void Map::DisplayMap()const {

    for (const auto& row : m_map) {
        for (const auto& cell : row) {
            if (cell.border == 1) {
                std::cout << "H";
            }
            else
                if (cell.space == '_')
                    std::cout << "_";
                else {
                    switch (cell.typeWall) {
                    case Wall::TypeWall::destructible:
                        std::cout << "@";  //destructible
                        break;
                    case Wall::TypeWall::indestructible:
                        std::cout << "#";  // indestructible
                        break;
                    }
                }
        }
        std::cout << std::endl;
    }
}



std::vector<std::pair<uint16_t, uint16_t>> Map::RandomWall(uint16_t width, uint16_t height, int numberOfWalls)
{
    std::vector<std::pair<uint16_t, uint16_t>> randomWalls;

    // Inițializăm generatorul de numere aleatoare cu time(0) pentru a obține rezultate diferite de fiecare dată
    srand(static_cast<unsigned int>(time(0)));

    // Generăm pereți aleatori
    for (int i = 0; i < numberOfWalls; ++i)
    {
        uint16_t x = rand() % width;  // Coordonata X aleatoare în intervalul [0, width-1]
        uint16_t y = rand() % height; // Coordonata Y aleatoare în intervalul [0, height-1]
        randomWalls.push_back({ x, y });  // Adăugăm perechea (x, y) în vectorul de pereți
    }
    return randomWalls;


}

void Map::GenerateWalls(uint8_t level)
{
    uint16_t height = GetHeight();
    uint16_t width = GetWidth();

    // A helper function to add a list of walls
    auto addWalls = [this](const std::vector<std::pair<uint16_t, uint16_t>>& coordinates, Wall::TypeWall type) {
        for (const auto& coord : coordinates) {
            AddWall(coord.first, coord.second, type);
        }
        };

    // A helper function to generate random walls
    auto generateRandomWalls = [this, width, height](int numWalls) {
        return RandomWall(width, height, numWalls);
        };

    switch (level)
    {
    case 1: {
        // Define fixed indestructible walls for level 1
        std::vector<std::pair<uint16_t, uint16_t>> indestructibleWalls = {
            {0, 6}, {1, 6}, {1, 7}, {3, 8}, {4, 0}, {4, 1}, {4, 8},
            {5, 2}, {5, 8}, {5, 9}, {5, 10}, {5, 14}, {6, 6}, {6, 14},
            {7, 5}, {7, 6}, {7, 7}, {10, 0}, {10, 1}, {10, 2}, {10, 3},
            {10, 11}, {10, 12}, {12, 5}, {12, 9}, {12, 10}, {12, 11},
            {12, 12}, {13, 5}, {13, 12}, {14, 5}, {12, 13}, {13, 14},
            {14, 13}, {9, 5}, {8, 6}, {7, 8}, {6, 9}, {5, 11}, {4, 12},
            {3, 13}, {2, 14}
        };
        addWalls(indestructibleWalls, Wall::TypeWall::indestructible);

        // Random indestructible walls
        auto randomIndestructibleWalls = generateRandomWalls(15);
        addWalls(randomIndestructibleWalls, Wall::TypeWall::indestructible);

        // Destructible walls
        std::vector<std::pair<uint16_t, uint16_t>> destructibleWalls = {
            {2, 2}, {2, 6}, {2, 9}, {6, 9}, {8, 8}, {11, 4}, {11, 9}, {13, 7}, {14, 10}
        };
        addWalls(destructibleWalls, Wall::TypeWall::destructible);

        // Random destructible walls
        auto randomDestructibleWalls = generateRandomWalls(40);
        addWalls(randomDestructibleWalls, Wall::TypeWall::destructible);

        break;
    }

    case 2: {
        // Define fixed indestructible walls for level 2
        std::vector<std::pair<uint16_t, uint16_t>> indestructibleWalls = {
            {2, 1}, {2, 2}, {2, 3}, {0, 7}, {0, 8}, {0, 9}, {1, 8}, {2, 8}, {3, 8},
            {4, 12}, {1, 16}, {2, 16}, {6, 6}, {6, 7}, {6, 8}, {6, 9}, {7, 13}, {8, 13},
            {9, 13}, {10, 11}, {10, 12}, {9, 19}, {7, 19}, {8, 19}, {8, 18}, {9, 4},
            {10, 4}, {11, 4}, {13, 5}, {11, 1}, {11, 2}, {11, 3}, {11, 4}, {11, 7},
            {12, 7}, {13, 7}, {14, 7}, {11, 4}, {14, 8}, {14, 9}, {15, 2}, {18, 4},
            {19, 4}, {17, 12}, {17, 13}, {17, 14}, {16, 13}, {18, 14}, {15, 18}
        };
        addWalls(indestructibleWalls, Wall::TypeWall::indestructible);

        // Random indestructible walls
        auto randomIndestructibleWalls = generateRandomWalls(15);
        addWalls(randomIndestructibleWalls, Wall::TypeWall::indestructible);

        // Random destructible walls
        auto randomDestructibleWalls = generateRandomWalls(50);
        addWalls(randomDestructibleWalls, Wall::TypeWall::destructible);

        break;
    }
    case 3: {
        // Define fixed indestructible walls for level 3

        std::vector<std::pair<uint16_t, uint16_t>> indestructibleWalls = {
            {0, 2}, {0, 3}, {0, 4}, {2, 9}, {2, 10}, {2, 19}, {2, 20}, {2, 21},
            {2, 22}, {2, 23}, {2, 24}, {3, 9}, {3, 10}, {3, 24}, {4, 11}, {4, 12},
            {4, 24}, {5, 24}, {6, 24}, {7, 24}, {8, 3}, {8, 4}, {8, 24}, {9, 4},
            {10, 4}, {10, 11}, {10, 12}, {10, 13}, {10, 14}, {11, 7}, {11, 10},
            {11, 12}, {12, 5}, {12, 6}, {12, 12}, {13, 4}, {13, 5}, {13, 6}, {13, 12},
            {14, 12}, {14, 19}, {15, 1}, {15, 19}, {16, 1}, {16, 19}, {17, 1},
            {17, 18}, {17, 19}, {18, 1}, {18, 19}, {18, 20}, {18, 21}, {19, 1},
            {19, 13}, {19, 21}, {19, 22}, {20, 8}, {21, 3}, {21, 12}, {21, 13},
            {21, 14}, {22, 8}, {22, 14}, {22, 15}, {22, 16}, {23, 8}, {23, 16},
            {24, 8}, {24, 16}
        };
        addWalls(indestructibleWalls, Wall::TypeWall::indestructible);

        // Random indestructible walls
        auto randomIndestructibleWalls = generateRandomWalls(15);
        addWalls(randomIndestructibleWalls, Wall::TypeWall::indestructible);

        // Destructible walls
        std::vector<std::pair<uint16_t, uint16_t>> destructibleWalls = {
            {1, 9}, {2, 8}, {3, 7}, {3, 8}, {3, 20}, {3, 21}, {3, 22}, {3, 23},
            {4, 6}, {4, 7}, {5, 6}, {5, 7}, {7, 17}, {7, 18}, {8, 17}, {8, 18},
            {9, 17}, {9, 18}, {11, 4}, {12, 4}, {15, 12}, {16, 12}, {17, 12},
            {17, 13}
        };
        addWalls(destructibleWalls, Wall::TypeWall::destructible);

        // Random destructible walls
        auto randomDestructibleWalls = generateRandomWalls(40);
        addWalls(randomDestructibleWalls, Wall::TypeWall::destructible);

        break;
    }

    default:
        break;
    }
}
