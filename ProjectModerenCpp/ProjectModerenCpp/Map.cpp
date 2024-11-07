#pragma once
#include "Map.h"
#include <cstdlib>  
#include <ctime>


Map::Map()
{
	uint8_t minVal=10, maxVal=20;   // pt nivel 1 
	// random val mat 
	std::srand(std::time(nullptr));
	m_width = minVal + std::rand() % (maxVal - minVal + 1);
	m_height = minVal + std::rand() % (maxVal - minVal + 1);	
	m_map.resize( m_width, std::vector<int>(m_height));

	for (int i = 0; i < m_width; ++i) {
		for (int j = 0; j < m_height; ++j) {
			m_map[i][j] = 0; 
		}
	}
}

void Map::print() const
{
	for (const auto& row : m_map) {
		for (int val : row) {
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
}
