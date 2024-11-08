#include "Tank.h"

Tank::Tank(ColorTank color)
	:m_color(color)
{
}

Tank::ColorTank Tank::GetColor() const
{
	return m_color;
}
