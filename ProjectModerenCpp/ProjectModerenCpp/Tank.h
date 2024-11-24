//client
#pragma once
//#include <cstdint>
//import std;
#include <iostream>

class Tank {   

public:
    enum class ColorTank:uint8_t {
        Red, 
        Blue, 
        Green, 
        Yellow
    };

public:
    Tank();
    Tank(ColorTank color);
    ColorTank GetColor()const;
   
    // tank be mutable , not copyable
    Tank(Tank&&) noexcept = default;            //def contructor mutable
    Tank& operator=(Tank&&) noexcept = default;    //moving from one tank to another tank without copying
    Tank(const Tank&) = delete;                     // delete copy constructor
    Tank& operator=(const Tank&) = delete;          // delete op = copy constructor

     friend std::ostream& operator<<(std::ostream& os, const Tank& tank);

private:
    ColorTank m_color : 2;    // with one bit (is just for red and blue )
};
