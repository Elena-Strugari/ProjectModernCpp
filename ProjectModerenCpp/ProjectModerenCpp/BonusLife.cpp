#include "BonusLife.h"



BonusLife::BonusLife(uint16_t x, uint16_t y)
    : m_x(x), m_y(y) {}

uint16_t BonusLife::getX() const {
    return m_x;
}

uint16_t BonusLife::getY() const {
    return m_y;
}

void BonusLife::setX(const uint16_t& x)
{
    m_x = x;
}
void BonusLife::setY(const uint16_t& y)
{
    m_y = y;
}


void BonusLife::collected() {
    if (m_collected == false) {
        m_collected = true;
    }
}

bool BonusLife::isCollected() const {
    return m_collected;
}

std::ostream& operator<<(std::ostream& os, const BonusLife& BonusLife) {
    os << "BonusLife [Position: (" << BonusLife.m_x << ", " << BonusLife.m_y << "), State: ";
    switch (BonusLife.m_collected) {
    case false: os << "Nu a fost colectat"; break;
    case true: os << "e colectat"; break;
    }
    os << "]";
    return os;
}
