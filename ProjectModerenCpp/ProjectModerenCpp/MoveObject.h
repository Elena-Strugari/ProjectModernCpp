#pragma once
#include "GameObject.h"
#include "Map.h"
#include <cstdint>

class MoveObject : public GameObject
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
    MoveObject() = default;
    MoveObject(GameObject&& obj, Map* map);
    MoveObject(const MoveObject&) = delete;    // Explicitly deleted copy constructor
    ~MoveObject() = default;
    MoveObject& operator=(MoveObject&& other) noexcept {
        if (this == &other) // Verificăm auto-atribuirea
            return *this;
        m_MOx = other.m_MOx;
        m_MOy = other.m_MOy;
        m_color = other.m_color;
        return *this;
    }

    //Get 
    uint16_t GetX()const;
    uint16_t GetY()const;
    std::pair<uint16_t, uint16_t> GetPosition()const;


    //set 
    void SetPosition(uint16_t x, uint16_t y);
    void SetColor(Tank::ColorTank color);

    //valid 
    bool IsValidPos(uint16_t x, uint16_t y)const;

    void ShootBullet();
    void Move(Direction direction);
    //std::tuple<uint16_t, uint16_t, Tank::ColorTank>  MoveServer2(Direction direction);
    void MoveServer(uint16_t x, uint16_t y, Direction direction);
    void HandleInput();
    void MoveCursorToTop();
    std::tuple<uint16_t, uint16_t, Tank::ColorTank> StartPositionColor();

private:
    Direction m_direction;
    Bullet m_bullet;
    uint16_t m_MOx, m_MOy;
    Tank::ColorTank m_color;
    Map* m_map;
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
