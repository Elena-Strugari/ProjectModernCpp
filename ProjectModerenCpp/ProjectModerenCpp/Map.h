#pragma once
#include <cstdint>
#include <iostream>
#include <vector>
#include "Wall.h"

class Map
{
public:
	struct Cell {
		Wall::TypeWall typeWall;
		uint16_t space;
		uint16_t border;
		//bomba 

	};
public:

	Map();
	Map(uint8_t level);

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




private:
	uint16_t m_width;
	uint16_t m_height;
	std::vector<Wall> m_wall;
	std::vector<std::vector<Cell>> m_map;

	Cell m_cellType;

	std::pair<uint16_t, uint16_t> getLevelBounds(uint8_t level) const;
	std::vector<std::pair<uint16_t, uint16_t>>RandomWall(uint16_t x, uint16_t y, int numberOfWalls);



	////CONSTRUCTOR
	//Map(); //default - sters

	//void Print()const;
	//void PrintWithBorder()const;

	//Wall* GetWallAt(uint16_t i, uint16_t j) const;
	//void SetBomb();
	//void SetBonus();
	//void SetBush();*/
	//void AddWall(uint16_t x, uint16_t y, Wall::TypeWall destructible);
	//void AddBomb(uint16_t x, uint16_t y);
	//void GenerateWalls(uint8_t level);


	//std::vector<Wall::TypeWall>GetWalls() const;
	//std::vector<std::vector<Wall::TypeWall>> GetMapWithBorder()const;

//private:
//
//	uint16_t m_width;
//	uint16_t m_height;
//	std::vector<std::vector<char>> m_map;
//	std::vector<std::pair<uint16_t, uint16_t>>RandomWall(uint16_t x, uint16_t y, int NumberOfWalls);
//	std::vector<Wall::TypeWall> m_wall; // lista de ziduri 
//	Cell m_valueCell;

};
