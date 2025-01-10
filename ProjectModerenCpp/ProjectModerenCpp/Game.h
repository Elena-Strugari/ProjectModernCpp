#pragma once
#include <vector>
#include <memory>
#include "Map.h"
#include "PlayerManager.h"
//#include "Collision.h"

class Game {
public:
    Game(uint8_t level);

    void AddPlayer(const std::shared_ptr<Player>& player);
    void Start();
   
    void MovePlayer(const std::string& playerName, MovementObject::Direction direction);
    void PlacePlayerOnMap(const std::shared_ptr<Player>& player);


private:
    Map m_map;
    std::shared_ptr<PlayerManager> m_playerManager; // Player manager
    //Collision m_collision;
};

