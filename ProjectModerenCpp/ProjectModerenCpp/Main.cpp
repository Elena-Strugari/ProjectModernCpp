#include <iostream>
#include "Map.h"
#include "Tank.h"
#include "UserManager.h"

int main()
{
	Map matrix;
	matrix.GenerateWalls();
	matrix.print();
	//Tank tank{ Tank::ColorTank::Red };
	

	return 0;
}