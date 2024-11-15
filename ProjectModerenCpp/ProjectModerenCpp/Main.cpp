#include <iostream>
#include "Map.h"
#include "UserManager.h"
#include<utility>
#include<vector>
#include"Position.h"
#include "MoveObject.h"
int main()
{
	Map matrix(2);
	matrix.GenerateWalls(2);
	matrix.print();
	Position p;
	std::vector<std::pair<uint16_t, uint16_t>>startPosition = p.PlayersStartPositions(matrix.GetWidth(), matrix.GetHeight());
	for (int i = 0; i < 4; i++)
		std::cout << "Playier " << i << " : " << startPosition[i].first << "," << startPosition[i].second << "\n";


	//afis 
	GameObject obj(Tank::ColorTank::Blue);
	std::cout << obj<<std::endl;
	MoveObject moveObj(std::move(obj));

	moveObj.ShootBullet();

	return 0;
}