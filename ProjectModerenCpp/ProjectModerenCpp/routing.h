#pragma once
#include <crow.h>
#include "ServerObject.h"



namespace http {
	class Routing : public ServerObject
	{
	public:
		void Run();
		//Routing() {
		//	// Inițializare mapă tanks cu un exemplu
		//	m_tanks["ela"] = GameObject(Tank::ColorTank::Red);
		//}

	private:
		crow::SimpleApp m_app;
	};

}



/*
*
client - level
ID = string = numele
int = level


tank
ID = client
Object = culoare , viata
*/

