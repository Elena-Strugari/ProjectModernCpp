#include "Map.h"

Map::Map(uint16_t width, uint16_t height, std::vector<std::vector<Wall*>> grid)
	: m_dimentions {width, height}
	, m_grid(std::move(grid))
{
	//EMPTY
}
