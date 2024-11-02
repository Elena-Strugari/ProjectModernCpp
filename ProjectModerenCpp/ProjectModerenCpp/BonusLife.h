#pragma once
#include <cstdint>
struct Position
{
	int x, y;
};
class BonusLife
{
public:
	void Collect(Position m_heartPosition);

private:
	Position m_bombPosition;
};
