#pragma once
#include <cstdint>


class Wall
{
public:
	enum class Destructible : uint8_t
	{
		destructible=0,
		indestructible=1
	};
public:

	//CONSTRUCTOR
	Wall(Destructible destructible);

	Destructible IsDestructible()const;

private:

	Wall:: Destructible m_destructible : 1;
	
};

