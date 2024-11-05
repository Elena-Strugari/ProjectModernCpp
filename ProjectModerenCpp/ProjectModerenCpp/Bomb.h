#pragma once
#include<cstdint>
#include"Position.h"
#include"Map.h"
class Bomb
{
public:
	void Explode(Position m_bombPosition,Map map);

private:
	Position m_bombPosition;

};