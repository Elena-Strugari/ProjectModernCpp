////export module Tank;
//export module Tank;
//import <iostream>;  // Required for std::ostream
//
//export class Tank {
//public:
//    enum class ColorTank : uint8_t {
//        Red,
//        Blue,
//        Green,
//        Yellow
//    };
//
//    // Static method to get the next tank color in a round-robin manner
//    static ColorTank GetNextColor() {
//        static int colorIndex = 0;
//        ColorTank color = static_cast<ColorTank>(colorIndex);
//        colorIndex = (colorIndex + 1) % 4;
//        return color;
//    }
//
//    // Constructors
//    Tank();
//    ColorTank GetColor() const;
//
//    // Disable copying, allow moving
//    Tank(Tank&&) noexcept = default;
//    Tank& operator=(Tank&&) noexcept = default;
//    Tank(const Tank&) = delete;
//    Tank& operator=(const Tank&) = delete;
//
//    // Friend function for stream output
//    friend std::ostream& operator<<(std::ostream& os, const Tank& tank);
//
//private:
//    ColorTank m_color : 2;  // Using bit field (2 bits) to store the color
//};
//
//// Implementation
//
//Tank::Tank() : m_color(GetNextColor()) {}
//
//Tank::ColorTank Tank::GetColor() const {
//    return m_color;
//}
//
//std::ostream& operator<<(std::ostream& os, const Tank& tank) {
//    switch (tank.GetColor()) {
//    case Tank::ColorTank::Red:    os << "R"; break;
//    case Tank::ColorTank::Blue:   os << "B"; break;
//    case Tank::ColorTank::Green:  os << "G"; break;
//    case Tank::ColorTank::Yellow: os << "Y"; break;
//    }
//    return os;
//}