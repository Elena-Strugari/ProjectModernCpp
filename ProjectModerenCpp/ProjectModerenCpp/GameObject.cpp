#include "GameObject.h"


void GameObject::ShootBullet()
{
    std::cout << "Apasa 'b' pentru a trage ('q' pentru a iesi)...\n";

    char key;
    while (true) {
        if (_kbhit()) { // Detectează apăsări de taste
            key = _getch(); // Citește tasta apăsată

            if (key == 'q') { // Ieșire
                std::cout << "Iesire din joc.\n";
                break;
            }

            if (key == 'b') { // Tasta 'b' pentru Shoot
                m_GOBullet.Shoot();
            }
        }
    }
}

GameObject::GameObject(Tank::ColorTank tank)
	:m_GOTank(tank)
{

}

std::ostream& operator<<(std::ostream& os, const GameObject& go)
{
	os << "GameObject: " << go.m_GOTank << " and Bullet: " << go.m_GOBullet;
	return os;
}
