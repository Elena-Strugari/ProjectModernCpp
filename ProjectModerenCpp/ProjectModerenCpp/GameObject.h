#pragma once
//tank + bullet
#include <cstdint>
#include "Tank.h"
#include "Bullet.h"
#include <conio.h>

class GameObject: public Tank, public Bullet
{
public:

	void ShootBullet();

	//print
	GameObject(Tank::ColorTank tank);
	const Tank& GetTank()const {
		return m_GOTank;
	}
	const Bullet& GetBullet() const {
		return m_GOBullet;
	}

	friend std::ostream& operator<<(std::ostream& os, const GameObject& go);

private:
	Tank m_GOTank;
	Bullet m_GOBullet;
};

