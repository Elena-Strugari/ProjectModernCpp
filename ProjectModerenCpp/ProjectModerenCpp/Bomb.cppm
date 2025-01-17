export module Bomb;

import <cstdint>;    // For uint16_t
import <iostream>;   // For std::ostream

export struct Bomb {
    // Constructor
    Bomb(uint16_t x, uint16_t y);

    // Methods
    void explode();
    uint16_t getX() const;
    uint16_t getY() const;
    void setX(const uint16_t& x);
    void setY(const uint16_t& y);

    bool isExploded() const;

    // Friend function for stream output
    friend std::ostream& operator<<(std::ostream& os, const Bomb& bomb);

private:
    uint16_t m_x;
    uint16_t m_y;
    bool m_exploded = false;
};

// Implementation

// Constructor
Bomb::Bomb(uint16_t x, uint16_t y)
    : m_x(x), m_y(y) {
}

// Getter methods
uint16_t Bomb::getX() const {
    return m_x;
}

uint16_t Bomb::getY() const {
    return m_y;
}

// Setter methods
void Bomb::setX(const uint16_t& x) {
    m_x = x;
}

void Bomb::setY(const uint16_t& y) {
    m_y = y;
}

// Explode the bomb
void Bomb::explode() {
    if (!m_exploded) {
        m_exploded = true;
    }
}

// Check if the bomb has exploded
bool Bomb::isExploded() const {
    return m_exploded;
}

// Stream output operator
std::ostream& operator<<(std::ostream& os, const Bomb& bomb) {
    os << "Bomb [Position: (" << bomb.m_x << ", " << bomb.m_y << "), State: ";
    os << (bomb.m_exploded ? "Exploded" : "Not Exploded") << "]";
    return os;
}