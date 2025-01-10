#include "MovementObject.h"
#include <iostream>

// Constructor
MovementObject::MovementObject(GameObject& gameObject)
    : m_gameObject(gameObject), m_x(0), m_y(0), m_direction(Direction::Up) {}

// Getters
uint16_t MovementObject::GetX() const {
    return m_x;
}

uint16_t MovementObject::GetY() const {
    return m_y;
}

std::pair<uint16_t, uint16_t> MovementObject::GetPosition() const {
    return { m_x, m_y };
}

MovementObject::Direction MovementObject::GetDirection() const {
    return m_direction;
}

// Setters
void MovementObject::SetPosition(uint16_t x, uint16_t y) {
    m_x = x;
    m_y = y;
}

void MovementObject::SetDirection(Direction direction) {
    m_direction = direction;
}

// Movement Logic
void MovementObject::Move(Direction direction) {
    uint16_t newX = m_x;
    uint16_t newY = m_y;

    switch (direction) {
    case Direction::Up:
        newY--;
        break;
    case Direction::Down:
        newY++;
        break;
    case Direction::Left:
        newX--;
        break;
    case Direction::Right:
        newX++;
        break;
    }
    SetPosition(newX, newY);
    SetDirection(direction);
}

void MovementObject::print()const
{
    std::cout << "Moved to (" << m_x << ", " << m_y << ") in direction "
        << static_cast<int>(m_direction) << ".\n";
}
