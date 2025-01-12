#include "Map.h"
#include <cstdlib>
#include <ctime>

// Constructor
Map::Map(uint8_t level) {
    auto [minWidth, maxWidth, numBombs, numBonusLives] = GetLevelBounds(level);

    std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed the random generator

    m_width = minWidth + std::rand() % (maxWidth - minWidth + 1);
    m_height = minWidth + std::rand() % (maxWidth - minWidth + 1);

    // Resize the map and initialize each cell
    m_map.resize(m_height, std::vector<Cell>(m_width));

    for (uint16_t y = 0; y < m_height; ++y) {
        for (uint16_t x = 0; x < m_width; ++x) {
            if (y == 0 || y == m_height - 1 || x == 0 || x == m_width - 1) {
                m_map[y][x] = { Wall::TypeWall::indestructible, 1 }; // Borders
            }
            else {
                m_map[y][x] = { Empty{}, 0 }; // Inner cells start as empty
            }
        }
    }

    GenerateWalls(level);
    InitializeGameElements(numBombs, numBonusLives);

}

// Getters
uint16_t Map::GetWidth() const { return m_width; }
uint16_t Map::GetHeight() const { return m_height; }
const std::vector<std::vector<Map::Cell>>& Map::GetMap() const {
    return m_map;
}

const Map::Cell& Map::GetCell(uint16_t x, uint16_t y) const {
    if (!IsValidPosition(x, y)) {
        throw std::out_of_range("Invalid position on the map!");
    }
    return m_map[y][x];
}

// Setters
void Map::SetCell(uint16_t x, uint16_t y, const Cell& value) {
    if (!IsValidPosition(x, y)) {
        throw std::out_of_range("Invalid position on the map!");
    }
    m_map[y][x] = value;
}

void Map::SetCellContent(uint16_t x, uint16_t y, CellContent content) {
    if (!IsValidPosition(x, y)) {
        throw std::out_of_range("Invalid position on the map!");
    }
    m_map[y][x].content = content;
}

// Validation
bool Map::IsValidPosition(uint16_t x, uint16_t y) const {
    return x < m_width && y < m_height; // Ensures the coordinates are within bounds
}

std::pair<uint16_t, uint16_t> Map::FindValidPosition() {
    uint16_t x, y;
    auto isCorner = [this](uint16_t x, uint16_t y) {
        return (x == 1 && y == 1) ||                                    
            (x == 1 && y == m_width - 2) ||                          
            (x == m_height - 2 && y == 1) ||                         
            (x == m_height - 2 && y == m_width - 2);                 
        };

    do {
        x = std::rand() % m_width;
        y = std::rand() % m_height;
    } while (!IsValidPosition(x, y) || !std::holds_alternative<Empty>(m_map[y][x].content) || isCorner(x, y));

    return { x, y };
}

// Display
void Map::DisplayMap() const {
    for (const auto& row : m_map) {
        for (const auto& cell : row) {
            std::visit([](const auto& content) {
                using T = std::decay_t<decltype(content)>;
                if constexpr (std::is_same_v<T, Empty>) {
                    std::cout << "_";
                }
                else if constexpr (std::is_same_v<T, Bomb>) {
                    std::cout << "B";
                }
                else if constexpr (std::is_same_v<T, BonusLife>) {
                    std::cout << "L";
                }
                else if constexpr (std::is_same_v<T, Wall::TypeWall>) {
                    std::cout << (content == Wall::TypeWall::destructible ? '@' : '#');
                }
                else if constexpr (std::is_same_v<T, Tank>) {
                    std::cout << "T";
                }
                else if constexpr (std::is_same_v<T, Bullet>) {
                    std::cout << "->";
                }
                }, cell.content);
        }
        std::cout << '\n';
    }
}

// Game Element Initialization
void Map::InitializeGameElements(uint8_t numBombs, uint8_t numBonusLives) {
    for (uint8_t i = 0; i < numBombs; ++i) {
        auto [x, y] = FindValidPosition();
        SetCellContent(x, y, Bomb{});
    }

    for (uint8_t i = 0; i < numBonusLives; ++i) {
        auto [x, y] = FindValidPosition();
        SetCellContent(x, y, BonusLife{});
    }
}

// Wall Generation
//void Map::GenerateWalls(uint8_t level) {
//    // Example: Add destructible walls randomly
//    for (uint16_t i = 0; i < level * 10; ++i) {
//        auto [x, y] = FindValidPosition();
//        SetCellContent(x, y, Wall::TypeWall::destructible);
//    }
//}

// Level Bounds
std::tuple<uint16_t, uint16_t, uint16_t, uint16_t> Map::GetLevelBounds(uint8_t level) const {
    switch (level) {
    case 1: return { 15, 20, 1, 1 }; // Width range and game elements for level 1
    case 2: return { 20, 25, 2, 2 }; // Level 2
    case 3: return { 25, 30, 3, 3 }; // Level 3
    default:
        throw std::invalid_argument("Invalid level! Levels must be 1, 2, or 3.");
    }
}

// Placing Game Elements
void Map::PlaceBomb(uint16_t x, uint16_t y) { SetCellContent(x, y, Bomb{}); }
void Map::PlaceBonusLife(uint16_t x, uint16_t y) { SetCellContent(x, y, BonusLife{}); }
void Map::PlaceTank(uint16_t x, uint16_t y, const Tank& tank) { SetCellContent(x, y, tank); }




void Map::GenerateWalls(uint8_t level) {
    uint16_t height = GetHeight();
    uint16_t width = GetWidth();

    // Predefined wall positions for each level
    std::vector<std::pair<uint16_t, uint16_t>> predefinedIndestructibleWalls;
    std::vector<std::pair<uint16_t, uint16_t>> predefinedDestructibleWalls;

    switch (level) {
    case 1:
        predefinedIndestructibleWalls = {
            {0, 6}, {1, 6}, {1, 7}, {3, 8}, {4, 0}, {4, 1}, {4, 8},
            {5, 2}, {5, 8}, {5, 9}, {5, 10}, {5, 14}, {6, 6}, {6, 14},
            {7, 5}, {7, 6}, {7, 7}, {10, 0}, {10, 1}, {10, 2}, {10, 3},
            {10, 11}, {10, 12}, {12, 5}, {12, 9}, {12, 10}, {12, 11},
            {12, 12}, {13, 5}, {13, 12}, {14, 5}
        };
        predefinedDestructibleWalls = {
            {2, 2}, {2, 6}, {2, 9}, {6, 9}, {8, 8}, {11, 4}, {11, 9},
            {13, 7}, {14, 10}
        };
        break;
    case 2:
        predefinedIndestructibleWalls = {
            {2, 1}, {2, 2}, {2, 3}, {0, 7}, {0, 8}, {0, 9}, {1, 8}, {2, 8},
            {3, 8}, {4, 12}, {1, 16}, {2, 16}, {6, 6}, {6, 7}, {6, 8},
            {6, 9}, {7, 13}, {8, 13}, {9, 13}
        };
        predefinedDestructibleWalls = {
            {3, 7}, {3, 10}, {7, 10}, {8, 9}, {9, 8}, {10, 8}, {12, 8}
        };
        break;
    case 3:
        predefinedIndestructibleWalls = {
            {0, 2}, {0, 3}, {0, 4}, {2, 9}, {2, 10}, {2, 19}, {2, 20},
            {2, 21}, {3, 9}, {3, 10}, {4, 11}, {4, 12}, {5, 24}, {6, 24},
            {7, 24}, {8, 3}, {8, 4}, {9, 4}, {10, 4}
        };
        predefinedDestructibleWalls = {
            {6, 10}, {7, 9}, {8, 8}, {9, 7}, {10, 6}, {11, 5}, {12, 4}
        };
        break;
    default:
        throw std::invalid_argument("Invalid level!");
    }

    // Place predefined walls on the map
    for (const auto& pos : predefinedIndestructibleWalls) {
        SetCellContent(pos.first, pos.second, Wall::TypeWall::indestructible);
    }
    for (const auto& pos : predefinedDestructibleWalls) {
        SetCellContent(pos.first, pos.second, Wall::TypeWall::destructible);
    }

    // Optionally, add random walls for additional variety
    int additionalRandomWalls = 10; // Adjust as needed
    for (int i = 0; i < additionalRandomWalls; ++i) {
        auto [x, y] = FindValidPosition();
        SetCellContent(x, y, Wall::TypeWall::destructible);
    }
}
