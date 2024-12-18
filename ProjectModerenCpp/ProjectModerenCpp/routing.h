#pragma once
#include <crow.h>
#include "ServerObject.h"



namespace http {

	class Routing : public ServerObject
	{
	public:
		void Run();

	private:
		crow::SimpleApp m_app;
		static std::unordered_map<std::string, std::string> m_users;

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

