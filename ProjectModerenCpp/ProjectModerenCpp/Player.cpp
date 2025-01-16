#include "Player.h"
#include <iostream>

Player::Player():m_name("default_name"), m_score(0), m_lives(3), m_database(m_database), m_alive(true), m_moving(false), m_shooting(false)
{
}

Player::Player(const std::string& name, Database& db)
    : m_name(name), m_score(0), m_lives(3), m_database(db), m_alive(true), m_moving(false), m_shooting(false) {
    if (m_database.ClientExists(m_name)) {
        m_score = m_database.GetScore(m_name);
    }
}

// Move constructor
Player::Player(Player&& other) noexcept
    : m_name(std::move(other.m_name)),
    m_score(other.m_score),
    m_lives(other.m_lives),
    m_database(other.m_database) {}

// Copy constructor
Player::Player(const Player& other)
    : m_name(other.m_name),
    m_score(other.m_score),
    m_lives(other.m_lives),
    m_database(other.m_database) {}

// Move assignment operator
Player& Player::operator=(Player&& other) noexcept {
    if (this != &other) { // Avoid self-assignment
        m_name = std::move(other.m_name);
        m_score = other.m_score;
        m_lives = other.m_lives;
        m_database = other.m_database;
    }
    return *this;
}

// Copy assignment operator
Player& Player::operator=(const Player& other) {
    if (this != &other) { // Avoid self-assignment
        m_name = other.m_name;
        m_score = other.m_score;
        m_lives = other.m_lives;
        m_database = other.m_database;
    }
    return *this;
}

// Destructor
Player::~Player() {}


void Player::AddPlayerObject()
{

    Tank m_tank;
    Bullet m_bullet;
    GameObject object(std::move(m_tank), std::move(m_bullet));
    m_object = std::move(object);
    // m_moveObject = MovementObject(m_object);
    m_moveObject.emplace(m_object);

    std::cout << "GameObject initialized for player " << m_name << "." << std::endl;
}
// void Player::AddPlayerObject(GameObject&& object)
//{
//    
//    m_object = std::move(object);
//   // m_moveObject = MovementObject(m_object);
//    m_moveObject.emplace(m_object);
//
//    std::cout << "GameObject initialized for player " << m_name << "." << std::endl;
//}


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
    if (!m_moveObject.has_value()) {
        throw std::runtime_error("MovementObject is not initialized!");
    }
    return *m_moveObject;
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

void Player::ChooseKeyBindings(int up, int down, int left, int right, int shoot) {
    // Salvează tastele în baza de date
    if (m_database.SaveKeyBindings(m_name, up, down, left, right, shoot)) {
        std::cout << "Key bindings saved for player " << m_name << "." << std::endl;
    }
    else {
        std::cerr << "Failed to save key bindings for player " << m_name << "." << std::endl;
    }
}


bool Player::IsAlive() const {
    return m_alive.load();  // Check if the player is alive
}

bool Player::IsMoving() const {
    return m_moving.load() && m_moveObject.has_value();  // Check if the player is moving
}

bool Player::IsShooting() const {
    return m_shooting.load();  // Check if the player is shooting
}

void Player::Move() {
    if (IsAlive() && m_moveObject.has_value()) {
        // Implement player movement logic here
        // For example, move the player in the direction of the movement object
        m_moveObject->Move(m_currentDirection);
    }
}
void Player::SetDirection(MovementObject::Direction direction) {
    m_currentDirection = direction;
}

void Player::UpdateDirection(MovementObject::Direction direction)
{
    SetDirection(direction); // Set new direction for the player
    Move();
}

void Player::ShootBulletS() {
    if (IsAlive()) {
        // Implement shooting logic here, using the player's game object
        m_object.ShootBullet();
    }
}

void Player::SetMovement(bool moving) {
    m_moving.store(moving);  // Set the player's movement state
}

void Player::SetShooting(bool shooting) {
    m_shooting.store(shooting);  // Set the player's shooting state
}

void Player::SetAlive(bool alive) {
    m_alive.store(alive);  // Set if the player is alive
}

void Player::AddMovementObject(MovementObject&& movement) {
    m_moveObject = std::move(movement);  
}