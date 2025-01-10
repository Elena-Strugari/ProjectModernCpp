//#include "CollisionManeger.h"
//#include <iostream>
//
//CollisionManager::CollisionManager(const Map& map) : m_map(map) {}
//
//bool CollisionManager::isPositionValid(uint16_t x, uint16_t y) const {
//    // Verifică dacă poziția este validă pe hartă
//    return m_map.IsValidPosition(x, y);
//}
//
//bool CollisionManager::checkCollision(uint16_t x, uint16_t y) const {
//    // Verifică dacă poziția este ocupată de un perete sau un alt obstacol
//    if (!isPositionValid(x, y)) {
//        return true; // Poziție invalidă, considerată coliziune
//    }
//
//    auto cell = m_map.GetCell(x, y);
//    return (cell.typeWall != Wall::TypeWall::destructible && cell.typeWall != Wall::TypeWall::none);
//}
//
//bool CollisionManager::isWall(uint16_t x, uint16_t y) const {
//    // Verifică dacă poziția este ocupată de un perete
//    if (!isPositionValid(x, y)) {
//        return false; // Poziție invalidă, nu este perete
//    }
//
//    auto cell = m_map.GetCell(x, y);
//    return (cell.typeWall == Wall::TypeWall::indestructible || cell.typeWall == Wall::TypeWall::destructible);
//}
//
//bool CollisionManager::isTankCollision(uint16_t x, uint16_t y, uint16_t tankX, uint16_t tankY) const {
//    // Verifică dacă două tank-uri se află pe aceeași poziție
//    return (x == tankX && y == tankY);
//}
