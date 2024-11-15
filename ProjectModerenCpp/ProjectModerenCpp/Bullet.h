#pragma once
#include <iostream>

class Bullet
{
public:
	Bullet()=default;
	
	void Shoot() const {
		std::cout << "pew pew\n";
	}

	friend std::ostream& operator<<(std::ostream& os, const Bullet& bullet);


private:
	//uint8_t m_speed;
	
};

