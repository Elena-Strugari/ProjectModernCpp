﻿#pragma once

#include <memory>
#include <vector>
#include "Map.h"
#include "PlayerManager.h"
#include "CollisionManager.h"


class Game {
public:
    explicit Game(uint8_t level);

    void AddPlayer(const std::shared_ptr<Player>& player);
    void Start();
    void MovePlayer(const std::shared_ptr<Player>& player, MovementObject::Direction direction);
    void PlacePlayerOnMap(const std::shared_ptr<Player>& player);

    void ShootBulletS(const std::shared_ptr<Player>& player);
    void MoveBullets();


private:
    Map m_map;
    std::shared_ptr<PlayerManager> m_playerManager;
    std::shared_ptr<CollisionManager> m_collision;
};
