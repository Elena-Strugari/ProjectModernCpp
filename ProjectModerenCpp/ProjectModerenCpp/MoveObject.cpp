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
