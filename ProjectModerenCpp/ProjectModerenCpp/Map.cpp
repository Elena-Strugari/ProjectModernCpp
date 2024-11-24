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
	std::srand(std::time(0));
	m_width = minVal + std::rand() % (maxVal - minVal + 1);
	m_height = minVal + std::rand() % (maxVal - minVal + 1);	
	m_map.resize( m_width, std::vector<char>(m_height));

	for (int i = 0; i < m_width; ++i) {
		for (int j = 0; j < m_height; ++j) {
			m_map[i][j] = '_';
		}
	}
}

void Map::Print() const
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
void Map::AddBomb(uint16_t x, uint16_t y)
{
	if (x >= 0 && x < m_width && y >= 0 && y < m_height)
		if(m_map[x][y] != 'O')
		    m_map[x][y] = 'O'; //💣
}
uint16_t Map::GetWidth() const
{
	return m_width;
}
uint16_t Map::GetHeight() const
{
	return m_height;
}
bool Map::IsValidPosition(uint16_t x, uint16_t y) const {
	return x >= 0 && x < m_width && y >= 0 && y < m_height;
}

void Map::SetCell(uint16_t x, uint16_t y, char value) {
	if (IsValidPosition(x, y)) {
		m_map[x][y] = value;
	}
}
char Map::GetCell(uint16_t x, uint16_t y) const {
	if (IsValidPosition(x, y)) {
		return m_map[x][y];
	}
	return '#'; // Returnează un caracter special pentru poziții invalide
}

std::vector<std::pair<uint16_t, uint16_t>> Map::RandomWall(uint16_t m_width, uint16_t m_height,int NumberOfWalls)
{
	std::vector<std::pair<uint16_t, uint16_t>> coordonate;
	std::srand(std::time(nullptr));
	for (int i = 0; i < NumberOfWalls; ++i) {
		std::pair<uint16_t, uint16_t> coord;
		coord.first = std::rand() % m_width;  
		coord.second = std::rand() % m_height; 
		if (m_map[coord.first][coord.second] !='_') //mai tarziu inlocuim cu ' '
			i--;
		else
		   coordonate.push_back(coord);
	}
	return coordonate;
}

void Map::GenerateWalls(uint8_t level)
{
	//astea vor fi pentru verificare daca corespund indicii cu dimensiunile hartii

	uint16_t height = GetHeight();
	uint16_t width = GetWidth();
	std::vector<std::pair<uint16_t, uint16_t>> destructibleWallsCoordonate, indestructibleWallsCoordonate;
	switch (level)
	{
	case 1: {

		/* Putem face asa cred
		
		std::vector<std::pair<int, int>> ImpliciteIndestructible = {
		{0, 6}, {1, 6}, {1, 7}, {3, 8}, {4, 0}, {4, 1}, {4, 8},
		{5, 2}, {5, 8}, {5, 9}, {5, 10}, {5, 14}, {6, 6}, {6, 14},
		{7, 5}, {7, 6}, {7, 7}, {10, 0}, {10, 1}, {10, 2}, {10, 3},
		{10, 11}, {10, 12}, {12, 5}, {12, 9}, {12, 10}, {12, 11},
		{12, 12}, {13, 5}, {13, 12}, {14, 5}, {12, 13}, {13, 14},
		{14, 13}, {9, 5}, {8, 6}, {7, 8}, {6, 9}, {5, 11}, {4, 12},
		{3, 13}, {2, 14}};

		for (const auto& pair : ImpliciteIndestructible) 
			AddWall(pair.first, pair.second, Wall::Destructible::indestructible);

		*/
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
		// Zona inferioară stânga
		AddWall(12, 13, Wall::Destructible::indestructible);
		AddWall(13, 14, Wall::Destructible::indestructible);
		AddWall(14, 13, Wall::Destructible::indestructible);
		// Zona centrală inferioară
		AddWall(9, 5, Wall::Destructible::indestructible);
		AddWall(8, 6, Wall::Destructible::indestructible);
		AddWall(7, 8, Wall::Destructible::indestructible);
		AddWall(6, 9, Wall::Destructible::indestructible);
		AddWall(5, 11, Wall::Destructible::indestructible);
		AddWall(4, 12, Wall::Destructible::indestructible);
		AddWall(3, 13, Wall::Destructible::indestructible);
		AddWall(2, 14, Wall::Destructible::indestructible);

		indestructibleWallsCoordonate = RandomWall(width, height, 15);
		for (int i = 0; i < 15; i++)
			AddWall(indestructibleWallsCoordonate[i].first, indestructibleWallsCoordonate[i].second, Wall::Destructible::indestructible);
		
		// Destructible walls
		AddWall(2, 2, Wall::Destructible::destructible);
		AddWall(2, 6, Wall::Destructible::destructible);
		AddWall(2, 9, Wall::Destructible::destructible);
		AddWall(6, 9, Wall::Destructible::destructible);
		AddWall(8, 8, Wall::Destructible::destructible);
		AddWall(11, 4, Wall::Destructible::destructible);
		AddWall(11, 9, Wall::Destructible::destructible);
		AddWall(13, 7, Wall::Destructible::destructible);
		AddWall(14, 10, Wall::Destructible::destructible);

		//Zidurile random se adauga dupa inserarea zidurilor fixe.
		destructibleWallsCoordonate = RandomWall(width, height, 40);  //DE VERIFICAT NR DE ZIDURI IMPLICTIE SI RANDOM SA NU INCARTE PREA MULT HARTA
		for (int i = 0; i < 40; i++)
			AddWall(destructibleWallsCoordonate[i].first, destructibleWallsCoordonate[i].second, Wall::Destructible::destructible);

		std::srand(std::time(0));
		int bombWallIndex =std::rand() % (40);
		int bonuslifeWallIndex1 = std::rand() % (40);
		int bonuslifeWallIndex2 = std::rand() % (40);
		int bonuslifeWallIndex3 = std::rand() % (40);
		//std::cout << "Indice pentru bomba "<< bombWallIndex;
		AddBomb(destructibleWallsCoordonate[bombWallIndex].first, destructibleWallsCoordonate[bombWallIndex].second);
		AddBonusLife(destructibleWallsCoordonate[bonuslifeWallIndex1].first, destructibleWallsCoordonate[bonuslifeWallIndex1].second);
		AddBonusLife(destructibleWallsCoordonate[bonuslifeWallIndex2].first, destructibleWallsCoordonate[bonuslifeWallIndex2].second);
		AddBonusLife(destructibleWallsCoordonate[bonuslifeWallIndex3].first, destructibleWallsCoordonate[bonuslifeWallIndex3].second);
		break;


	}
	case 2:{
		AddWall(2, 1, Wall::Destructible::indestructible);
		AddWall(2, 2, Wall::Destructible::indestructible);
		AddWall(2, 3, Wall::Destructible::indestructible);
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

		indestructibleWallsCoordonate = RandomWall(width, height, 15);
		for (int i = 0; i < 15; i++)
			AddWall(indestructibleWallsCoordonate[i].first, indestructibleWallsCoordonate[i].second, Wall::Destructible::indestructible);

		//DE ADAUGAT ZIDURI DESTRUCTIBILE IMPLICITE
		destructibleWallsCoordonate = RandomWall(width, height, 50); //DE VERIFICAT NR DE ZIDURI IMPLICTIE SI RANDOM SA NU INCARTE PREA MULT HARTA
		for (int i = 0; i < 50; i++)
			AddWall(destructibleWallsCoordonate[i].first, destructibleWallsCoordonate[i].second, Wall::Destructible::destructible);

		std::srand(std::time(nullptr));
		int bombWallIndex = std::rand() % (50);
		int bonuslifeWallIndex1 = std::rand() % (50);
		int bonuslifeWallIndex2 = std::rand() % (50);
		int bonuslifeWallIndex3 = std::rand() % (50);
		AddBomb(destructibleWallsCoordonate[bombWallIndex].first, destructibleWallsCoordonate[bombWallIndex].second);
		AddBonusLife(destructibleWallsCoordonate[bonuslifeWallIndex1].first, destructibleWallsCoordonate[bonuslifeWallIndex1].second);
		AddBonusLife(destructibleWallsCoordonate[bonuslifeWallIndex2].first, destructibleWallsCoordonate[bonuslifeWallIndex2].second);
		AddBonusLife(destructibleWallsCoordonate[bonuslifeWallIndex3].first, destructibleWallsCoordonate[bonuslifeWallIndex3].second);
		break;
	}

	case 3: {

	
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
		AddWall(11, 7, Wall::Destructible::indestructible);
		AddWall(11, 10, Wall::Destructible::indestructible);
		AddWall(11, 12, Wall::Destructible::indestructible);
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

		indestructibleWallsCoordonate = RandomWall(width, height, 15);
		for (int i = 0; i < 15; i++)
			AddWall(indestructibleWallsCoordonate[i].first, indestructibleWallsCoordonate[i].second, Wall::Destructible::indestructible);


		AddWall(1, 9, Wall::Destructible::destructible);
		AddWall(2, 8, Wall::Destructible::destructible);
		AddWall(3, 7, Wall::Destructible::destructible);
		AddWall(3, 8, Wall::Destructible::destructible);
		AddWall(3, 20, Wall::Destructible::destructible);
		AddWall(3, 21, Wall::Destructible::destructible);
		AddWall(3, 22, Wall::Destructible::destructible);
		AddWall(3, 23, Wall::Destructible::destructible);
		AddWall(4, 6, Wall::Destructible::destructible);
		AddWall(4, 7, Wall::Destructible::destructible);
		AddWall(5, 6, Wall::Destructible::destructible);
		AddWall(5, 7, Wall::Destructible::destructible);
		AddWall(7, 17, Wall::Destructible::destructible);
		AddWall(7, 18, Wall::Destructible::destructible);
		AddWall(8, 17, Wall::Destructible::destructible);
		AddWall(8, 18, Wall::Destructible::destructible);
		AddWall(9, 17, Wall::Destructible::destructible);
		AddWall(9, 18, Wall::Destructible::destructible);
		AddWall(11, 4, Wall::Destructible::destructible);
		AddWall(12, 4, Wall::Destructible::destructible);
		AddWall(15, 12, Wall::Destructible::destructible);
		AddWall(16, 12, Wall::Destructible::destructible);
		AddWall(17, 12, Wall::Destructible::destructible);
		AddWall(18, 12, Wall::Destructible::destructible);
		AddWall(18, 13, Wall::Destructible::destructible);
		AddWall(22, 19, Wall::Destructible::destructible);
		AddWall(23, 19, Wall::Destructible::destructible);
		AddWall(24, 19, Wall::Destructible::destructible);

		destructibleWallsCoordonate = RandomWall(width, height, 70); //DE VERIFICAT NR DE ZIDURI IMPLICTIE SI RANDOM SA NU INCARTE PREA MULT HARTA
		for (int i = 0; i < 70; i++)
			AddWall(destructibleWallsCoordonate[i].first, destructibleWallsCoordonate[i].second, Wall::Destructible::destructible);

		std::srand(std::time(nullptr));
		int bombWallIndex1 = std::rand() % (70);
		int bombWallIndex2 = std::rand() % (70);
		int bonuslifeWallIndex1 = std::rand() % (70);
		int bonuslifeWallIndex2 = std::rand() % (70);
		int bonuslifeWallIndex3 = std::rand() % (70);
		AddBomb(destructibleWallsCoordonate[bombWallIndex1].first, destructibleWallsCoordonate[bombWallIndex1].second);
		AddBomb(destructibleWallsCoordonate[bombWallIndex2].first, destructibleWallsCoordonate[bombWallIndex2].second); 
		AddBonusLife(destructibleWallsCoordonate[bonuslifeWallIndex1].first, destructibleWallsCoordonate[bonuslifeWallIndex1].second);
		AddBonusLife(destructibleWallsCoordonate[bonuslifeWallIndex2].first, destructibleWallsCoordonate[bonuslifeWallIndex2].second);
		AddBonusLife(destructibleWallsCoordonate[bonuslifeWallIndex3].first, destructibleWallsCoordonate[bonuslifeWallIndex3].second);
		break;
	}
	default:
		break;
	}


}

void Map::AddBonusLife(uint16_t x, uint16_t y)
{
	if (x >= 0 && x < m_width && y >= 0 && y < m_height)
		if (m_map[x][y] != 'H')
			m_map[x][y] = 'H'; //H de la heart
}
