#pragma once
//tank + bullet
#include <cstdint>
#include "Tank.h"
#include "Bullet.h"

class GameObject: public Tank, public Bullet
{
public:
	GameObject(Tank::ColorTank tank , Bullet bullet);

private:

};

