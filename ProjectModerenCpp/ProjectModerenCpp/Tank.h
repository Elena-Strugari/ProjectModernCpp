#pragma once
#include <cstdint>


class Tank {   

public:
    enum class ColorTank:uint8_t {
        Red, 
        Blue, 
        Green, 
        Yellow
    };

public:
   
    Tank(ColorTank color);

    ColorTank GetColor()const;
   



private:
    ColorTank m_color : 1;
    
};
