#include "ServerObject.h"



void ServerObject::AddClient(const std::string& clientId, const std::string& level)
{
    m_clientLevels[clientId] = level;
    auto [x, y, color] = GetTankPositionColor(clientId);

    m_SOtank.SetPosition(x, y);
    m_SOtank.SetColor(color);

    m_tanks[clientId] = std::move(m_SOtank);
}

std::string ServerObject::GetTankPositionString(const std::string& clientId)
{

    auto it = m_tanks.find(clientId);
    if (it != m_tanks.end()) {
        uint16_t x = it->second.GetX();
        uint16_t y = it->second.GetY();

        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
    return "Tank not found";
}

void ServerObject::MoveTank(const std::string& clientId, MoveObject::Direction direction)
{
    auto it = m_tanks.find(clientId);
    if (it != m_tanks.end()) {
        //m_SOtank = it->second; // Referință la obiectul MoveObject
        auto [currentX, currentY] = it->second.GetPosition();

        std::cout << "Pozitie curenta: " << currentX << ", " << currentY << ", culoare: "
            << it->second.GetColor() << std::endl;
        it->second.MoveServer(currentX, currentY, direction);// de revenit aici 

        auto [newX, newY] = it->second.GetPosition();
        std::cout << "Noua pozitie: " << newX << ", " << newY << std::endl;
    }
    else {
        std::cerr << "Tank-ul cu ID-ul " << clientId << " nu exista!\n";
    }
}


std::tuple<uint16_t, uint16_t, Tank::ColorTank> ServerObject::GetTankPositionColor(const std::string& clientId)
{
    auto it = m_tanks.find(clientId);
    if (it != m_tanks.end()) {
        //MoveObject& tank = it->second;
        return std::make_tuple(m_SOtank.GetX(), m_SOtank.GetY(), m_SOtank.GetColor());
    }

    return std::make_tuple(0, 0, Tank::ColorTank::Red);
}


void ServerObject::displayClients()
{
    for (const auto& pair : m_tanks) {
        const std::string& clientId = pair.first;
        const MoveObject& tank = pair.second;

        std::cout << "Client ID: " << clientId
            << ", Poziție: (" << tank.GetX() << ", " << tank.GetY() << ")"
            << ", Culoare: " << static_cast<int>(tank.GetColor()) << std::endl;
    }
}

//void ServerObject::MoveTank(const std::string& clientId, MoveObject::Direction direction)
//{
//    auto it = m_tanks.find(clientId);
//    if (it != m_tanks.end()) {
//       //m_SOtank = it->second; // Referință la obiectul MoveObject
//        auto [currentX, currentY] = it->second.GetPosition(); // Obținem poziția curentă
//
//        std::cout << "Pozitie curenta: " << currentX << ", " << currentY << ", culoare: "
//            << it->second.GetColor() << std::endl;
//        // Mutăm tancul
//        it->second.MoveServer2(currentX, currentY, direction);// de rezolvat aici 
//
//        std::cout << "sunt si aici";
//        auto [newX, newY] = it->second.GetPosition();
//        std::cout << "Noua pozitie: " << newX << ", " << newY << std::endl;
//    }
//    else {
//        std::cerr << "Tank-ul cu ID-ul " << clientId << " nu exista!\n";
//    }
//}

//void ServerObject::AddClient(const std::string& clientId, const std::string& level)
//{
//    // Adăugăm nivelul clientului
//    m_clientLevels[clientId] = level;
//    auto [x, y, color] = GetTankPositionColor(clientId);
//    m_tanks[clientId] = std::make_tuple(x, y, color);
//}
//
//std::string ServerObject::GetTankPositionString(const std::string& clientId)
//{
//    auto it = m_tanks.find(clientId);
//    if (it != m_tanks.end()) {
//        uint16_t x = std::get<0>(it->second);
//        uint16_t y = std::get<1>(it->second);
//
//        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
//    }
//    return "Tank not found";
//}
//std::tuple<uint16_t, uint16_t, Tank::ColorTank> ServerObject::GetTankPositionColor(const std::string& clientId)
//{
//    //std::tuple<uint16_t, uint16_t, Tank::ColorTank> rez= MoveObject::StartPositionColor();
//    std::tuple<uint16_t, uint16_t, Tank::ColorTank> rez= std::make_tuple(0, 0, Tank::ColorTank::Red);
//        uint16_t x = std::get<0>(rez);
//        uint16_t y = std::get<1>(rez);
//        Tank::ColorTank color= std::get<2>(rez);
//
//        return std::make_tuple(x, y,color);
//    
//}
//
//void ServerObject::MoveTank(const std::string& clientId, MoveObject::Direction direction)
//{
//    auto it = m_tanks.find(clientId);
//    if (it != m_tanks.end()) {
//        auto [currentX, currentY, currentColor] = it->second;
//
//
//        std::cout << "current direct" << currentX << " " << currentY << " " << currentColor << std::endl;
//
//        
//        // Cream un obiect MoveObject temporar
//    //    MoveObject tempTank;
//    //    tempTank.SetPosition(currentX, currentY);
//    //    tempTank.SetColor(currentColor);
//
//    //    // Apelăm MoveServer pe obiectul temporar
//    //    auto [newX, newY, newColor] = tempTank.MoveServer(direction);
//    //    std::cout << "dupa direct" << newX << " " << newY << " " << newColor << std::endl;
//
//    //    if(abs(newX- currentX)==1 || abs(newY- currentY)==1)
//    //        it->second = std::make_tuple(newX, newY, newColor);
//
//    //    std::cout << "Tankul " << clientId << " s-a mutat la ("
//    //        << newX << ", " << newY << ") cu culoarea "
//    //        << static_cast<int>(newColor) << ".\n";
//
//    //    /*if (tempTank.IsValidPos(newX, newY))
//    //    {
//    //        std::cout << "sunt in if";
//    //        it->second = std::make_tuple(newX, newY, newColor);
//
//    //        std::cout << "Tankul " << clientId << " s-a mutat la ("
//    //            << newX << ", " << newY << ") cu culoarea "
//    //            << static_cast<int>(newColor) << ".\n";
//    //    }
//    //   */
//    //    
//    //}
//    //else {
//    //    std::cerr << "Tank-ul cu ID-ul " << clientId << " nu există!\n";
//    //    //// Apelează MoveServer pe obiectul `MoveObject` din mapa `m_tanks`
//    //    //std::tuple<uint16_t, uint16_t, Tank::ColorTank> rez
//    //    //auto [newX, newY, color] = MoveObject::MoveServer(direction);  // Deconstruim tuple-ul
//
//    //    //// Actualizăm poziția și culoarea în obiectul `MoveObject`
//    //    //it->second.SetPosition(newX, newY);  // Setează noile coordonate
//    //    //it->second.SetColor(color);  // Setează culoarea, dacă este necesar
//    //}
//}
//
//bool ServerObject::clientExists(const std::string& clientId)
//{
//    return m_tanks.find(clientId) != m_tanks.end();
//}
//
//void ServerObject::displayClients()
//{
//    for (const auto& pair : m_tanks) {
//        std::cout << "Client ID: " << pair.first << ", Poziție: " <<std::get<0>( GetTankPositionColor(pair.first))<< std::get<1>(GetTankPositionColor(pair.first)) << std::endl;
//    }
//}
