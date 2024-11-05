#pragma once
#include "Map.h"
#include "Position.h"
#include "Wall.h"
//class Wall;

Map::Map()
	: m_dimentions{ 0, 0 }, m_grid{} {
}

Map::Map(uint16_t width, uint16_t height, std::vector<std::vector<Wall*>> grid)
	: m_dimentions {width, height}
	, m_grid(std::move(grid))
{
	//EMPTY
}


uint16_t Map::GetWidth() const
{
	return m_dimentions.width;
}

uint16_t Map::GetHeight() const
{
	return m_dimentions.height;
}

Wall* Map::GetWallAt(uint16_t i, uint16_t j) const {
	if (i < m_dimentions.height && j < m_dimentions.width) {
		return m_grid[i][j];
	}
	return nullptr; // Returneaz? nullptr dac? indexul este în afara limitelor
}

