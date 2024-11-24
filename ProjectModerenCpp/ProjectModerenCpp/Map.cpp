#pragma once
#include "Map.h"
#include <cstdlib>  
#include <ctime>
#include<vector>
#include<set>
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
	m_level = level;
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
		    m_map[x][y] = 'O'; 
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
	std::set<std::pair<uint16_t, uint16_t>>cornes = { {0, 0}, {0, m_height - 1}, {m_width - 1,0},{m_width - 1,m_height - 1} };
	std::srand(std::time(nullptr));
	for (int i = 0; i < NumberOfWalls; ++i) {
		std::pair<uint16_t, uint16_t> coord;
		coord.first = std::rand() % m_width;  
		coord.second = std::rand() % m_height; 
		
		if (m_map[coord.first][coord.second] !='_' || cornes.count(coord) !=0) //mai tarziu inlocuim cu ' '
			i--;
		else
		   coordonate.push_back(coord);
	}
	return coordonate;
}

void Map::GenerateMapElements(Map& map)
{
	//astea vor fi pentru verificare daca corespund indicii cu dimensiunile hartii

	uint16_t height = GetHeight();
	uint16_t width = GetWidth();
	std::vector<std::pair<uint16_t, uint16_t>> destructibleWallsCoordonate, indestructibleWallsCoordonate;
	switch (m_level)
	{
	case 1: {
		std::vector<std::pair<int, int>> ImpliciteIndestructible = 
		{ {0, 6}, {1, 6}, {1, 7}, {3, 8}, {4, 0}, {4, 1}, {4, 8},{5, 2}, {5, 8}, {5, 9}, {5, 10}, {5, 14}, {6, 6}, {6, 14},{7, 5}, {7, 6}, {7, 7}, {10, 0}, 
		  {10, 1}, {10, 2}, {10, 3},{10, 11}, {10, 12}, {12, 5}, {12, 9}, {12, 10}, {12, 11},{12, 12}, {13, 5}, {13, 12}, {14, 5}, {12, 13}, {13, 14},{14, 13}, 
		  {9, 5}, {8, 6}, {7, 8}, {6, 9}, {5, 11}, {4, 12},{3, 13}, {2, 14}};
		for (const auto& pair : ImpliciteIndestructible) 
			AddWall(pair.first, pair.second, Wall::Destructible::indestructible);  //Indestructibile implicite

		indestructibleWallsCoordonate = RandomWall(width, height, 15);
		for (int i = 0; i < 15; i++)
			AddWall(indestructibleWallsCoordonate[i].first, indestructibleWallsCoordonate[i].second, Wall::Destructible::indestructible);  //indestructibile random
		
		
		std::vector<std::pair<int, int>> ImpliciteDestructible = { {2,2},{2,6},{2,9},{6,9},{8,8},{11,4},{11,9},{13,7},{14,10} };
		for (const auto& pair : ImpliciteDestructible)
			AddWall(pair.first, pair.second, Wall::Destructible::destructible);  //destructibile implicite
		
		destructibleWallsCoordonate = RandomWall(width, height, 40); 
		for (int i = 0; i < 40; i++)
			AddWall(destructibleWallsCoordonate[i].first, destructibleWallsCoordonate[i].second, Wall::Destructible::destructible);  // destructibile random

		std::srand(std::time(0));
		int bombWallIndex =std::rand() % (40);
		int bonuslifeWallIndex1 = std::rand() % (40);
		//std::cout << "Indice pentru bomba "<< bombWallIndex;
		AddBomb(destructibleWallsCoordonate[bombWallIndex].first, destructibleWallsCoordonate[bombWallIndex].second);
		AddBonusLife(destructibleWallsCoordonate[bonuslifeWallIndex1].first, destructibleWallsCoordonate[bonuslifeWallIndex1].second);
		break;
	}


	case 2:{
		std::vector<std::pair<int, int>> ImpliciteIndestructible =
		{ {2, 1}, {2, 2}, {2, 3}, {0, 7}, {0, 8}, {0, 9}, {1, 8}, {2, 8},{3, 8}, {4, 12}, {1, 16}, {2, 16}, {6, 6}, {6, 7}, {6, 8}, {6, 9},
		  {7, 13}, {8, 13}, {9, 13}, {10, 11}, {10, 12}, {9, 19}, {7, 19}, {8, 19},{8, 18}, {9, 4}, {10, 4}, {11, 4}, {13, 5}, {11, 1}, {11, 2},
		  {11, 3},{11, 4}, {11, 7}, {12, 7}, {13, 7}, {14, 7}, {11, 4}, {14, 8}, {14, 9},{15, 2}, {18, 4}, {19, 4}, {17, 12}, {17, 13}, {17, 14}, 
		  {16, 13}, {18, 14},{15, 18}
		};
		for (const auto& pair : ImpliciteIndestructible)
			AddWall(pair.first, pair.second, Wall::Destructible::indestructible);  //Indestructibile implicite

		indestructibleWallsCoordonate = RandomWall(width, height, 15);
		for (int i = 0; i < 15; i++)
			AddWall(indestructibleWallsCoordonate[i].first, indestructibleWallsCoordonate[i].second, Wall::Destructible::indestructible); //indestructibile random

		std::vector<std::pair<int, int>> ImpliciteDestructible = { /*DE ADAUGAT ZIDURI DESTRUCTIBILE IMPLICITE*/ };
		for (const auto& pair : ImpliciteDestructible)
			AddWall(pair.first, pair.second, Wall::Destructible::destructible);  //destructibile implicite

		destructibleWallsCoordonate = RandomWall(width, height, 50);
		for (int i = 0; i < 50; i++)
			AddWall(destructibleWallsCoordonate[i].first, destructibleWallsCoordonate[i].second, Wall::Destructible::destructible);   //destructibile random

		std::srand(std::time(nullptr)); 
		int bombWallIndex = std::rand() % (50); 
		int bonuslifeWallIndex1 = std::rand() % (50); 
		int bonuslifeWallIndex2 = std::rand() % (50); 
		AddBomb(destructibleWallsCoordonate[bombWallIndex].first, destructibleWallsCoordonate[bombWallIndex].second); 
		AddBonusLife(destructibleWallsCoordonate[bonuslifeWallIndex1].first, destructibleWallsCoordonate[bonuslifeWallIndex1].second); 
		AddBonusLife(destructibleWallsCoordonate[bonuslifeWallIndex2].first, destructibleWallsCoordonate[bonuslifeWallIndex2].second); 
		break;
	}

	case 3: {
		std::vector<std::pair<int, int>> ImpliciteIndestructible = 
		 { {0, 2}, {0, 3}, {0, 4}, {2, 9}, {2, 10}, {2, 19}, {2, 20}, {2, 21},{2, 22}, {2, 23}, {2, 24}, {3, 9}, {3, 10}, {3, 24}, {4, 11}, {4, 12},
		   {4, 24}, {5, 24}, {6, 24}, {7, 24}, {8, 3}, {8, 4}, {8, 24}, {9, 4},{10, 4}, {10, 11}, {10, 12}, {10, 13}, {10, 14}, {11, 7}, {11, 10},
		   {11, 12}, {12, 5}, {12, 6}, {12, 12}, {13, 4}, {13, 5}, {13, 6},{13, 12}, {14, 12}, {14, 19}, {15, 1}, {15, 19}, {16, 1}, {16, 19},
	 	   {17, 1}, {17, 18}, {17, 19}, {18, 1}, {18, 19}, {18, 20}, {18, 21},{19, 1}, {19, 13}, {19, 21}, {19, 22}, {20, 8}, {21, 3}, {21, 12},
		   {21, 13}, {21, 14}, {22, 8}, {22, 14}, {22, 15}, {22, 16}, {23, 8},{23, 16}, {24, 8}, {24, 16}
		 };
		for (const auto& pair : ImpliciteIndestructible) 
			AddWall(pair.first, pair.second, Wall::Destructible::indestructible);  //indestructibile implictite

		indestructibleWallsCoordonate = RandomWall(width, height, 15);
		for (int i = 0; i < 15; i++)
			AddWall(indestructibleWallsCoordonate[i].first, indestructibleWallsCoordonate[i].second, Wall::Destructible::indestructible); //indestructibile random

		std::vector<std::pair<int, int>> ImpliciteDestructible = 
		{ {1, 9}, {2, 8}, {3, 7}, {3, 8}, {3, 20}, {3, 21}, {3, 22}, {3, 23},{4, 6}, {4, 7}, {5, 6}, {5, 7}, {7, 17}, {7, 18}, {8, 17}, {8, 18},
		  {9, 17}, {9, 18}, {11, 4}, {12, 4}, {15, 12}, {16, 12}, {17, 12},{18, 12}, {18, 13}, {22, 19}, {23, 19}, {24, 19} };
		for (const auto& pair : ImpliciteDestructible)
			AddWall(pair.first, pair.second, Wall::Destructible::destructible);  //destructibile implicite
		

		destructibleWallsCoordonate = RandomWall(width, height, 70); 
		for (int i = 0; i < 70; i++)
			AddWall(destructibleWallsCoordonate[i].first, destructibleWallsCoordonate[i].second, Wall::Destructible::destructible); //destructibile random

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
		if (m_map[x][y] != 'H' && m_map[x][y]!='O')
			m_map[x][y] = 'H'; //H de la heart
}
