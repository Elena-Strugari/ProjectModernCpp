//sa fac si daca in raza bombei , mai exista o bomba si ea se declanseaza 
#pragma once
#include <vector>
#include <memory>
#include <map>
#include "Bullet.h"
#include "Tank.h"
#include "Map.h"
#include "PlayerManager.h"
#include "Wall.h"

class Collision {
public:
    Collision(std::shared_ptr<Map> map, std::shared_ptr<PlayerManager> playerManager);

    void HandleBulletCollisions(std::vector<Bullet>& bullets);

    void HandleTankCollisions(std::vector<std::shared_ptr<Tank>>& tanks);

    void HandleBulletTankCollisions(std::vector<Bullet>& bullets, std::vector<std::shared_ptr<Tank>>& tanks);

    void HandleMultipleBulletWallCollisions(std::vector<Bullet>& bullets);

private:
    std::shared_ptr<Map> m_map;
    std::shared_ptr<PlayerManager> m_playerManager;
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