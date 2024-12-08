#pragma once
#include <string>
#include <memory>

#include "GameObject.h"

class Player
{
public:
	Player(const std::string& name, uint16_t lives);

	void AssignTank(std::shared_ptr<Tank> tank);
	void LoseLife();
	void GainLife();

	uint16_t GetLives()const;


private:
	std::string m_userName;
	uint16_t m_lives;
	std::shared_ptr<Tank> m_tank;// pointer catre tancul jucatorului 
};

