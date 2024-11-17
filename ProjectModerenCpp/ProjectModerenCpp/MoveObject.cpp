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
