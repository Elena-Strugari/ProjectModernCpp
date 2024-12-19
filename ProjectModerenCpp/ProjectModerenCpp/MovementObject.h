#pragma once
#include "GameObject.h"

class MovementObject {
public:
    enum class Direction { Up, Down, Left, Right };

    MovementObject(GameObject* gameObject); // Constructor cu GameObject

    uint16_t GetX() const;
    uint16_t GetY() const;
    GameObject* GetObject()const;
    std::pair<uint16_t, uint16_t> GetPosition() const;

    void SetPosition(uint16_t x, uint16_t y);
    void Move(Direction direction);
    Direction GetDirection() const;

private:
    GameObject* m_GameObject; // Pointer către GameObject
    uint16_t m_MOx;          // Poziția curentă pe axa X
    uint16_t m_MOy;          // Poziția curentă pe axa Y
    Direction m_direction;   // Direcția curentă
};



//idee

/*
//private

CollisionType CheckCollision(int x, int y) {
        // Poți implementa logica de coliziune
        // De exemplu, verifică dacă poziția (x, y) este pe un perete sau în afacerea unei alte entități
        if (m_map->IsWall(x, y)) {
            return CollisionType::Wall;
        }

        // Dacă există alt obiect (tank, bază, etc.) pe acea poziție
        if (m_map->IsTankAt(x, y)) {
            return CollisionType::Tank;
        }

        // Dacă există un proiectil pe acea poziție
        if (m_map->IsBulletAt(x, y)) {
            return CollisionType::Bullet;
        }

        return CollisionType::None;
    }

*/
