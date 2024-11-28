////de discutat, cred server
//#pragma once
//#include <cstdint>
//#include <iostream>
//#include <vector>
//#include "Wall.h"
//
//class Map
//{
//public:
//	//CONSTRUCTOR
//	Map(uint8_t level); 
//	void Print()const;     
//	void PrintWithBorder()const;
//	bool IsValidPosition(uint16_t x, uint16_t y) const;
//	void SetCell(uint16_t x, uint16_t y, char value);
//	char GetCell(uint16_t x, uint16_t y) const;
//	void AddWall(uint16_t x, uint16_t y, Wall::Destructible destructible);
//	void AddBomb(uint16_t x, uint16_t y);
//	void GenerateMapElements(Map& map);
//	void AddBonusLife(uint16_t x, uint16_t y);
//	uint16_t GetWidth()const;
//	uint16_t GetHeight()const;
//private:
//
//	uint16_t m_width;
//	uint16_t m_height;
//	uint16_t m_level;
//	std::vector<std::vector<char>> m_map;
//	std::vector<std::pair<uint16_t, uint16_t>>RandomWall(uint16_t x, uint16_t y,int NumberOfWalls);
//	//std::vector<std::vector<Wall>> m_grid;
//};
//
