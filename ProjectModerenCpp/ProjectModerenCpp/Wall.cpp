#pragma once
#include "Wall.h"

Wall::Wall(Destructible destructible)
	:m_destructible{destructible}
{
}

Wall::Destructible Wall::IsDestructible() const
{
	return m_destructible;
}
