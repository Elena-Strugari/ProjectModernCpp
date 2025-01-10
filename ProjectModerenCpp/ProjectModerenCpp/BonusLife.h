#pragma once
#include <cstdint>
#include <iostream>

struct BonusLife {

    BonusLife(uint16_t x, uint16_t y);

    void collected();
    uint16_t getX()const;
    uint16_t getY()const;
    void setX(const uint16_t& x);
    void setY(const uint16_t& y);

    bool isCollected() const;

    friend std::ostream& operator<<(std::ostream& os, const BonusLife& BonusLife);


private:
    uint16_t m_x;
    uint16_t m_y;
    bool m_collected = false;
};
