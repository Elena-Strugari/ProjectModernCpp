//server 
#include <iostream>
#include "Map.h"
#include "UserManager.h"
#include<utility>
#include<vector>
#include"Position.h"
#include "MoveObject.h"
int main()
{
<<<<<<< Updated upstream
	Map matrix(1);
	matrix.GenerateMapElements(matrix);
	//matrix.print();
	//matrix.PrintWithBorder();
	Position p;
	std::vector<std::pair<uint16_t, uint16_t>>startPosition = p.PlayersStartPositions(matrix.GetWidth(), matrix.GetHeight());
	for (int i = 0; i < 4; i++)
		std::cout << "Playier " << i << " : " << startPosition[i].first << "," << startPosition[i].second << "\n";
=======
	Map matrix(2);
	matrix.GenerateWalls(2);
	//matrix.print();
	matrix.PrintWithBorder();
	//Position p;
	//std::vector<std::pair<uint16_t, uint16_t>>startPosition = p.PlayersStartPositions(matrix.GetWidth(), matrix.GetHeight());
	//for (int i = 0; i < 4; i++)
	//	std::cout << "Playier " << i << " : " << startPosition[i].first << "," << startPosition[i].second << "\n";
>>>>>>> Stashed changes


	////afis 
	//GameObject obj(Tank::ColorTank::Blue);
	//MoveObject tank(std::move(obj), &matrix, startPosition[0].first, startPosition[0].second);
	////tank.ShootBullet();
 //   tank.HandleInput();

	return 0;
}