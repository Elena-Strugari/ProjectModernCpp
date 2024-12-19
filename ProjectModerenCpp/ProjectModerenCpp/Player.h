#pragma once
#include <string>
#include "Database.h"

class Player {
public:
    Player(const std::string& name, Database& db, bool isRegistering);
    // Getters
    const std::string& getName() const;
    int getLives() const;

    // Lives management
    void loseLife();
    void gainLife();

    // Save state to database
    void saveState();

private:
    std::string name;   // Numele jucătorului
    int lives;          // Numărul de vieți
    int score;
    Database& database; // Referință la baza de date pentru salvarea stării
};
