#include "Wall.h"

Wall::Wall(uint16_t x, uint16_t y, bool destructible, bool exist, uint8_t hitCount /* Bomb* bomb, Heart* heart*/)
	: m_position{ x,y }
	, m_destructible(destructible)
	, m_exist(true)
	, m_hitCount(hitCount)
{
	//EMPTY
}

bool Wall::isDistructible() const
{
	return m_destructible;
}

Position Wall::getPosition() const
{
	return m_position;
}

bool Wall::destroy() const
{
	return false;
}

bool Wall::hit()
{
	return false;
}
