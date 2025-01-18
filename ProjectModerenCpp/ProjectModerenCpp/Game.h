#pragma once

#include <memory>
#include <vector>
#include <array>
#include "Map.h"
#include "PlayerManager.h"
#include "CollisionManager.h"

#include <thread>
#include <atomic>

class Game {
public:
    explicit Game(uint8_t level=1, const std::string& code=GenerateGameCode());
    static std::string GenerateGameCode();
    void AddPlayer(const std::shared_ptr<Player>& player);
    void Start();
    bool IsGameStarted() const { return m_gameStarted; }
    void MovePlayer(const std::shared_ptr<Player>& player, MovementObject::Direction direction);
   // void UpdateClientsWithNewMap();

    void PlacePlayerOnMap(const std::shared_ptr<Player>& player);
    void ShootBulletS(const std::shared_ptr<Player>& player);
    void MoveBullets();

    /*void GameLoop() {
        while (true) {
            MoveBullets();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }*/
    void HandlePlayerActions(std::shared_ptr<Player> player);  // Declare the method for handling player actions
    Map GetMap()const;
    std::vector<std::shared_ptr<Player>> m_players; 

    bool IsLastPlayer(const std::shared_ptr<Player>& player) const;

    //std::array<std::shared_ptr<Player>, 4> m_players;

    //de creat functie care primeste player din playerManager

    bool ExistPlayerInGame();
    void RecordChange(const std::pair<int, int>& newCoord, const std::pair<int, int>& lastCoord, const std::string& type);
    const std::vector<std::tuple<std::pair<int, int>, std::pair<int, int>, std::string>>& GetChangedCells() const;



private:
    Map m_map;
    std::string m_gameCode;
    bool m_gameStarted;
    std::shared_ptr<CollisionManager> m_collision;
    std::shared_ptr<PlayerManager> m_playerManager;

    std::vector<std::tuple<std::pair<int, int>, std::pair<int, int>, std::string>> m_changedCells;

};
