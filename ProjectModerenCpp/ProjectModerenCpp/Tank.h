#pragma once
#include <cstdint>
#include "Bomb.h"
#include "Wall.h"

class Tank {
public:
    enum class Direction : uint8_t {
        Up,
        Down,
        Left,
        Right
    };

    enum class Type : uint8_t {
        Player,
        Enemy
    };

    Tank(uint16_t startX, uint16_t startY, Type type);

    void move(Direction direction);
    void rotate(Direction newDirection);
    // void shoot();
    void takeDamage(int amount);
    bool isDestroyed() const;
    void setPosition(int x, int y);
    Position getPosition() const;
    Direction getDirection() const;
    int getHealth() const;

private:
    Position m_position;
    Direction m_direction;
    int m_health;
    float m_speed;
    Type m_type;
};
