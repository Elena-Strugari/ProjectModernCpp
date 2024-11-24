//de discutat, cred server
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

	void Print()const;     
	void PrintWithBorder()const;
	/*uint16_t GetWidth() const;
	uint16_t GetHeight() const;
	Wall* GetWallAt(uint16_t i, uint16_t j) const;
	void SetBomb();
	void SetBonus();
	void SetBush();*/
	bool IsValidPosition(uint16_t x, uint16_t y) const;
	void SetCell(uint16_t x, uint16_t y, char value);
	char GetCell(uint16_t x, uint16_t y) const;
	void AddWall(uint16_t x, uint16_t y, Wall::Destructible destructible);
	void AddBomb(uint16_t x, uint16_t y);
	void GenerateWalls(uint8_t level);
	void AddBonusLife(uint16_t x, uint16_t y);
	uint16_t GetWidth()const;
	uint16_t GetHeight()const;
private:

	uint16_t m_width;
	uint16_t m_height;
	std::vector<std::vector<char>> m_map;
	std::vector<std::pair<uint16_t, uint16_t>>RandomWall(uint16_t x, uint16_t y,int NumberOfWalls);
	//std::vector<std::vector<Wall>> m_grid;


};

