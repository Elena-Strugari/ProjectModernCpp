#include "PowerUp.h"

PowerUp::PowerUp(uint8_t x, uint8_t y, PowerUpTyppe type)
	:GameObject(x, y)
	,m_type(type)
{
}

void PowerUp::activate(Player* player)
{
}
