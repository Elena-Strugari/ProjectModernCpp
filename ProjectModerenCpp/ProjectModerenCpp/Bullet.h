#pragma once
#include "GameObject.h"
#include "MoveObject.h"

class Bullet: public GameObject, public MoveObject
{
public:
	Bullet();
	Bullet(uint8_t x, uint8_t y, Direction direction);
	void update() override;
	//void render() override; //GUI

private:
	uint8_t m_speed;
	Direction direction;
};

