#include "Player.h"

Player::Player(const std::string& name, uint16_t lives)
    :m_userName(name), m_lives(lives), m_tank(nullptr) {}

void Player::AssignTank(std::shared_ptr<Tank> tank)
{
    m_tank = tank;
}

void Player::LoseLife()
{
    if (m_lives > 0) {
        --m_lives;
        std::cout << m_userName << " a pierdut o viata! Vieti ramase: " << m_lives << std::endl;
    }
    else {
        std::cout << m_userName << " nu mai are vieti!\n";
    }
}

void Player::GainLife()
{
    ++m_lives;
    std::cout << m_userName << " a castigat o viata! Vieti: " << m_lives << std::endl;

}

uint16_t Player::GetLives() const
{
    return m_lives;
}

