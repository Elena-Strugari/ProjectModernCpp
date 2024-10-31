#pragma once
#include <cstdint>

struct Position
{
	uint16_t x, y;

};

class Wall
{
public:

	//CONSTRUCTOR
	Wall(uint16_t x, uint16_t y, bool destructible, bool exist, uint8_t hitCount /* Bomb* bomb, Heart* heart*/);

	bool isDistructible()const;
	Position getPosition()const;
	bool destroy()const;
	bool hit();
	//GETTERS



private:
	Position m_position;
	bool m_destructible; //1 = destructible, 0 = indestructible
};

