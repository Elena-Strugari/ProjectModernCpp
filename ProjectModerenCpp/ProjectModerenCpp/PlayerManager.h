#pragma once

#include <vector>
#include <memory>
#include "Player.h"

class PlayerManager {
public:
    void AddPlayer(const std::shared_ptr<Player>& player);
    void RemovePlayer(const std::string& name);

    std::shared_ptr<Player> GetPlayer(const std::string& name) const;
    const std::vector<std::shared_ptr<Player>>& GetAllPlayers() const;

    void DisplayAllPlayers() const;

private:
    std::vector<std::shared_ptr<Player>> m_players; 
};
