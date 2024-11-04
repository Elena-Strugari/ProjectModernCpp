#pragma once
#include <cstdint>
#include <iostream>

struct Position
{
	uint16_t x, y;
    Position(uint16_t xVal = 0, uint16_t yVal = 0)
        : x(xVal)
        , y(yVal) 
    {
        //EMPTY
    }

    void print() const
    {
        std::cout << "(" << x << ", " << y << ")";
    }
};