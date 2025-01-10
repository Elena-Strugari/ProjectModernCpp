#pragma once
#include <cstdint>
#include <iostream>
#include <vector>
#include <variant>
#include <tuple>
#include <stdexcept>
#include "Wall.h"

class Map {
public:
    struct Empty {};
    struct Bomb {};
    struct BonusLife {};
    struct Tank {}; // Placeholder, can be replaced with an actual Tank class

    using CellContent = std::variant<Empty, Bomb, BonusLife, Wall::TypeWall, Tank>;

    struct Cell {
        CellContent content; // Stores the content of the cell
        uint16_t border;

        Cell() : content(Empty{}), border(0) {} // Default to an empty cell

        Cell(CellContent content, uint16_t border)
            : content(std::move(content)), border(border) {}
    };

public:
    explicit Map(uint8_t level);

    // Getters
    uint16_t GetWidth() const;
    uint16_t GetHeight() const;
    const Cell& GetCell(uint16_t x, uint16_t y) const;

    // Setters
    void SetCell(uint16_t x, uint16_t y, const Cell& value);
    void SetCellContent(uint16_t x, uint16_t y, CellContent content);

    // Validation
    bool IsValidPosition(uint16_t x, uint16_t y) const;

    // Display
    void DisplayMap() const;

    // Add specific elements
    void PlaceBomb(uint16_t x, uint16_t y);
    void PlaceBonusLife(uint16_t x, uint16_t y);
    void PlaceTank(uint16_t x, uint16_t y, const Tank& tank);

private:
    uint16_t m_width;
    uint16_t m_height;
    std::vector<std::vector<Cell>> m_map;

    std::tuple<uint16_t, uint16_t, uint16_t, uint16_t> GetLevelBounds(uint8_t level) const;
    std::pair<uint16_t, uint16_t> FindValidPosition();

    void InitializeGameElements(uint8_t numBombs, uint8_t numBonusLives);
    void GenerateWalls(uint8_t level);
};
