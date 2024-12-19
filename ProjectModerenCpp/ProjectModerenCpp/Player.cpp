#include "Player.h"
#include <iostream>

Player::Player(const std::string& name, Database& db, bool isRegistering) : name(name), lives(3), score(0), database(db) {
    if (isRegistering) {
        // Înregistrare: Verifică dacă numele există deja
        if (database.clientExists(name)) {
            throw std::runtime_error("Error: The username '" + name + "' is already taken.");
        }
        // Adaugă jucătorul în baza de date cu scorul inițial 0
        database.addClient(name, score);
    }
    else {
        // Logare: Verifică dacă jucătorul există în baza de date
        if (!database.clientExists(name)) {
            throw std::runtime_error("Error: The username '" + name + "' does not exist. Please register first.");
        }
        // Preia scorul din baza de date
        score = database.getScore(name);
    }
}

const std::string& Player::getName() const {
    return name;
}

int Player::getLives() const {
    return lives;
}

int Player::getScore() const {
    return score;
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
    // Salvăm scorul și alte informații relevante în baza de date
    int currentScore = database.getScore(name);
    database.updateScore(name, currentScore + score);   
    std::cout << "Player " << name << " state saved to database." << std::endl;
}

void Player::chooseKeyBindings(const std::string& up, const std::string& down, const std::string& left, const std::string& right) {
    // Salvează tastele în baza de date
    if (database.saveKeyBindings(name, up, down, left, right)) {
        std::cout << "Key bindings saved for player " << name << "." << std::endl;
    }
    else {
        std::cerr << "Failed to save key bindings for player " << name << "." << std::endl;
    }
}
