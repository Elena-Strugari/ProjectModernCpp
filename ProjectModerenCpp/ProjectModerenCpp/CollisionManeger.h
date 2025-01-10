//sa fac si daca in raza bombei , mai exista o bomba si ea se declanseaza 
#pragma once
#include "Map.h"
#include <utility>

class CollisionManager {
public:
    CollisionManager(const Map& map);

    bool isPositionValid(uint16_t x, uint16_t y) const;                // Verifică dacă poziția este validă
    bool checkCollision(uint16_t x, uint16_t y) const;                 // Verifică dacă există o coliziune la poziția specificată
    bool isWall(uint16_t x, uint16_t y) const;                         // Verifică dacă poziția este un perete
    bool isTankCollision(uint16_t x, uint16_t y, uint16_t tankX, uint16_t tankY) const; // Coliziune între două tank-uri

private:
    const Map& m_map; // Referință la hartă
};





//server
//#pragma once
//#include "GameObject.h"
//#include "MovementObject.h"
//
//class CollisionManeger
//{
//public:
//	//CollisionType checkCollosion(GameObject obj1, GameObject obj2);
//};
//



//  din move class
/*enum class CollisionType {
    None,
    Wall,
    Tank,
    Bullet,
    Base
}; */



//CollisionType CheckCollision(int x, int y) {
//    // Poți implementa logica de coliziune
//    // De exemplu, verifică dacă poziția (x, y) este pe un perete sau în afacerea unei alte entități
//    if (m_map->IsWall(x, y)) {
//        return CollisionType::Wall;
//    }
//
//    // Dacă există alt obiect (tank, bază, etc.) pe acea poziție
//    if (m_map->IsTankAt(x, y)) {
//        return CollisionType::Tank;
//    }
//
//    // Dacă există un proiectil pe acea poziție
//    if (m_map->IsBulletAt(x, y)) {
//        return CollisionType::Bullet;
//    }
//
//    return CollisionType::None;
//}
//
//*/