#pragma once
#include "GameObject.h"

class MovementObject {
public:
    enum class Direction { Up, Down, Left, Right };

    explicit MovementObject(GameObject& gameObject);
    MovementObject(const MovementObject& other);            // Constructor de copiere
    MovementObject(MovementObject&& other) noexcept;        // Constructor de mutare
    MovementObject& operator=(const MovementObject& other); // Operator de atribuire prin copiere
    MovementObject& operator=(MovementObject&& other) noexcept; // Operator de atribuire prin mutare


    // Common movement logic
    std::pair<uint16_t, uint16_t> GetPosition(bool forBullet = false) const;
    void SetPosition(uint16_t x, uint16_t y, bool forBullet = false);

    Direction GetDirection(bool forBullet = false) const;
    void SetDirection(Direction direction, bool forBullet = false);

    std::pair<uint16_t, uint16_t> Move(Direction direction, bool forBullet = false);

    // Bullet management
    void Shoot();
    bool IsBulletActive() const;
    void DeactivateBullet();

    void print() const;

private:
    GameObject& m_gameObject;
    uint16_t m_tankX, m_tankY;
    Direction m_tankDirection;

    bool m_bulletActive;
    uint16_t m_bulletX, m_bulletY;
    Direction m_bulletDirection;
};
