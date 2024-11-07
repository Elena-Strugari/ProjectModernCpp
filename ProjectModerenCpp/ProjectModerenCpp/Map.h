#pragma once
#include <cstdint>
#include <iostream>
#include <vector>


class Map
{
public:
	//CONSTRUCTOR
	Map();      // va trebui adaugare nivel 

	void print()const;





	/*uint16_t GetWidth() const;
	uint16_t GetHeight() const;
	Wall* GetWallAt(uint16_t i, uint16_t j) const;
	void SetBomb();
	void SetBonus();
	void SetBush();*/

private:

	uint16_t m_width;
	uint16_t m_height;
	std::vector<std::vector<int>> m_map;

	//std::vector<std::vector<Wall>> m_grid;


};

