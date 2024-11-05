#pragma once

#include <cstdint>
// #include "Tank.h"
class Player
{
public:
	Player(uint8_t x, uint8_t y);
	void updateScore(int points);
	void loseLife();
	bool isGameOver();

private:
	uint8_t m_score;
protected:
	uint8_t lives;
};

