#pragma once
#include<cstdint>

struct Position
{
	uint16_t x, y;

};
class Bomb
{
public:
	void Explode(Position m_bombPosition/*second parameter is the map size*/ );

private:
	Position m_bombPosition;

};