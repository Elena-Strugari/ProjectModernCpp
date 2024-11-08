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
	return os << std::format("{}",
		static_cast<int>(tank.GetColor())
	);
}
