#pragma once
#include "Map.h"
#include <cstdlib>  
#include <ctime>


Map::Map()
{
	uint8_t minVal=15, maxVal=20;   // pt nivel 1 
	// random val mat 
	std::srand(std::time(nullptr));
	m_width = minVal + std::rand() % (maxVal - minVal + 1);
	m_height = minVal + std::rand() % (maxVal - minVal + 1);	
	m_map.resize( m_width, std::vector<int>(m_height));

	for (int i = 0; i < m_width; ++i) {
		for (int j = 0; j < m_height; ++j) {
			m_map[i][j] = 0; 
		}
	}
}

void Map::print() const
{
	for (const auto& row : m_map) {
		for (int val : row) {
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
}

void Map::AddWall(uint16_t x, uint16_t y, Wall::Destructible destructible)
{
	if (x >= 0 && x < m_width && y >= 0 && y < m_height)
	{
		if (destructible == Wall::Destructible::destructible)
			m_map[x][y] = 2;
		else
			m_map[x][y] = 1;
	}
}
uint16_t Map::GetWidth() const
{
	return m_width;
}

uint16_t Map::GetHeight() const
{
	return m_height;
}
void Map::GenerateWalls()
{
	//astea vor fi pentru verificare daca corespund indicii cu dimensiunile hartii

	uint16_t height = GetHeight();
	uint16_t width = GetWidth();
	AddWall(3, 4, Wall::Destructible::destructible);
	AddWall(3, 5, Wall::Destructible::destructible);
	AddWall(2, 7, Wall::Destructible::destructible);
	AddWall(8, 5, Wall::Destructible::destructible);
	AddWall(6, 2, Wall::Destructible::destructible);
	AddWall(3, 10, Wall::Destructible::indestructible);
	AddWall(7, 7, Wall::Destructible::indestructible);
	AddWall(3, 7, Wall::Destructible::indestructible);
	AddWall(5, 9, Wall::Destructible::indestructible);
	AddWall(10, 8, Wall::Destructible::indestructible);
	AddWall(9, 1, Wall::Destructible::indestructible);
	AddWall(9, 3, Wall::Destructible::indestructible);
	AddWall(7, 8, Wall::Destructible::indestructible);
	AddWall(3, 1, Wall::Destructible::destructible);
	AddWall(3, 6, Wall::Destructible::destructible);
	AddWall(4, 2, Wall::Destructible::destructible);
	AddWall(4, 3, Wall::Destructible::destructible);
	AddWall(2, 8, Wall::Destructible::destructible);
	AddWall(6, 4, Wall::Destructible::destructible);
	AddWall(5, 5, Wall::Destructible::destructible);
	AddWall(7, 4, Wall::Destructible::destructible);
	AddWall(4, 8, Wall::Destructible::destructible);
	AddWall(8, 3, Wall::Destructible::destructible);
	AddWall(1, 3, Wall::Destructible::indestructible);
	AddWall(8, 6, Wall::Destructible::indestructible);
	AddWall(10, 2, Wall::Destructible::indestructible);
	AddWall(6, 9, Wall::Destructible::indestructible);
	AddWall(4, 7, Wall::Destructible::indestructible);
	AddWall(2, 6, Wall::Destructible::indestructible);
	AddWall(9, 7, Wall::Destructible::indestructible);
	AddWall(1, 5, Wall::Destructible::indestructible);

}
