#pragma once
#include "Map.h"
#include "CollisionManeger.h"
#include "Player.h"
#include "MovementObject.h"
#include <vector>

class Game {
public:
    Game(uint8_t level);

    void addPlayer(Player* player, MovementObject* movement);
    void update(); // Actualizează starea jocului
    void movePlayer(Player* player, MovementObject::Direction direction);

private:
    Map m_map; // Harta jocului
    CollisionManager m_collisionManager; // Managerul de coliziuni
    std::vector<std::pair<Player*, MovementObject*>> m_players; // Lista de jucători și mișcările lor
};







//server
//#pragma once
//#include "Map.h"
//
//class Game
//{
//public:
//	void start();
//	void update();
//	void checkCollisions();
//	void HandleInput();
//
//	//Functii test
//	Game();
//	void TestRun();
//	void DisplayMap() const;
//	void InitializeMap();
//
//	void Run();
//private:
//	/*Map  m_map;
//	std::vector<Tank> m_tanks;
//	std::vector<Bullet> m_bullets;
//	Player m_player;*/
//
//	// Variabile de test
//	Map m_map;
//	//void InitializeMap();
//};
//
