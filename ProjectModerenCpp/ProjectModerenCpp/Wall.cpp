#include "Wall.h"

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

Wall::Destructible Wall::IsDistructible() const
{
	return m_destructible;
}

Position Wall::GetPosition() const
{
	return m_position;
}

bool Wall::Destroy() const
{
	return false;
}

bool Wall::Hit()
{
	return false;
}
