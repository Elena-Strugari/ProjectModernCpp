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
