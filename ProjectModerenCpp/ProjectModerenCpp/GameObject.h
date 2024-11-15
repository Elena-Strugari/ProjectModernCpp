#pragma once
//tank + bullet
#include <cstdint>
#include "Tank.h"
#include "Bullet.h"

class GameObject: public Tank, public Bullet
{
public:
	GameObject(const GameObject&) = delete; 
	GameObject& operator=(const GameObject&) = delete; 
	GameObject(GameObject&& other) noexcept
		: m_GOTank(std::move(other.m_GOTank)),  // Mutãm membrul m_GOTank
		m_GOBullet(std::move(other.m_GOBullet)) {  // Mutãm membrul m_GOBullet
	}

	//print
	GameObject(Tank::ColorTank tank);
	const Tank& GetTank()const {
		return m_GOTank;
	}
	const Bullet& GetBullet() const {
		return m_GOBullet;
	}

	friend std::ostream& operator<<(std::ostream& os, const GameObject& go);

	// shoot
	void ShootObj() {
		m_GOBullet.Shoot();
	}

private:
	Tank m_GOTank;
	Bullet m_GOBullet;
};

