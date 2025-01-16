#pragma once
#include <string>
#include <optional>
#include "Database.h"
#include "MovementObject.h"

class Player {
public:
   
    Player();
    Player(const std::string& name, Database& db);
    Player(Player&& other) noexcept;         // Move constructor
    Player(const Player& other);             // Copy constructor
    ~Player();                               // Destructor

    // Assignment operators
    Player& operator=(Player&& other) noexcept; // Move assignment operator
    Player& operator=(const Player& other);     // Copy assignment operator


    //void AddPlayerObject(GameObject&& object);
    void AddPlayerObject();
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
    void ChooseKeyBindings(const std::string& up, const std::string& down, const std::string& left, const std::string& right, const std::string& shoot);


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
