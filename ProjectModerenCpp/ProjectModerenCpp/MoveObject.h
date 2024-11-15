#pragma once
#include "GameObject.h"

class MoveObject: public GameObject
{
public:
    enum class Direction {
        Up,
        Down,
        Left,
        Right
    };

    enum class CollisionType {
        None,
        Wall,
        Tank,
        Bullet,
        Base
    };
public:
    MoveObject(GameObject&& obj);
    void ShootBullet();

private:
    Direction m_direction;
};

