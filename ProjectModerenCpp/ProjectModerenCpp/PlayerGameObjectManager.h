#pragma once
#include "Player.h"
#include "MovementObject.h"

class PlayerGameObjectManager {
public:
    PlayerGameObjectManager(Player* player, MovementObject* movement);

    Player* getPlayer() const;
    MovementObject* getMovementObject() const;

    void moveTank(MovementObject::Direction direction); // Mută tank-ul
    void shoot();                                      // Tank-ul trage
    void displayStatus() const;                        // Afișează statusul jucătorului și poziția tank-ului

private:
    Player* m_Player;           // Jucătorul asociat
    MovementObject* m_Movement; // Obiectul de mișcare asociat
};
