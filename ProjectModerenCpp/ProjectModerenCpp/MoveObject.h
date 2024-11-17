#pragma once
#include "GameObject.h"
#include "Map.h"

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
    MoveObject(GameObject&& obj, Map* map, int startX = 0, int startY = 0);
    void ShootBullet();
    void Move(Direction direction);
    void HandleInput();

private:
    Direction m_direction;
    Bullet m_bullet;
    int x, y;
    Map* m_map;
};

