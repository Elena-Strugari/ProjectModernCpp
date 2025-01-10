#pragma once
#include <cstdint>
#include <iostream>

struct Bomb {

    Bomb(uint16_t x, uint16_t y);

    void explode();
    uint16_t getX()const;
    uint16_t getY()const;
    void setX(const uint16_t& x);
    void setY(const uint16_t& y);

    bool isExploded() const;

    friend std::ostream& operator<<(std::ostream& os, const Bomb& bomb);

       
private:
    uint16_t m_x; 
    uint16_t m_y; 
    bool m_exploded = false; 
};
