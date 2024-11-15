#include <iostream>
#include "Map.h"
#include "Tank.h"
#include "UserManager.h"
#include<utility>
#include<vector>
#include"Position.h"
int main()
{
	Map matrix;
	matrix.GenerateWalls();
	matrix.print();
	Position p;
	std::vector<std::pair<uint16_t, uint16_t>>startPosition = p.PlayersStartPositions(matrix.GetWidth(), matrix.GetHeight());
	for (int i = 0; i < 4; i++)
		std::cout << "Playier " << i << " : " << startPosition[i].first << "," << startPosition[i].second << "\n";
	//Tank tank{ Tank::ColorTank::Green };
	
	//std::cout << tank;

	return 0;
}