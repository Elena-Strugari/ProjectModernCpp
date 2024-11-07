#pragma once
#include "Wall.h"
#include "Bomb.h"
#include <cstdint>
#include "Position.h"

//Wall(uint16_t x, uint16_t y, Destructible destructible, bool exist, uint8_t hitCount /* Bomb* bomb, Heart* heart*/)
//	: m_position{ x,y }
//	, m_destructible{ destructible }
//	, m_exist{ true }
//	, m_hitCount{ hitCount }
//{
//	//empty
//}


Wall::Wall(uint16_t x, uint16_t y, Destructible destructible, bool exist, uint8_t hitCount)
	:m_position{x,y}
	,m_destructible{destructible}
	,m_exist{true}
	,m_hitCount{hitCount}
{
	//EMPTY
}

Wall::Destructible Wall::IsDestructible() const
{
	return m_destructible;
}

Position Wall::GetPosition() const
{
	return m_position;
}

bool Wall::Destroy()
{
	if (m_destructible == Destructible::destructible && m_exist)
	{
		m_exist = false;
		return true; // zid distrus
	}
	return false;
}

bool Wall::Hit()
{
	if (m_destructible == Destructible::destructible && m_exist)
	{
		m_hitCount++;
		if (m_hitCount >= 3)
			return Destroy(); 
	}
	return false;
}
