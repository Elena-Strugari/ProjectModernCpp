#pragma once
#include <cstdint>
#include <vector>
#include "Wall.h"
//#include "Position.h"


struct Dimentions {
	uint16_t width;
	uint16_t height;
};
class Map
{
public:
	//CONSTRUCTOR
	Map(uint16_t width, uint16_t height, std::vector <std::vector<Wall*>> grid);

private:

	Dimentions m_dimentions;
	std::vector<std::vector<Wall*>> m_grid;//pointeri catre wall sau nullptr


};

