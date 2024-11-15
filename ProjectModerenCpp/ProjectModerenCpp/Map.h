#pragma once
#include <cstdint>
#include <iostream>
#include <vector>
#include "Wall.h"

class Map
{
public:
	//CONSTRUCTOR
	Map(uint8_t level);      // va trebui adaugare nivel 

	void print()const;





	/*uint16_t GetWidth() const;
	uint16_t GetHeight() const;
	Wall* GetWallAt(uint16_t i, uint16_t j) const;
	void SetBomb();
	void SetBonus();
	void SetBush();*/
	void AddWall(uint16_t x, uint16_t y, Wall::Destructible destructible);
	void GenerateWalls(uint8_t level);
	uint16_t GetWidth()const;
	uint16_t GetHeight()const;
private:

	uint16_t m_width;
	uint16_t m_height;
	std::vector<std::vector<char>> m_map;

	//std::vector<std::vector<Wall>> m_grid;


};

