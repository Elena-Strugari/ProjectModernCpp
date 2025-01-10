#include "PlayerGameObjectManager.h"
#include <iostream>

PlayerGameObjectManager::PlayerGameObjectManager(Player* player, MovementObject* movement)
    : m_Player(player), m_Movement(movement) {}

Player* PlayerGameObjectManager::getPlayer() const {
    return m_Player;
}

MovementObject* PlayerGameObjectManager::getMovementObject() const {
    return m_Movement;
}

void PlayerGameObjectManager::moveTank(MovementObject::Direction direction) {
    if (m_Movement) {
        m_Movement->Move(direction);
        auto [x, y] = m_Movement->GetPosition();
      //  std::cout << "Player " << m_Player->getName() << " moved tank to position (" << x << ", " << y << ")." << std::endl;
    }
}

void PlayerGameObjectManager::shoot() {
    if (m_Movement) {
       // m_Movement->GetObject()->ShootObj();
        //std::cout << "Player " << m_Player->getName() << " fired a bullet!" << std::endl;
    }
}

void PlayerGameObjectManager::displayStatus() const {
    auto [x, y] = m_Movement->GetPosition();
    //std::cout << "Player: " << m_Player->getName()
    //    << ", Lives: " << m_Player->getLives()
       // << ", Tank Position: (" << x << ", " << y << ")"
       // << std::endl;
}
