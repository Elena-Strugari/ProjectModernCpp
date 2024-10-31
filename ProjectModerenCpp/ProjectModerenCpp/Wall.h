#pragma once
#include <cstdint>

struct Position
{
	uint16_t x, y;

};

class Wall
{
public:

	


private:
	Position m_position;
	bool m_destructible; //1 = destructible, 0 = indestructible
};

