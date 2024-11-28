#include <iostream>
#include "Map.h"
#include<utility>
#include<vector>
#include "Tank.h"

#include "routing.h"

using namespace http;
int main()
{
	/*Map map(3);
	map.GenerateWalls(3);
	map.DisplayMap();*/

	//Tank t(Tank::ColorTank::Blue);
	//std::cout<<t.GetColor();
	Routing r;
	r.Run();


	return 0;
}
