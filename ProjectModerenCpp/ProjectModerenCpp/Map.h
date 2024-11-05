#pragma once
#include <cstdint>
#include <vector>
//includerea wall.h este paguboasa.
//#include "Wall.h"
//#include "Position.h"

class Wall;

struct Dimentions {
	uint16_t width;
	uint16_t height;
};
class Map
{
public:
	//CONSTRUCTOR
	Map();
	Map(uint16_t width, uint16_t height, std::vector <std::vector<Wall*>> grid);
	uint16_t GetWidth() const;
	uint16_t GetHeight() const;
	Wall* GetWallAt(uint16_t i, uint16_t j) const;

private:

	Dimentions m_dimentions;
	std::vector<std::vector<Wall*>> m_grid;//pointeri catre wall sau nullptr


};

