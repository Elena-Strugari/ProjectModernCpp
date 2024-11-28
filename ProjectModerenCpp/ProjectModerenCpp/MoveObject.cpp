#include "MoveObject.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>



MoveObject::MoveObject(GameObject&& obj, Map* map)
    : GameObject(std::move(obj)), m_map(map), m_MOx(0), m_MOy(0), m_direction(Direction::Up) {}

void MoveObject::MoveCursorToTop() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = { 0, 0 };
    SetConsoleCursorPosition(hConsole, coordScreen);

}

uint16_t MoveObject::GetX() const
{
    return m_MOx;
}

uint16_t MoveObject::GetY() const
{
    return m_MOy;
}

void MoveObject::SetPosition(uint16_t x, uint16_t y)
{
    m_MOx = x;
    m_MOy = y;
}

void MoveObject::SetColor(Tank::ColorTank color)
{
    m_color = color;
}

std::pair<uint16_t, uint16_t> MoveObject::GetPosition()const
{
    return std::make_pair(m_MOx, m_MOy);
}

bool MoveObject::IsValidPos(uint16_t x, uint16_t y)const
{
    return m_map->IsValidPosition(x, y);
}

std::tuple<uint16_t, uint16_t, Tank::ColorTank> MoveObject::StartPositionColor()
{
    //daca e primul jucator 
    m_MOx = 1;
    m_MOy = 1;
    m_color = Tank::ColorTank::Blue;

    return std::make_tuple(m_MOx, m_MOy, m_color);
    // vor venii mai multe if uri pt ceilalti jucator(cred) , va trebui sa avem ca parametru si id jucator
    //va trebui returnat si map , nu stiu cum pt serverObeject 
}



void MoveObject::ShootBullet() {
    std::string shootMessage = m_bullet.Shoot();
    std::cout << shootMessage << std::endl;
}

void MoveObject::Move(Direction direction) {
    uint16_t newX = m_MOx, newY = m_MOy;

    switch (direction) {
    case Direction::Up:
        newY--;
        break;
    case Direction::Down:
        newY++;
        break;
    case Direction::Left:
        newX--;
        break;
    case Direction::Right:
        newX++;
        break;
    }

    //collision
}

void MoveObject::MoveServer(uint16_t x, uint16_t y, Direction direction)
{

    //de revenit 
    switch (direction) {
    case Direction::Up:
        if (y > 0)
            y--;
        break;
    case Direction::Down:
        //  if (y < m_map->GetHeight()-1) // Limita grilei
        y++;
        break;
    case Direction::Left:
        if (x > 0)
            x--;
        break;
    case Direction::Right:
        // if (x < m_map->GetWidth()-1) // Limita grilei
        x++;
        break;
    }
    MoveObject::SetPosition(x, y);
}

//incercari

//void MoveObject::HandleInput() {
//    std::vector<std::string> messageLog;
//    const int maxMessages = 3;
//    std::cout << "Folositi sagetile pentru a muta tancul" << std::endl << "'b' pentru a trage, 'q' pentru a iesi\n";
//
//    char key;
//    while (true) {
//        if (_kbhit()) {
//            key = _getch();
//            std::string message;
//            if (key == 'q') {
//                std::cout << "Joc incheiat.\n";
//                break;
//            }
//            if (key == 'b') {
//                std::string shootMessage = m_bullet.Shoot();
//                message = shootMessage;
//            }
//            if (key == 72) {
//                Move(Direction::Up);
//                message = "Tancul s-a deplasat in sus.";
//            }
//            if (key == 80) {
//                Move(Direction::Down);
//                message = "Tancul s-a deplasat in jos.";
//            }
//            if (key == 75) {
//                Move(Direction::Left);
//                message = "Tancul s-a deplasat la stanga.";
//            }
//            if (key == 77) {
//                Move(Direction::Right);
//                message = "Tancul s-a deplasat la dreapta.";
//            }
//            if (!message.empty()) {
//                messageLog.push_back(message + " Pozitia curenta: (" + std::to_string(m_MOx) + ", " + std::to_string(m_MOy) + ")");
//                if (messageLog.size() > maxMessages) {
//                    messageLog.erase(messageLog.begin());
//                }
//            }
//            system("cls");
//            MoveCursorToTop();
//
//            for (const auto& msg : messageLog) {
//                std::cout << msg << "\n";
//            }
//
//        }
//    }
//}
//std::tuple<uint16_t, uint16_t, Tank::ColorTank>  MoveObject::MoveServer2(Direction direction) {
//    uint16_t newX = m_MOx, newY = m_MOy;
//
//    switch (direction) {
//    case Direction::Up:
//        newY--;
//        break;
//    case Direction::Down:
//        newY++;
//        break;
//    case Direction::Left:
//        newX--;
//        break;
//    case Direction::Right:
//        newX++;
//        break;
//    }
//    return std::make_tuple(newX, newY, m_color);
//
//    //collision
//}

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