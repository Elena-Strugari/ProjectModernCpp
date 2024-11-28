#include "GameObject.h"


GameObject::GameObject()
{
	std::cout << "costructor def gameObject";
}

GameObject::GameObject(Tank::ColorTank tank)
	:m_GOTank(tank) {}

const Tank& GameObject::GetTank() const
{
	return m_GOTank;
}

const Bullet& GameObject::GetBullet() const
{
	return m_GOBullet;
}

void GameObject::ShootObj()
{
	m_GOBullet.Shoot();
}

std::ostream& operator<<(std::ostream& os, const GameObject& go)
{
	os << "GameObject: " << go.m_GOTank << " and Bullet: " << go.m_GOBullet;
	return os;
}

//denisa