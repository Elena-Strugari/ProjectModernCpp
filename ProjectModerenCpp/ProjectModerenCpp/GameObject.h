#pragma once
#include <cstdint>
#include "Tank.h"
#include "Bullet.h"

class GameObject 
{
public:
    GameObject();
    GameObject(Tank&& tank, Bullet&& bullet= Bullet());

    // Getters
    const Tank& GetTank() const;
    Tank& GetTank(); 
    const Bullet& GetBullet() const;
    Bullet& GetBullet();

    void ShootBullet(); 

     friend std::ostream& operator<<(std::ostream& os, const GameObject& go);


private:
    Tank m_tank;
    Bullet m_bullet;
};

