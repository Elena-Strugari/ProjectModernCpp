#pragma once
#include <cstdint>

class Wall
{
public:
	enum class TypeWall
	{
		destructible,
		indestructible,
	};
public:

	Wall(TypeWall typeWall);

	TypeWall IsDestructible()const;

private:

	Wall::TypeWall m_typeWall;

};

