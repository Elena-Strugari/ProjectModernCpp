﻿#pragma once
#include <string>
#include <optional>
#include "Database.h"
#include "MovementObject.h"

class Player {
public:
    //Player(const std::string& name, Database& db , GameObject&& object);
    Player(const std::string& name, Database& db);
    void AddPlayerObject(GameObject&& object);
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
    bool m_hasLife=true;
    Database& m_database;

    GameObject m_object;
    std::optional<MovementObject> m_moveObject;
    bool m_objectInitialized = false;

};
