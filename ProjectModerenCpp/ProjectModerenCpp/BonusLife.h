#pragma once
#include <cstdint>
#include"Position.h"
#include"Player.h"
class BonusLife : public Player
{
public:
	void Collect(Position m_heartPosition);
	
private:
	Position m_bombPosition;
};
