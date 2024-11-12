#include "Tank.h"
#include <format>

Tank::Tank(ColorTank color)
	:m_color(color)
{
}

Tank::ColorTank Tank::GetColor() const
{
	return m_color;
}

std::ostream& operator<<(std::ostream& os, const Tank& tank)
{
    switch (tank.GetColor()) {
    case Tank::ColorTank::Red:    os << "R"; break;
    case Tank::ColorTank::Blue:   os << "B"; break;
    case Tank::ColorTank::Green:  os << "G"; break;
    case Tank::ColorTank::Yellow: os << "Y"; break;
    }
    return os;
}
