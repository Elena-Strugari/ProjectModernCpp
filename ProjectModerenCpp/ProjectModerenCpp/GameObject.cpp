#include "GameObject.h"


GameObject::GameObject() : m_PosX(0), m_PosY(0) {
	std::cout << "Constructor default GameObject\n";
}

GameObject::GameObject(Tank::ColorTank tank)
	: m_GOTank(tank), m_PosX(0), m_PosY(0) {}

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

void GameObject::SetPosition(uint16_t x, uint16_t y) {
	m_PosX = x;
	m_PosY = y;
	std::cout << "GameObject position set to (" << m_PosX << ", " << m_PosY << ")." << std::endl;
}

std::pair<uint16_t, uint16_t> GameObject::GetPosition() const {
	return { m_PosX, m_PosY };
}
