#include "Game.h"
#include "CollisionManager.h"
#include "libs/nlohmann/json.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>
using json = nlohmann::json;

Game::Game(uint8_t level, const std::string& code)
    : m_map(level),
    m_playerManager(std::make_shared<PlayerManager>()),
    m_gameCode(code),
    m_gameStarted(false) {
    // Inițializează CollisionManager după ce m_map și m_playerManager sunt complet inițializați
    m_collision = std::make_shared<CollisionManager>(std::make_shared<Map>(m_map), m_playerManager);
}


std::string Game::GenerateGameCode()
{
    std::string code;
    static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 6; ++i) {
        code += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return code;

}

void Game::AddPlayer(const std::shared_ptr<Player>& player) {

    std::thread playerThread(&Game::HandlePlayerActions, this, player);
    playerThread.detach();
    player->AddPlayerObject();
    m_playerManager->AddPlayer(player);
   // m_players.emplace(player);
    PlacePlayerOnMap(player);
}

void Game::Start() {
    std::cout << "Starting game..." << std::endl;
    m_map.DisplayMap();
}

//void Game::MovePlayer(const std::string& playerName, MovementObject::Direction direction) {
//    // Get player by name from PlayerManager
//    auto player = m_playerManager->GetPlayer(playerName);
//    if (player) {
//        // Perform movement
//        //player->Move(direction);
//        player->Move();
//    }
//    else {
//        std::cerr << "Player not found!" << std::endl;
//    }
//}

void Game::PlacePlayerOnMap(const std::shared_ptr<Player>& player) {
    static std::vector<std::pair<uint16_t, uint16_t>> cornerPositions = {
        {1, 1},
        {1, m_map.GetHeight() - 2},
        {m_map.GetWidth() - 2, 1},
        {m_map.GetWidth() - 2, m_map.GetHeight() - 2}
    };

    static size_t nextCornerIndex = 0;

    auto [startX, startY] = cornerPositions[nextCornerIndex];
    nextCornerIndex = (nextCornerIndex + 1) % cornerPositions.size(); // Cycle through corners

    // Ensure the corner position is valid before placing the player
    /*if (!m_map.IsValidPosition(startX, startY) ||
        !std::holds_alternative<Map::Empty>(m_map.GetCell(startX, startY).content)) {
        throw std::runtime_error("Corner position is invalid for player placement.");
    }*/
    if (!m_map.IsValidPosition(startX, startY))
        std::cout << "erroare la valid";
    if (!std::holds_alternative<Map::Empty>(m_map.GetCell(startX, startY).content)) {
        std::cout << "eroare la cell";
    }

    auto& movement = player->GetMovementObject();
    movement.SetPosition(startX, startY);
    m_map.SetCellContent(startX, startY, Map::Tank{});

    std::pair<int, int> lastCoord = { startX, startY };
    std::pair<int, int> newCoord = { startX, startY };

    RecordChange(newCoord, lastCoord, "player");
    
}


//void Game::MovePlayer(const std::shared_ptr<Player>& player, MovementObject::Direction direction) {
//    auto& movement = player->GetMovementObject();
//    auto [currentX, currentY] = movement.GetPosition();
//    auto [newX, newY] = movement.Move(direction);
//
//    if (!m_map.IsValidPosition(newX, newY)) {
//        std::cout << "Movement blocked to (" << newX << ", " << newY << ") due to invalid position.\n";
//        return;
//    }
//
//    if (std::holds_alternative<Map::Empty>(m_map.GetCell(newX, newY).content) &&
//        !m_collision->isOccupiedByAnotherTank(m_playerManager->GetAllPlayers(), newX, newY, player)) {
//        m_map.SetCellContent(currentX, currentY, Map::Empty{});
//        m_map.SetCellContent(newX, newY, Map::Tank{});
//
//        movement.SetPosition(newX, newY);
//        movement.SetDirection(direction);
//
//        std::pair<int, int> lastCoord = { currentX, currentY };
//        std::pair<int, int> newCoord = { newX, newY };
//
//        RecordChange(newCoord, lastCoord, "player");
//        //UpdateClientsWithNewMap();
//    }
//    else {
//        std::cout << "Movement blocked to (" << newX << ", " << newY << ") due to collision or obstruction.\n";
//    }
//}

void Game::MovePlayer(const std::string& Nameplayer, MovementObject::Direction direction) {

    auto player = m_playerManager->GetPlayer(Nameplayer);
    auto& movement = player->GetMovementObject();
    auto [currentX, currentY] = movement.GetPosition();
    auto [newX, newY] = movement.Move(direction);

    if (!m_map.IsValidPosition(newX, newY)) {
        std::cout << "Movement blocked to (" << newX << ", " << newY << ") due to invalid position.\n";
        return;
    }

    if (std::holds_alternative<Map::Empty>(m_map.GetCell(newX, newY).content) &&
        !m_collision->isOccupiedByAnotherTank(m_playerManager->GetAllPlayers(), newX, newY, player)) {
        m_map.SetCellContent(currentX, currentY, Map::Empty{});
        m_map.SetCellContent(newX, newY, Map::Tank{});

        movement.SetPosition(newX, newY);
        movement.SetDirection(direction);

        std::pair<int, int> lastCoord = { currentX, currentY };
        std::pair<int, int> newCoord = { newX, newY };

        RecordChange(newCoord, lastCoord, "player");
        //UpdateClientsWithNewMap();
    }
    if (std::holds_alternative<Wall::TypeWall>(m_map.GetCell(newX, newY).content)) {
        auto& wall = std::get<Wall::TypeWall>(m_map.GetCell(newX, newY).content);
        if (wall == Wall::TypeWall::destructible) {
            // Handle the destruction of the wall (e.g., change it to empty or another state)
            m_map.SetCellContent(currentX, currentY, Map::Empty{});  // Destroy the destructible wall
            m_map.SetCellContent(newX, newY, Map::Empty{});  // Destroy the destructible wall
            //std::cout << "Destructible wall at (" << newX << ", " << newY << ") destroyed!" << std::endl;
            std::pair<int, int> lastCoord = { currentX, currentY };
            std::pair<int, int> newCoord = { newX, newY };

            RecordChange(newCoord, lastCoord, "wall");
        }
    }
    else {
        std::cout << "Movement blocked to (" << newX << ", " << newY << ") due to collision or obstruction.\n";
    }
}




//void Game::UpdateClientsWithNewMap() {
//
//    std::cout << "mapUpdate";
//    //for (auto& client : m_players) {
//    //    // Send the updated map to each client
//    //    client->SendUpdatedMap(m_map.GetMapAsJson());
//    //}
//}

//nlohmann::json Game::GetMapAsJson() {
//    nlohmann::json jsonMap;
//
//    // Serialize the map to JSON
//    jsonMap["width"] = m_map.GetWidth();
//    jsonMap["height"] = m_map.GetHeight();
//
//    // For simplicity, assuming m_map.GetMap() returns a 2D vector or array of cells
//    std::vector<std::vector<int>> mapData;
//
//    for (int i = 0; i < m_map.GetHeight(); ++i) {
//        std::vector<int> rowData;
//        for (int j = 0; j < m_map.GetWidth(); ++j) {
//            // Serialize each cell in the map. For example, 0 for empty, 1 for walls, etc.
//            rowData.push_back(m_map.GetCell(i, j).GetType());
//        }
//        mapData.push_back(rowData);
//    }
//
//    jsonMap["cells"] = mapData;
//    return jsonMap;
//}

void Game::ShootBulletS(const std::shared_ptr<Player>& player) {
    auto& movement = player->GetMovementObject();
    movement.Shoot();
}

void Game::MoveBullets() {
    for (const auto& player : m_playerManager->GetAllPlayers()) {
        auto& movement = player->GetMovementObject();
        auto [currentX, currentY] = movement.GetPosition();

        if (movement.IsBulletActive()) {
            auto [newX, newY] = movement.Move(movement.GetDirection(), 1);
            if (m_map.IsValidPosition(newX, newY)) {
                m_collision->HandleBulletCollisions();

                if (std::holds_alternative<Map::Empty>(m_map.GetCell(newX, newY).content)) {
                    m_map.SetCellContent(currentX, currentY, Map::Empty{}); // Clear old position
                    m_map.SetCellContent(newX, newY, Map::Bullet{});
                }
                else {
                    movement.DeactivateBullet();
                    m_map.SetCellContent(currentX, currentY, Map::Empty{}); // Clear bullet
                }
            }
        }
    }

}

void Game::HandlePlayerActions(std::shared_ptr<Player> player)
{
    while (player->IsAlive()) {
        // Process actions like move, shoot, etc.
        if (player->IsMoving()) {
            player->Move();
        }

        if (player->IsShooting()) {
            player->ShootBulletS();
        }

        // Add sleep to simulate periodic actions
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

Map Game::GetMap() const
{
    return m_map;
}

bool Game::IsPlayerInGame(const std::string& playerName) const
{
        // Access the PlayerManager to check if the player exists by name
        std::shared_ptr<Player> player = m_playerManager->GetPlayer(playerName);

        // Return true if the player exists, false otherwise
        return player != nullptr;
    }

bool Game::IsLastPlayer(const std::string& playerName) const {
    std::shared_ptr<Player> player = m_playerManager->GetPlayer(playerName);
    const auto& allPlayers = m_playerManager->GetAllPlayers();

    // Check if there is only one player, and if it matches the provided player
    if (allPlayers.size() == 1 && allPlayers[0] == player) {
        return true;
    }
    return false;
}

std::shared_ptr<Player> Game::GetPlayer(const std::string& name)
{
    return m_playerManager->GetPlayer(name);
}


void Game::RecordChange(const std::pair<int, int>& newCoord, const std::pair<int, int>& lastCoord, const std::string& type)
{
    m_changedCells.push_back({ newCoord, lastCoord, type });

}

const std::vector<std::tuple<std::pair<int, int>, std::pair<int, int>, std::string>>& Game::GetChangedCells() const
{
    return m_changedCells;
}


//void Game::GetNameLastPlayer()
//{
//    for (const auto& player : m_players) {
//           if (IsLastPlayer(player)) {
//              std::cout << player->GetName() << " is the last player in the game!" << std::endl;
//           }
//    }
//}
