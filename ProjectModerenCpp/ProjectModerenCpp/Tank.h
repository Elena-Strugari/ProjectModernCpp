//#pragma once
//#include <iostream>
//class Tank {
//
//public:
//    enum class ColorTank :uint8_t {
//        Red,
//        Blue,
//        Green,
//        Yellow
//    };
//
//    static ColorTank GetNextColor() {
//        static int colorIndex = 0;
//        ColorTank color = static_cast<ColorTank>(colorIndex);
//        colorIndex = (colorIndex + 1) % 4;
//        return color;
//    }
//
//public:
//    Tank();
//    ColorTank GetColor()const;
//
//    // tank be mutable , not copyable
//    Tank(Tank&&) noexcept = default;
//    Tank& operator=(Tank&&) noexcept = default;
//    Tank(const Tank&) = delete;
//    Tank& operator=(const Tank&) = delete;
//
//    friend std::ostream& operator<<(std::ostream& os, const Tank& tank);
//
//private:
//    ColorTank m_color : 2;    // with one bit (is just for red and blue )
//};