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
		destructible,
		indestructible
	};
public:

	//CONSTRUCTOR
	Wall(uint16_t x, uint16_t y, Destructible destructible, bool exist, uint8_t hitCount /* Bomb* bomb, Heart* heart*/);

	Destructible IsDistructible()const;
	Position GetPosition()const;
	bool Destroy();
	bool Hit();
	//GETTERS

private:

	Position m_position;
	Destructible m_destructible:1;
	bool m_exist;
	uint8_t m_hitCount;
};

