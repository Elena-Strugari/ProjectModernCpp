#include "Player.h"
#include <iostream>

Player::Player(const std::string& name, Database& db, GameObject&& object)
    : m_name(name), m_score(0), m_lives(3), m_database(db), m_object(std::move(object)), m_moveObject(m_object) {
    if (!m_database.ClientExists(m_name)) {
        m_database.AddClient(m_name, m_score);
    }
    else {
        m_score = m_database.GetScore(m_name);
    }
}

bool Player::ExistPlayer(const std::string& name, Database& db) const
{
    if (m_database.ClientExists(name))
        return true;
    return false;
}

const std::string& Player::GetName() const {
    return m_name;
}

int Player::GetLives() const {
    return m_lives;
}

int Player::GetScore() const {
    return m_score;
}

GameObject& Player::GetObject()
{
    return m_object;
}

MovementObject& Player::GetMovementObject()
{
    return m_moveObject;
}

void Player::LoseLife() {
    if (m_lives > 0) {
        m_lives--;
    }
    else {
        m_hasLife = false;
    }
}

void Player::GainLife() {
    m_lives++;
}

bool Player::HasLife() const
{
    return m_hasLife;
}


void Player::SaveState() {
    m_database.UpdateScore(m_name, m_score);
}

void Player::AddScore(int points)
{
    m_score += points;
}

void Player::ChooseKeyBindings(const std::string& up, const std::string& down, const std::string& left, const std::string& right) {
    // Salvează tastele în baza de date
    if (m_database.SaveKeyBindings(m_name, up, down, left, right)) {
        std::cout << "Key bindings saved for player " << m_name << "." << std::endl;
    }
    else {
        std::cerr << "Failed to save key bindings for player " << m_name << "." << std::endl;
    }
}
