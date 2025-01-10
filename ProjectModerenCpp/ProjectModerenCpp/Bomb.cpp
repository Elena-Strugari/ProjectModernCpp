#include "Bomb.h"



Bomb::Bomb(uint16_t x, uint16_t y)
    : m_x(x), m_y(y){}

uint16_t Bomb::getX() const {
    return m_x;
}

uint16_t Bomb::getY() const {
    return m_y;
}

void Bomb::setX(const uint16_t& x)
{
    m_x = x;
}
void Bomb::setY(const uint16_t& y)
{
    m_y = y;
}


void Bomb::explode() {
    if (m_exploded == false) {
        m_exploded = true;
    }
}

bool Bomb::isExploded() const {
    return m_exploded;
}

std::ostream& operator<<(std::ostream& os, const Bomb& bomb) {
    os << "Bomb [Position: (" << bomb.m_x << ", " << bomb.m_y << "), State: ";
    switch (bomb.m_exploded) {
    case false: os << "Nu a explodat"; break;
    case true: os << "A explodat"; break;
    }
    os << "]";
    return os;
}
