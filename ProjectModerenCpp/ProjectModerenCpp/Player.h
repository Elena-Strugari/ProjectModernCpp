#pragma once
#include <string>
#include "Database.h"
#include "MovementObject.h"

class Player {
public:
    Player(const std::string& name, Database& db , GameObject&& object);
    bool ExistPlayer(const std::string& name, Database& db)const;
    // Getters
    const std::string& GetName() const;
    int GetLives() const;
    int GetScore() const;
    GameObject& GetObject();
    MovementObject& GetMovementObject();
    // Lives management
    void LoseLife();
    void GainLife();
    bool HasLife()const;

    // Save state to database
    void SaveState();
    void AddScore(int points);
    void ChooseKeyBindings(const std::string& up, const std::string& down, const std::string& left, const std::string& right);


private:
    std::string m_name;
    int m_score;
    int m_lives;
    Database& m_database;
    bool m_hasLife=true;
    GameObject m_object;
    MovementObject m_moveObject;
};
