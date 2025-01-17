#pragma once
#include <string>
#include <optional>
#include "Database.h"
#include "MovementObject.h"
#include <atomic>


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
    void ChooseKeyBindings(int up, int down,int left, int right, int shoot);


    bool IsAlive() const;  // Check if the player is alive
    bool IsMoving() const; // Check if the player is moving
    bool IsShooting() const;  // Check if the player is shooting

    void Move();  // Move the player
    void ShootBulletS();  // Handle the shooting action

    void SetMovement(bool moving);  // Set the player's movement state
    void SetShooting(bool shooting);  // Set the player's shooting state
    void SetAlive(bool alive);
    void AddMovementObject(MovementObject&& movement);
    MovementObject::Direction m_currentDirection;
    //void Move();
    void SetDirection(MovementObject::Direction direction);
    void UpdateDirection(MovementObject::Direction direction);
private:
    std::string m_name;
    int m_score;
    int m_lives;
    bool m_hasLife=true;
    Database& m_database;

    GameObject m_object;
    //MovementObject m_moveObject;
   std::optional<MovementObject> m_moveObject;
    //bool m_objectInitialized = false;

    std::atomic<bool> m_alive;
    std::atomic<bool> m_moving;
    std::atomic<bool> m_shooting;

};
