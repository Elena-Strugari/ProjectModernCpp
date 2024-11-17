#include "MoveObject.h"
#include <conio.h>
#include <iostream>

MoveObject::MoveObject(GameObject&& obj, Map* map, int startX, int startY)
    : GameObject(std::move(obj)), m_map(map), x(startX), y(startY) {
    if (m_map->IsValidPosition(x, y)) {
        m_map->SetCell(x, y, 'T');
        m_map->PrintWithBorder();
    }
    else {
        std::cerr << "Pozitia initiala a tancului este invalida!\n";
    }
}

void MoveObject::ShootBullet() {
    m_bullet.Shoot();
}
void MoveObject::Move(Direction direction) {
    int newX = x, newY = y;

    switch (direction) {
    case Direction::Up:
        newX--;
        break;
    case Direction::Down:
        newX++;
        break;
    case Direction::Left:
        newY--;
        break;
    case Direction::Right:
        newY++;
        break;
    }

    if (m_map->IsValidPosition(newX, newY) && m_map->GetCell(newX, newY) == '_') {
        m_map->SetCell(x, y, '_');
        x = newX;
        y = newY;
        m_map->SetCell(x, y, 'T');
        std::cout << "Tank moved to (" << x << ", " << y << ")\n";
    }
    else {
        std::cout << "Mutarea nu este posibila: obstacol sau iesire din harta\n";
    }
}
void MoveObject::HandleInput() {
    std::cout << "Folositi sagetile pentru a muta tancul" << std::endl << "'b' pentru a trage, 'q' pentru a iesi\n";

    char key;
    while (true) {
        if (_kbhit()) {
            key = _getch();
            if (key == 'q') {
                std::cout << "Joc încheiat.\n";
                break;
            }
            if (key == 'b') {
                ShootBullet();
            }
            if (key == 72) {
                Move(Direction::Up);
                std::cout << "Tancul s-a deplasat in sus.\n";
            }
            if (key == 80) {
                Move(Direction::Down);
                std::cout << "Tancul s-a deplasat in jos.\n";
            }
            if (key == 75) {
                Move(Direction::Left);
                std::cout << "Tancul s-a deplasat la stanga.\n";
            }
            if (key == 77) {
                Move(Direction::Right);
                std::cout << "Tancul s-a deplasat la dreapta.\n";
            }

            m_map->PrintWithBorder();
        }
    }
}

//void move(Direction direction);
       //void rotate(Direction newDirection);
       //// void shoot();
       //void takeDamage(int amount);
       //bool isDestroyed() const;
       //void setPosition(int x, int y);
       //Position getPosition() const;
       //Direction getDirection() const;
       //uint16_t getHealth() const;
       //float GetSpeed()const;



       //void Tank::setPosition(int x, int y) {
       //    m_position.x = x;
       //    m_position.y = y;
       //}
       //Position Tank::getPosition() const {
       //    return m_position;
       //}
       //
       //Tank::Direction Tank::getDirection() const {
       //    return m_direction;
       //}
       //
       //uint16_t Tank::getHealth() const {
       //    return m_health;
       //}
       //
       //float Tank::GetSpeed() const
       //{
       //    return m_speed;
       //
