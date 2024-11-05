#pragma once
#include "Map.h"
#include "Position.h"

Map::Map(uint16_t width, uint16_t height, std::vector<std::vector<Wall*>> grid)
	: m_dimentions {width, height}
	, m_grid(std::move(grid))
{
	//EMPTY
}

uint16_t Map::GetWidth() const
{
	return 0;
}

uint16_t Map::GetHeight() const
{
	return 0;
}
