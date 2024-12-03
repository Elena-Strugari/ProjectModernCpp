#pragma once
//ma gandesc ca va fi aici baza de date conectata si 
#include <unordered_map>
#include <iostream>
#include <string>


#include "MoveObject.h"


class ServerObject
{

public:

    //ServerObject() {
    //    // Adăugăm clienți simulați la server
    //    AddClient("client1", "Usor");  // Clientul 1, pe nivelul 1, la poziția (0, 0)
    //    AddClient("client2", "Mediu");  // Clientul 2, pe nivelul 2, la poziția (5, 5)
    //    AddClient("client3", "Greu"); // Clientul 3, pe nivelul 3, la poziția (10, 10)
    //}


    std::string GetTankPositionString(const std::string& clientId);
    std::tuple<uint16_t, uint16_t, Tank::ColorTank> GetTankPositionColor(const std::string& clientId);

    void AddClient(const std::string& clientId, const std::string& level);
    void MoveTank(const std::string& clientId, MoveObject::Direction direction);
    bool clientExists(const std::string& clientId);


    //display
    void displayClients();

protected:
    std::unordered_map<std::string, std::string> m_clientLevels;  // Mapează ID-ul clientului la nivelul ales
    //std::unordered_map<std::string, std::tuple<uint16_t, uint16_t, Tank::ColorTank>> m_tanks;
    std::unordered_map<std::string, MoveObject> m_tanks;
private:
    MoveObject m_SOtank;
};

