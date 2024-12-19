#pragma once
#include <string>
#include "Database.h"

class Player {
public:
    Player(const std::string& name, Database& db, bool isRegistering);
    // Getters
    const std::string& getName() const;
    int getLives() const;
    int getScore() const;


    // Lives management
    void loseLife();
    void gainLife();

    // Save state to database
    void saveState();

    void chooseKeyBindings(const std::string& up, const std::string& down, const std::string& left, const std::string& right);


private:
    std::string name;   // Numele jucătorului
    int lives;          // Numărul de vieți
    int score;
    Database& database; // Referință la baza de date pentru salvarea stării
};
