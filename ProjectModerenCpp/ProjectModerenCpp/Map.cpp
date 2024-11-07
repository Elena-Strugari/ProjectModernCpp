#pragma once
#include "Map.h"
#include "Position.h"
//#include "Wall.h"
//class Wall;

Map::Map()
	: m_dimensions{ 0, 0 }
	, m_grid{}
{
	//EMPTY
}

Map::Map(uint16_t width, uint16_t height)
	:m_dimensions{width, height}
{
	//EMPTY
}

//Map::Map(uint16_t width, uint16_t height, std::vector<std::vector<Wall*>> grid)
//	:m_dimensions{width, height}
//	,m_grid{grid}
//{
//	//EMPTY
//}

Map::Map(uint16_t width, uint16_t height, std::vector<std::vector<Wall*>> grid)
	: m_dimensions {width, height}
	, m_grid(std::move(grid))
{
	//EMPTY
}


uint16_t Map::GetWidth() const
{
	return m_dimensions.width;
}

uint16_t Map::GetHeight() const
{
	return m_dimensions.height;
}


Wall* Map::GetWallAt(uint16_t i, uint16_t j) const {
	if (i < m_dimensions.height && j < m_dimensions.width) {
		return m_grid[i][j];
	}
	return nullptr; // Returneaz? nullptr dac? indexul este în afara limitelor
}

//void Map::AddWall(uint16_t x, uint16_t y, Wall::Destructible destructible) {
//	if (x < m_dimensions.height && y < m_dimensions.width) {
//		m_grid[x][y] = new Wall(x, y, destructible, true, 0); // Alocare dinamic?
//	}
//}
void Map::AddWall(uint16_t x, uint16_t y, Wall::Destructible destructible) {
	if (x < m_dimensions.height && y < m_dimensions.width) {
		delete m_grid[x][y];
		m_grid[x][y] = new Wall(x, y, destructible, true, 0);
	}
}