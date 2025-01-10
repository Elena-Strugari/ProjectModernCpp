#include "GameObject.h"

GameObject::GameObject() : m_tank(), m_bullet() {}

// Constructor parametrizat (folosind move semantics)
GameObject::GameObject(Tank&& tank, Bullet&& bullet)
    : m_tank(std::move(tank)), m_bullet(std::move(bullet)) {}

// Getters
const Tank& GameObject::GetTank() const {
    return m_tank;
}

Tank& GameObject::GetTank() {
    return m_tank;
}

const Bullet& GameObject::GetBullet() const {
    return m_bullet;
}

Bullet& GameObject::GetBullet() {
    return m_bullet;
}

void GameObject::ShootBullet() {
    if (!m_bullet.IsActive()) {
        m_bullet.SetBullet(true);
    }
}




std::ostream& operator<<(std::ostream& os, const GameObject& go) {
    // Print Tank details
    os << "GameObject contains:\n";
    os << "Tank Color: ";
    switch (go.m_tank.GetColor()) {
    case Tank::ColorTank::Red:
        os << "Red";
        break;
    case Tank::ColorTank::Blue:
        os << "Blue";
        break;
    case Tank::ColorTank::Green:
        os << "Green";
        break;
    case Tank::ColorTank::Yellow:
        os << "Yellow";
        break;
    }
    os << "\n";

    // Print Bullet status
    os << "Bullet is " << (go.m_bullet.IsActive() ? "active" : "inactive") << ".\n";

    return os;
}
