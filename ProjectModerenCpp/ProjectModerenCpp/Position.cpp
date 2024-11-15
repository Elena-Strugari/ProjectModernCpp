#include "Position.h"
#include"utility"
#include<vector>
std::vector<std::pair<uint16_t, uint16_t>> Position::PlayersStartPositions(uint16_t m_width, uint16_t m_height)
{
    std::vector<std::pair<uint16_t, uint16_t>> startPositions;
    startPositions.push_back(std::make_pair(0, 0));
    startPositions.push_back(std::make_pair(0, m_height-1));
    startPositions.push_back(std::make_pair(m_width-1, 0));
    startPositions.push_back(std::make_pair(m_width-1, m_height-1));

    return startPositions;
}
