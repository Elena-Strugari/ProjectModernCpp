#include "Player.h"
#include <iostream>

Player::Player(const std::string& name, Database& db, bool isRegistering) : name(name), lives(3),score(0) database(db) {
    if (isRegistering) {
        // Înregistrare: Verifică dacă numele există deja
        if (database.clientExists(name)) {
            throw std::runtime_error("Error: The username '" + name + "' is already taken.");
        }
        // Adaugă jucătorul în baza de date cu scorul inițial 0
        database.addClient(name, 0);
    }
    else {
        // Logare: Verifică dacă jucătorul există în baza de date
        if (!database.clientExists(name)) {
            throw std::runtime_error("Error: The username '" + name + "' does not exist. Please register first.");
        }
    }
}

const std::string& Player::getName() const {
    return name;
}

int Player::getLives() const {
    return lives;
}

void Player::loseLife() {
    if (lives > 0) {
        lives--;
        std::cout << "Player " << name << " lost a life. Remaining lives: " << lives << std::endl;
    }
    else {
        std::cout << "Player " << name << " has no lives left." << std::endl;
    }
}

void Player::gainLife() {
    lives++;
    std::cout << "Player " << name << " gained a life. Total lives: " << lives << std::endl;
}

void Player::saveState() {
    // Salvăm numărul de vieți și orice alte informații relevante
    database.updateScore(name, lives);
    std::cout << "Player " << name << " state saved to database." << std::endl;
}
