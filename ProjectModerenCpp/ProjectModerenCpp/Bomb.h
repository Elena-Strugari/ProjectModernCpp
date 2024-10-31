#pragma once
#include<cstdint>

struct Position
{
	uint16_t x, y;

};
class Bomb
{
public:
	void Explode();

private:
	Position m_bombPosition;

};