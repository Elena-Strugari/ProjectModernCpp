#pragma once
#ifndef CELL_H
#define CELL_H

#include <memory>
#include "GameEntity.h"

class MapCell
{
private:
	bool m_isWall;
	bool m_isDestructible;
	std::shared_ptr<GameEntity> m_object;

public:
	MapCell();
	bool IsWall() const;
	void SetWall(bool wall);

	bool IsDestructible() const;
	void SetDestructible(bool destructible);

	std::shared_ptr<GameEntity> GetObject() const;
	void SetObject(std::shared_ptr<GameEntity> obj);

	bool IsFree() const;
};
#endif // CELL_H
