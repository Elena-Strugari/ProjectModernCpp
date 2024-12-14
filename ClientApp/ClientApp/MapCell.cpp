#include "MapCell.h"

MapCell::MapCell()
	: m_isWall(false)
	, m_isDestructible(false)
	//, m_object(nullptr)
{
	//EMPTY
}

bool MapCell::IsWall() const
{
	return m_isWall;
}

void MapCell::SetWall(bool wall)
{
	m_isWall = wall;
}

bool MapCell::IsDestructible() const
{
	return m_isDestructible;
}

void MapCell::SetDestructible(bool destructible)
{
	m_isDestructible = destructible;
}

bool MapCell::IsFree() const
{
	return !m_isWall && !m_isDestructible; //&& !m_object;
}
