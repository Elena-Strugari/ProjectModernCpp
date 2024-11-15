#pragma once
#include <cstdint>


class Wall
{
public:
	enum class Destructible : char
	{
		destructible='@',
		indestructible='#'
	};
public:

	//CONSTRUCTOR
	Wall(Destructible destructible);

	Destructible IsDestructible()const;

private:

	Wall:: Destructible m_destructible;
	
};

