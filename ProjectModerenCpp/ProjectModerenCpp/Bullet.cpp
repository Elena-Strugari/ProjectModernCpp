#include "Bullet.h"


std::ostream& operator<<(std::ostream& os, const Bullet& bullet)
{

    os << "->";
    return os;
}

Bullet::Bullet()
{
    m_isActive = false;
}

void Bullet::SetBullet(bool active)
{
    if(m_isActive!= active)
         m_isActive = active;
}

bool Bullet::IsActive() const
{
    return m_isActive;
}
