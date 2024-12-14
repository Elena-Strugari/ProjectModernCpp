#pragma once
#ifndef CELL_H
#define CELL_H

class MapCell
{
private:
	bool m_isWall;
	bool m_isDestructible;

public:
	MapCell();
	bool IsWall() const;
	void SetWall(bool wall);

	bool IsDestructible() const;
	void SetDestructible(bool destructible);

	bool IsFree() const;
};
#endif // CELL_H
