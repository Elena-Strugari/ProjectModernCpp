#pragma once
#include <crow.h>


namespace http {

	class Routing 
	{
	public:
		void Run();

	private:
		crow::SimpleApp m_app;
		//std::unordered_map<std::string, Player> m_players;



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

