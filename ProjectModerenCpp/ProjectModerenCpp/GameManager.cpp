#include "GameManager.h"
#include <unordered_map>  // Ensure this is included

std::unordered_map<std::string, Game> GameManager::m_games;  

bool GameManager::GameExists(const std::string& gameCode) {
    return m_games.find(gameCode) != m_games.end();  // Check if gameCode exists in the map
}

void GameManager::AddGame(const std::string& gameCode, const Game& game) {
    m_games[gameCode] = game;  // Add game to the map with the gameCode as the key
}

Game& GameManager::GetGame(const std::string& gameCode) {
    auto it = m_games.find(gameCode);  // Find the game by its code
    if (it == m_games.end()) {
        throw std::runtime_error("Game not found");
    }
    return it->second;  // Return the game associated with the gameCode
}
