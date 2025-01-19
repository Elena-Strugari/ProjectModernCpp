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
    //void MovePlayer(const std::shared_ptr<Player>& player, MovementObject::Direction direction);
    void MovePlayer(const std::string& playerName, MovementObject::Direction direction);
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
    //std::vector<std::shared_ptr<Player>> m_players; 
    bool IsPlayerInGame(const std::string& playerName) const;


    bool IsLastPlayer(const std::string& playerName) const;

    std::shared_ptr<Player> GetPlayer(const std::string& name);
    //std::array<std::shared_ptr<Player>, 4> m_players;

    //de creat functie care primeste player din playerManager

   // bool ExistPlayerInGame();
    void RecordChange(const std::pair<int, int>& newCoord, const std::pair<int, int>& lastCoord, const std::string& type);
    const std::vector<std::tuple<std::pair<int, int>, std::pair<int, int>, std::string>>& GetChangedCells() const;

    void ClearChangedCells() {
        m_changedCells.clear();
    }
    bool IsMaxPlayersReached() const {
        // Check if the number of players has reached the limit (4 players in this case)
        return m_playerManager->GetPlayerCount() >= 4;
    }

    void RemovePlayer(const std::string& playerName) {
        m_playerManager->RemovePlayer(playerName);
    }

private:
    Map m_map;
    std::string m_gameCode;
    bool m_gameStarted;
    std::shared_ptr<CollisionManager> m_collision;
    std::shared_ptr<PlayerManager> m_playerManager;

    std::vector<std::tuple<std::pair<int, int>, std::pair<int, int>, std::string>> m_changedCells;

};
