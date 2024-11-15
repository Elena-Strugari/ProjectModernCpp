#include "MoveObject.h"
#include <conio.h>


MoveObject::MoveObject(GameObject&& obj)
    :GameObject(std::move(obj))
{
}

void MoveObject::ShootBullet()
{
    std::cout << "Apasa 'b' pentru a trage ('q' pentru a iesi)...\n";

    char key;
    while (true) {
        if (_kbhit()) { 
            key = _getch(); 

            if (key == 'q') { 
                std::cout << "End Game.\n";
                break;
            }

            if (key == 'b') { 
                Shoot();
            }
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
//}
