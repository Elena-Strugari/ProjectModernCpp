//#include "GameManager.h"
//
//bool GameManager::GameExists(const std::string& gameCode)
//{
//     return m_games.find(gameCode) != m_games.end();
//}
//
//void GameManager::AddGame(const std::string& gameCode, const Game& game)
//{
//    m_games[gameCode] = game;
//}
//
//Game& GameManager::GetGame(const std::string& gameCode)
//{
//    if (m_games.find(gameCode) == m_games.end()) {
//        throw std::runtime_error("Game not found");
//    }
//    return m_games[gameCode];
//}
