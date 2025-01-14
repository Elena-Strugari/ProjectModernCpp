#include "PlayerManager.h"
#include <iostream>

PlayerManager::PlayerManager() = default;

void PlayerManager::AddPlayer(const std::shared_ptr<Player>& player) {
    m_players.push_back(player);
}

// Get a player by name
std::shared_ptr<Player> PlayerManager::GetPlayer(const std::string& name) const {
    for (const auto& player : m_players) {
        if (player->GetName() == name) {
            return player;
        }
    }
    return nullptr;
}

void PlayerManager::RemovePlayer(const std::string& name) {
    m_players.erase(
        std::remove_if(m_players.begin(), m_players.end(),
            [&name](const std::shared_ptr<Player>& player) {
                return player->GetName() == name;
            }),
        m_players.end());
}

const std::vector<std::shared_ptr<Player>>& PlayerManager::GetAllPlayers() const {
    return m_players;
}

void PlayerManager::DisplayAllPlayers() const {
    for (const auto& player : m_players) {
        std::cout << "Player Name: " << player->GetName()
            << ", Score: " << player->GetScore()
            << ", Lives: " << player->GetLives() << std::endl;
    }
}

size_t PlayerManager::GetPlayerCount() const {
    return m_players.size();
}
