#pragma once
#include "GameObject.h"

class MovementObject {
public:
    enum class Direction { Up, Down, Left, Right };

    explicit MovementObject(GameObject& gameObject); 

    uint16_t GetX() const;
    uint16_t GetY() const;
   // GameObject* GetObject()const;
    std::pair<uint16_t, uint16_t> GetPosition() const;
    Direction GetDirection() const;

    void SetPosition(uint16_t x, uint16_t y);
    void SetDirection(Direction direction);
    void Move(Direction direction);

    void print()const;

private:
    GameObject& m_gameObject; 
    uint16_t m_x;          
    uint16_t m_y;          
    Direction m_direction;   
};



