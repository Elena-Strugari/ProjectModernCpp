#pragma once
#include <cstdint>



class GameObject
{
public:
	virtual void update() = 0;
	//virtual void render() = 0; //- for GUI


protected:
	uint8_t m_x, m_y;
	uint16_t m_width, m_height; 

};

