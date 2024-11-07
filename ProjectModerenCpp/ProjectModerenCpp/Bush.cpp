#include "Bush.h"
#include"Tank.h"
#include<thread>
#include<chrono>
void Bush::GoThrough(Tank &player_tank)
{
	float InitialSpeed = player_tank.GetSpeed(); //  nu ma ajuta o functide de get pentru ca eu trebuie sa modific viteza (care e private)
	/*
	 variable = newValue;
    std::cout << "Valoare temporară: " << variable << std::endl;

    // Creează un thread care așteaptă perioada specificată și apoi revine la valoarea inițială
    std::thread([&variable, initialValue, duration]() {
        std::this_thread::sleep_for(duration);
        variable = initialValue;
        std::cout << "Valoare restaurată: " << variable << std::endl;
    }).detach();

    cod de pe chatgbt; doar ca sintaxa; trebuie adaptat
	*/
}
