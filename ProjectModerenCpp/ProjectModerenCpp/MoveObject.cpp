#include "MoveObject.h"
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

MoveObject::MoveObject(GameObject&& obj, Map* map, uint16_t startX, uint16_t startY)
    : GameObject(std::move(obj)), m_map(map), m_MOx(startX), m_MOy(startY), m_direction(Direction::Up) {
    if (m_map->IsValidPosition(m_MOx, m_MOy)) {
        m_map->SetCell(m_MOx, m_MOy, 'T');
        m_map->PrintWithBorder();
    }
    else {
        std::cerr << "Pozitia initiala a tancului este invalida!\n";
    }
}
void MoveObject::MoveCursorToTop() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = { 0, 0 };
    SetConsoleCursorPosition(hConsole, coordScreen);

}

void MoveObject::ShootBullet() {
    std::string shootMessage = m_bullet.Shoot();
    std::cout << shootMessage << std::endl;
}

void MoveObject::Move(Direction direction) {
    uint16_t newX = m_MOx, newY = m_MOy;

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
        m_map->SetCell(m_MOx, m_MOy, '_');
        m_MOx = newX;
        m_MOy = newY;
        m_map->SetCell(m_MOx, m_MOy, 'T');
        
        std::cout << "Tank moved to (" << m_MOx << ", " << m_MOy << ")\n";
    }
    else {
        std::cout << "Mutarea nu este posibila: obstacol sau iesire din harta\n";
    }
}
void MoveObject::HandleInput() {
    std::vector<std::string> messageLog;
    const int maxMessages = 3;
    std::cout << "Folositi sagetile pentru a muta tancul" << std::endl << "'b' pentru a trage, 'q' pentru a iesi\n";

    char key;
    while (true) {
        if (_kbhit()) {
            key = _getch();
            std::string message;
            if (key == 'q') {
                std::cout << "Joc incheiat.\n";
                break;
            }
            if (key == 'b') {
                std::string shootMessage = m_bullet.Shoot();
                message = shootMessage;
            }
            if (key == 72) {
                Move(Direction::Up);
                message = "Tancul s-a deplasat in sus.";
            }
            if (key == 80) {
                Move(Direction::Down);
                message = "Tancul s-a deplasat in jos.";
            }
            if (key == 75) {
                Move(Direction::Left);
                message = "Tancul s-a deplasat la stanga.";
            }
            if (key == 77) {
                Move(Direction::Right);
                message = "Tancul s-a deplasat la dreapta.";
            }      
            if (!message.empty()) {
                messageLog.push_back(message + " Pozitia curenta: (" + std::to_string(m_MOx) + ", " + std::to_string(m_MOy) + ")");
                if (messageLog.size() > maxMessages) {
                    messageLog.erase(messageLog.begin());
                }
            }
            system("cls");
            MoveCursorToTop();
            m_map->PrintWithBorder();
            for (const auto& msg : messageLog) {
                std::cout << msg << "\n";
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
       //
