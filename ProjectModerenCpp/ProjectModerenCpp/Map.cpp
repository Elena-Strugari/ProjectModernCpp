#pragma once
#include "Map.h"
#include <cstdlib>  
#include <ctime>


Map::Map()
{
	uint16_t minVal=15, maxVal=20;   // pt nivel 1 
	// random val mat 
	std::srand(std::time(nullptr));
	m_width = minVal + std::rand() % (maxVal - minVal + 1);
	m_height = minVal + std::rand() % (maxVal - minVal + 1);	
	m_map.resize( m_width, std::vector<char>(m_height));

	for (int i = 0; i < m_width; ++i) {
		for (int j = 0; j < m_height; ++j) {
			m_map[i][j] = '_';
		}
	}
}

void Map::print() const
{
	for (const auto& row : m_map) {
		for (int val : row) {
			std::cout <<char( val) << " ";
		}
		std::cout << std::endl;
	}
}

void Map::AddWall(uint16_t x, uint16_t y, Wall::Destructible destructible)
{
	if (x >= 0 && x < m_width && y >= 0 && y < m_height)
	{
		if (destructible == Wall::Destructible::destructible)
			m_map[x][y] = '@';
		else
			m_map[x][y] = '#';
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
	/*AddWall(3, 4, Wall::Destructible::destructible);
	AddWall(3, 5, Wall::Destructible::destructible);
	AddWall(2, 7, Wall::Destructible::destructible);
	AddWall(8, 5, Wall::Destructible::destructible);
	AddWall(6, 2, Wall::Destructible::destructible);*/
	AddWall(0, 6, Wall::Destructible::indestructible);
	AddWall(1, 6, Wall::Destructible::indestructible);
	AddWall(1, 7, Wall::Destructible::indestructible);
	AddWall(3, 8, Wall::Destructible::indestructible);
	AddWall(4, 0, Wall::Destructible::indestructible);
	AddWall(4, 1, Wall::Destructible::indestructible);
	AddWall(4, 8, Wall::Destructible::indestructible);
	AddWall(5, 2, Wall::Destructible::indestructible);
	/*AddWall(3, 1, Wall::Destructible::destructible);
	AddWall(3, 6, Wall::Destructible::destructible);
	AddWall(4, 2, Wall::Destructible::destructible);
	AddWall(4, 3, Wall::Destructible::destructible);
	AddWall(2, 8, Wall::Destructible::destructible);
	AddWall(6, 4, Wall::Destructible::destructible);
	AddWall(5, 5, Wall::Destructible::destructible);
	AddWall(7, 4, Wall::Destructible::destructible);
	AddWall(4, 8, Wall::Destructible::destructible);
	AddWall(8, 3, Wall::Destructible::destructible);*/
	AddWall(5, 8, Wall::Destructible::indestructible);
	AddWall(5, 9, Wall::Destructible::indestructible);
	AddWall(5, 10, Wall::Destructible::indestructible);
	AddWall(5, 14, Wall::Destructible::indestructible);
	AddWall(6, 6, Wall::Destructible::indestructible);
	AddWall(6, 14, Wall::Destructible::indestructible);
	AddWall(7, 5, Wall::Destructible::indestructible);
	AddWall(7, 6, Wall::Destructible::indestructible);

	AddWall(7, 7, Wall::Destructible::indestructible);
	AddWall(10, 0, Wall::Destructible::indestructible);
	AddWall(10, 1, Wall::Destructible::indestructible);
	AddWall(10, 2, Wall::Destructible::indestructible);
	AddWall(10, 3, Wall::Destructible::indestructible);
	AddWall(10, 11, Wall::Destructible::indestructible);
	AddWall(10, 12, Wall::Destructible::indestructible);
	AddWall(12, 5, Wall::Destructible::indestructible);

	AddWall(12, 9, Wall::Destructible::indestructible);
	AddWall(12, 10, Wall::Destructible::indestructible);
	AddWall(12, 11, Wall::Destructible::indestructible);
	AddWall(12, 12, Wall::Destructible::indestructible);
	AddWall(13, 5, Wall::Destructible::indestructible);
	AddWall(13, 12, Wall::Destructible::indestructible);
	AddWall(14, 5, Wall::Destructible::indestructible);
	//AddWall(7, 6, Wall::Destructible::indestructible);

}
