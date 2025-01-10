#pragma once
#include <cstdint>
#include <iostream>
#include <vector>
#include "Wall.h"
#include "Bomb.h"
#include "BonusLife.h"

class Map
{
public:
	struct Cell {
		Wall::TypeWall typeWall;
		uint16_t space;
		uint16_t border;
	};
public:

	explicit Map(uint8_t level);

	//Get
	uint16_t GetWidth() const;
	uint16_t GetHeight() const;
	Cell GetType()const;
	std::vector<std::vector<Map::Cell>>GetMap()const;
	Map::Cell GetCell(uint16_t x, uint16_t y) const;

	//set
	void SetCell(uint16_t x, uint16_t y, Cell value);

	//validation
	bool IsValidPosition(uint16_t x, uint16_t y) const;

	//display 
	void DisplayMap()const;

	//Add
	void GenerateWalls(uint8_t level);
	void AddWall(uint16_t x, uint16_t y, Wall::TypeWall destructible);
	/*void AddBomb(Bomb bomb);
	void AddBonusLife(BonusLife bonusLife);*/



private:
	uint16_t m_width;
	uint16_t m_height;
	//std::vector<Wall> m_wall;
	std::vector<std::vector<Cell>> m_map;

	Cell m_cellType;

	std::tuple<uint16_t, uint16_t,uint16_t, uint16_t> getLevelBounds(uint8_t level) const;
	std::vector<std::pair<uint16_t, uint16_t>>RandomWall(uint16_t x, uint16_t y, int numberOfWalls);
	void initializeGameElements(uint8_t numBombs, uint8_t numBonusLives);
	std::pair<uint16_t, uint16_t> findValidPositionElements();

};