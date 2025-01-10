#include "MovementObject.h"


MovementObject::MovementObject(GameObject* gameObject)
    : m_GameObject(gameObject), m_MOx(1), m_MOy(1), m_direction(Direction::Up) {
    if (m_GameObject) {
        // Inițializează poziția tank-ului din GameObject
        //auto [x, y] = m_GameObject->GetPosition();
       // m_MOx = x;
        //m_MOy = y;
    }
}

uint16_t MovementObject::GetX() const
{
    return m_MOx;
}

uint16_t MovementObject::GetY() const
{
    return m_MOy;
}

GameObject* MovementObject::GetObject() const
{
    return m_GameObject;
}


void MovementObject::Move(Direction direction) {
    uint16_t newX = m_MOx, newY = m_MOy;

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

    // Actualizează poziția doar dacă există un GameObject
    if (m_GameObject) {
       // m_GameObject->SetPosition(newX, newY);
    }

    // Actualizează poziția internă
    SetPosition(newX, newY);

    std::cout << "Moved to position (" << newX << ", " << newY << ")." << std::endl;
}

void MovementObject::SetPosition(uint16_t x, uint16_t y) {
    m_MOx = x;
    m_MOy = y;

    if (m_GameObject) {
       // m_GameObject->SetPosition(x, y);
    }
}

std::pair<uint16_t, uint16_t> MovementObject::GetPosition()const
{
    return std::make_pair(m_MOx, m_MOy);
}

MovementObject::Direction MovementObject::GetDirection() const
{
    return m_direction;
}

