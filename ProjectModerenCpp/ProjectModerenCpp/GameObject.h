#pragma once
//tank + bullet
#include <cstdint>
#include "Tank.h"
#include "Bullet.h"

class GameObject 
{
public:
	GameObject();
	GameObject(Tank::ColorTank tank);

	GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;
	GameObject(GameObject&& other) noexcept
		: m_GOTank(std::move(other.m_GOTank)),
		m_GOBullet(std::move(other.m_GOBullet)) {
	}
	friend std::ostream& operator<<(std::ostream& os, const GameObject& go);

	GameObject& operator=(GameObject&& other) noexcept {
		if (this != &other) {
			m_GOTank = std::move(other.m_GOTank);   // move Tank
			m_GOBullet = std::move(other.m_GOBullet);  // move Bullet
		}
		return *this;
	}

	const Tank& GetTank()const;
	const Bullet& GetBullet() const;

	// shoot
	void ShootObj();

private:
	Tank m_GOTank;
	Bullet m_GOBullet;
};

