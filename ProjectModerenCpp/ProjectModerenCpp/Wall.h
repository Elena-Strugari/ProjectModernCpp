#pragma once
#include <cstdint>
#include "Bomb.h"
#include "BonusLife.h"
#include "Position.h"

//struct Position
//{
//	uint16_t x, y;
//
//};

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

