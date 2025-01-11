#include "MovementObject.h"
#include <iostream>

// Constructor
MovementObject::MovementObject(GameObject& gameObject)
    : m_gameObject(gameObject), m_tankX(0), m_tankY(0), m_tankDirection(Direction::Up),
    m_bulletActive(false), m_bulletX(0), m_bulletY(0), m_bulletDirection(Direction::Up) {}

// Common position and direction logic
std::pair<uint16_t, uint16_t> MovementObject::GetPosition(bool forBullet) const {
    return forBullet ? std::make_pair(m_bulletX, m_bulletY) : std::make_pair(m_tankX, m_tankY);
}

void MovementObject::SetPosition(uint16_t x, uint16_t y, bool forBullet) {
    if (forBullet) {
        m_bulletX = x;
        m_bulletY = y;
    }
    else {
        m_tankX = x;
        m_tankY = y;
    }
}

MovementObject::Direction MovementObject::GetDirection(bool forBullet) const {
    return forBullet ? m_bulletDirection : m_tankDirection;
}

void MovementObject::SetDirection(Direction direction, bool forBullet) {
    if (forBullet) {
        m_bulletDirection = direction;
    }
    else {
        m_tankDirection = direction;
    }
}

std::pair<uint16_t, uint16_t> MovementObject::Move(Direction direction, bool forBullet) {
    uint16_t& x = forBullet ? m_bulletX : m_tankX;
    uint16_t& y = forBullet ? m_bulletY : m_tankY;

    switch (direction) {
    case Direction::Up:    --y; break;
    case Direction::Down:  ++y; break;
    case Direction::Left:  --x; break;
    case Direction::Right: ++x; break;
    }

    if (forBullet) {
        m_bulletDirection = direction;
    }
    else {
        m_tankDirection = direction;
    }

    return { x, y };
}

// Bullet-specific logic
void MovementObject::Shoot() {
    if (!m_bulletActive) {
        m_bulletActive = true;
        m_bulletX = m_tankX;
        m_bulletY = m_tankY;
        m_bulletDirection = m_tankDirection;
    }
}

bool MovementObject::IsBulletActive() const {
    return m_bulletActive;
}

void MovementObject::DeactivateBullet() {
    m_bulletActive = false;
}

void MovementObject::print() const {
    std::cout << "Tank at (" << m_tankX << ", " << m_tankY << ") facing " << static_cast<int>(m_tankDirection) << ".\n";
    if (m_bulletActive) {
        std::cout << "Bullet at (" << m_bulletX << ", " << m_bulletY << ") moving " << static_cast<int>(m_bulletDirection) << ".\n";
    }
    else {
        std::cout << "Bullet is inactive.\n";
    }
}
