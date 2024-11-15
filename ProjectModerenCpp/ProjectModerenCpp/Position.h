#pragma once
#include <cstdint>
#include <iostream>
#include"Map.h"
#include<utility>

class Position
{
public:
    Position(uint16_t xVal = 0, uint16_t yVal = 0);
    std::vector<std::pair<uint16_t, uint16_t>> PlayersStartPositions(uint16_t m_width, uint16_t m_height);

    void print() const
    {
        std::cout << "(" << x << ", " << y << ")";
    }
private:
    uint16_t x, y;
};