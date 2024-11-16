#include "Position.h"
#include"utility"
#include<vector>

Position::Position(uint16_t xVal, uint16_t yVal): x(xVal), y(yVal){}

std::vector<std::pair<uint16_t, uint16_t>> Position::PlayersStartPositions(uint16_t m_width, uint16_t m_height)
{
    std::vector<std::pair<uint16_t, uint16_t>> startPositions;
    startPositions.push_back(std::make_pair(1, 1));
    startPositions.push_back(std::make_pair(1, m_height-2));
    startPositions.push_back(std::make_pair(m_width-2, 1));
    startPositions.push_back(std::make_pair(m_width-2, m_height-2));

    return startPositions;
}

void Position::print() const
{
    std::cout << "(" << x << ", " << y << ")";
}
