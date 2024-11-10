#include <iostream>
#include "Map.h"
#include "Tank.h"
#include "UserManager.h"

int main()
{
	Map matrix;
	matrix.print();
	Tank tank{ Tank::ColorTank::Red };
	//UserManager userManager;
	//userManager.PromptLoginOrRegister();
	

	return 0;
}