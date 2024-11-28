#pragma once
#include <iostream>

class Bullet
{
public:
	Bullet() = default;

	std::string Shoot() const {
		return "pew pew";
	}

	friend std::ostream& operator<<(std::ostream& os, const Bullet& bullet);


private:
	//uint8_t m_speed;

};