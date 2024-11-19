#pragma once
#include "GameObject.h"
#include "Map.h"
#include <cstdint>

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
    MoveObject(GameObject&& obj, Map* map, uint16_t startX = 0, uint16_t startY = 0);
    void ShootBullet();
    void Move(Direction direction);
    void HandleInput();

private:
    Direction m_direction;
    Bullet m_bullet;
    uint16_t m_MOx, m_MOy;
    Map* m_map;
};

