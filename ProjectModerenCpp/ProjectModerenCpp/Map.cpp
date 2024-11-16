#pragma once
#include "Map.h"
#include <cstdlib>  
#include <ctime>
#include<vector>

Map::Map(uint8_t level)
{
	uint16_t minVal, maxVal;   // pt nivel 1 
	// random val mat 
	if (level == 1)
	  {minVal = 15, maxVal = 20;}
	else if (level == 2)
	  {minVal = 20, maxVal = 25;}
	else  //leveel==3
	  {minVal = 25, maxVal = 30;}
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
void Map::PrintWithBorder()const
{
	int rows = m_map.size();
	int cols = m_map[0].size();

	for (int i = 0; i < (cols+1)*2; i++) 
	{
		std::cout << "#";
	}
	std::cout << '\n';
	for (const auto& row : m_map)
	{
		std::cout << "#"; 
		for (int val : row)
		{
			std::cout << char(val) << " ";
		}
		std::cout << "#" << '\n';
	}
	//std::cout << "#";
	for (int i = 0; i < (cols+1)*2; ++i) 
	{
		std::cout << "#";
	}
	std::cout << '\n';

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
std::vector<std::pair<int, int>> Map::RandomDestructibleWall(uint16_t m_width, uint16_t m_height,int NumberOfWalls)
{
	std::vector<std::pair<int, int>> coordonate;
	std::srand(std::time(nullptr));
	for (int i = 0; i < NumberOfWalls; ++i) {
		std::pair<int, int> coord;
		coord.first = std::rand() % m_width;  
		coord.second = std::rand() % m_height; 
		coordonate.push_back(coord);
	}
	return coordonate;
}

void Map::GenerateWalls(uint8_t level)
{
	//astea vor fi pentru verificare daca corespund indicii cu dimensiunile hartii

	uint16_t height = GetHeight();
	uint16_t width = GetWidth();
	std::vector<std::pair<int, int>> coordonate;
	switch (level)
	{
	case 1:
		coordonate = RandomDestructibleWall(width, height, 25);
		for (int i = 0; i < 25; i++)
			AddWall(coordonate[i].first, coordonate[i].second, Wall::Destructible::destructible);
		AddWall(0, 6, Wall::Destructible::indestructible);
		AddWall(1, 6, Wall::Destructible::indestructible);
		AddWall(1, 7, Wall::Destructible::indestructible);
		AddWall(3, 8, Wall::Destructible::indestructible);
		AddWall(4, 0, Wall::Destructible::indestructible);
		AddWall(4, 1, Wall::Destructible::indestructible);
		AddWall(4, 8, Wall::Destructible::indestructible);
		AddWall(5, 2, Wall::Destructible::indestructible);
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
		break;
	case 2:
		coordonate = RandomDestructibleWall(width, height, 30);
		for (int i = 0; i < 30; i++)
			AddWall(coordonate[i].first, coordonate[i].second, Wall::Destructible::destructible);
		AddWall(2, 1, Wall::Destructible::indestructible);
		AddWall(2, 2, Wall::Destructible::indestructible);
		AddWall(2,3, Wall::Destructible::indestructible);
		AddWall(0, 7, Wall::Destructible::indestructible);
		AddWall(0, 8, Wall::Destructible::indestructible);
		AddWall(0, 9, Wall::Destructible::indestructible);
		AddWall(1, 8, Wall::Destructible::indestructible);
		AddWall(2, 8, Wall::Destructible::indestructible);
		AddWall(3, 8, Wall::Destructible::indestructible);
		AddWall(4, 12, Wall::Destructible::indestructible);
		AddWall(1, 16, Wall::Destructible::indestructible);
		AddWall(2, 16, Wall::Destructible::indestructible);
		AddWall(6, 6, Wall::Destructible::indestructible);
		AddWall(6, 7, Wall::Destructible::indestructible);
		AddWall(6, 8, Wall::Destructible::indestructible);
		AddWall(6, 9, Wall::Destructible::indestructible);
		AddWall(7, 13, Wall::Destructible::indestructible);
		AddWall(8, 13, Wall::Destructible::indestructible);
		AddWall(9, 13, Wall::Destructible::indestructible);
		AddWall(10, 11, Wall::Destructible::indestructible);
		AddWall(10, 12, Wall::Destructible::indestructible);
		AddWall(9, 19, Wall::Destructible::indestructible);
		AddWall(7, 19, Wall::Destructible::indestructible);
		AddWall(8, 19, Wall::Destructible::indestructible);
		AddWall(8, 18, Wall::Destructible::indestructible);
		AddWall(9, 4, Wall::Destructible::indestructible);
		AddWall(10, 4, Wall::Destructible::indestructible);
		AddWall(11, 4, Wall::Destructible::indestructible);
		AddWall(13, 5, Wall::Destructible::indestructible);
		AddWall(11, 1, Wall::Destructible::indestructible);
		AddWall(11, 2, Wall::Destructible::indestructible);
		AddWall(11, 3, Wall::Destructible::indestructible);
		AddWall(11, 4, Wall::Destructible::indestructible);
		AddWall(11, 7, Wall::Destructible::indestructible);
		AddWall(12, 7, Wall::Destructible::indestructible);
		AddWall(13, 7, Wall::Destructible::indestructible);
		AddWall(14, 7, Wall::Destructible::indestructible);
		AddWall(11, 4, Wall::Destructible::indestructible);
		AddWall(14, 8, Wall::Destructible::indestructible);
		AddWall(14, 9, Wall::Destructible::indestructible);
		AddWall(15, 2, Wall::Destructible::indestructible);
		AddWall(18, 4, Wall::Destructible::indestructible);
		AddWall(19, 4, Wall::Destructible::indestructible);
		AddWall(17, 12, Wall::Destructible::indestructible);
		AddWall(17, 13, Wall::Destructible::indestructible);
		AddWall(17, 14, Wall::Destructible::indestructible);
		AddWall(16, 13, Wall::Destructible::indestructible);
		AddWall(18, 14, Wall::Destructible::indestructible);
		AddWall(15, 18, Wall::Destructible::indestructible);
		break;
	case 3:
		coordonate = RandomDestructibleWall(width, height, 35);
		for (int i = 0; i < 35; i++)
			AddWall(coordonate[i].first, coordonate[i].second, Wall::Destructible::destructible);
		AddWall(0, 2, Wall::Destructible::indestructible);
		AddWall(0, 3, Wall::Destructible::indestructible);
		AddWall(0, 4, Wall::Destructible::indestructible);
		AddWall(2, 9, Wall::Destructible::indestructible);
		AddWall(2, 10, Wall::Destructible::indestructible);
		AddWall(2, 19, Wall::Destructible::indestructible);
		AddWall(2, 20, Wall::Destructible::indestructible);
		AddWall(2, 21, Wall::Destructible::indestructible);
		AddWall(2, 22, Wall::Destructible::indestructible);
		AddWall(2, 23, Wall::Destructible::indestructible);
		AddWall(2, 24, Wall::Destructible::indestructible);
		AddWall(3, 9, Wall::Destructible::indestructible);
		AddWall(3, 10, Wall::Destructible::indestructible);
		AddWall(3, 24, Wall::Destructible::indestructible);
		AddWall(4, 11, Wall::Destructible::indestructible);
		AddWall(4, 12, Wall::Destructible::indestructible);
		AddWall(4, 24, Wall::Destructible::indestructible);
		AddWall(5, 24, Wall::Destructible::indestructible);
		AddWall(6, 24, Wall::Destructible::indestructible);
		AddWall(7, 24, Wall::Destructible::indestructible);
		AddWall(8, 3, Wall::Destructible::indestructible);
		AddWall(8, 4, Wall::Destructible::indestructible);
		AddWall(8, 24, Wall::Destructible::indestructible);
		AddWall(9, 4, Wall::Destructible::indestructible);
		AddWall(10, 4, Wall::Destructible::indestructible);
		AddWall(10, 11, Wall::Destructible::indestructible);
		AddWall(10, 12, Wall::Destructible::indestructible);
		AddWall(10, 13, Wall::Destructible::indestructible);
		AddWall(10, 14, Wall::Destructible::indestructible);
		AddWall(11, 4, Wall::Destructible::indestructible);
		AddWall(11, 7, Wall::Destructible::indestructible);

		AddWall(11, 10, Wall::Destructible::indestructible);
		AddWall(11, 12, Wall::Destructible::indestructible);
		AddWall(12, 4, Wall::Destructible::indestructible);
		AddWall(12, 5, Wall::Destructible::indestructible);
		AddWall(12, 6, Wall::Destructible::indestructible);
		AddWall(12, 12, Wall::Destructible::indestructible);
		AddWall(13, 4, Wall::Destructible::indestructible);
		AddWall(13, 5, Wall::Destructible::indestructible);
		AddWall(13, 6, Wall::Destructible::indestructible);
		AddWall(13, 12, Wall::Destructible::indestructible);

		AddWall(14, 12, Wall::Destructible::indestructible);
		AddWall(14, 19, Wall::Destructible::indestructible);
		AddWall(15, 1, Wall::Destructible::indestructible);
		AddWall(15, 19, Wall::Destructible::indestructible);
		AddWall(16, 1, Wall::Destructible::indestructible);
		AddWall(16, 19, Wall::Destructible::indestructible);
		AddWall(17, 1, Wall::Destructible::indestructible);
		AddWall(17, 18, Wall::Destructible::indestructible);
		AddWall(17, 19, Wall::Destructible::indestructible);
		AddWall(18, 1, Wall::Destructible::indestructible);
		AddWall(18, 19, Wall::Destructible::indestructible);
		AddWall(18, 20, Wall::Destructible::indestructible);
		AddWall(18, 21, Wall::Destructible::indestructible);
		AddWall(19, 1, Wall::Destructible::indestructible);
		AddWall(19, 13, Wall::Destructible::indestructible);
		AddWall(19, 21, Wall::Destructible::indestructible);
		AddWall(19, 22, Wall::Destructible::indestructible);
		AddWall(20, 8, Wall::Destructible::indestructible);

		AddWall(21, 3, Wall::Destructible::indestructible);
		AddWall(21, 12, Wall::Destructible::indestructible);
		AddWall(21, 13, Wall::Destructible::indestructible);
		AddWall(21, 14, Wall::Destructible::indestructible);
		AddWall(22, 8, Wall::Destructible::indestructible);
		AddWall(22, 14, Wall::Destructible::indestructible);
		AddWall(22, 15, Wall::Destructible::indestructible);
		AddWall(22, 16, Wall::Destructible::indestructible);
		AddWall(23, 8, Wall::Destructible::indestructible);
		AddWall(23, 16, Wall::Destructible::indestructible);
		AddWall(24, 8, Wall::Destructible::indestructible);
		AddWall(24, 16, Wall::Destructible::indestructible);
		break;
	default:
		break;
	}
	

}
