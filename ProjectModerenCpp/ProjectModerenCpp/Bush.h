#pragma once
#include"Position.h"
#include"Map.h"
#include"Tank.h"
class Bush
{
public:
	void GoThrough(Position m_bushPsition,Tank player_tank); //depunde cum va fi legat tanc de player

private:
	Position m_bushPosition;

};