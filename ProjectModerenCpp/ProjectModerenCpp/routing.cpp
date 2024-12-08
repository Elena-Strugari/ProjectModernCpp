#include "routing.h"
using namespace http;

void http::Routing::Run()
{
    CROW_ROUTE(m_app, "/incerc")([]() {
        return "sunt aici ";
        });

    //std::unordered_map<std::string, std::string> clientLevels;
    //std::mutex clientLevelsMutex;


    CROW_ROUTE(m_app, "/choose_level").methods(crow::HTTPMethod::POST)([&](const crow::request& req) {
        try {
            std::string levelType = req.body;
            if (levelType.empty()) {
                return crow::response(400, "Server:Bad request: missing level type");
            }

            std::string clientId = req.get_header_value("Client-ID");
            if (clientId.empty()) {
                return crow::response(400, "Server:Bad request: missing client ID");
            }

            std::cout << "Nivel ales pentru Client-ID " << clientId << ": " << levelType << std::endl;
            AddClient(clientId, levelType);
            std::cout << "Nivel ales pentru Client-ID " << clientId << ": " << levelType << std::endl;

            return crow::response(200, "Server:Nivel ales: " + levelType);
        }
        catch (const std::exception& e) {
            return crow::response(500, "Server:Internal server error: " + std::string(e.what()));
        }
        });

    CROW_ROUTE(m_app, "/get_map").methods(crow::HTTPMethod::GET)([&](const crow::request& req) {
        try {
            std::string clientId = req.get_header_value("Client-ID");
            if (clientId.empty()) {
                return crow::response(400, "Server: Missing Client-ID");
            }

            std::string levelType;
            {
                //std::lock_guard<std::mutex> lock(clientLevelsMutex);
                if (m_clientLevels.find(clientId) == m_clientLevels.end()) {
                    return crow::response(400, "Server: Client ID invalid sau nu s-a ales un nivel");
                }
                levelType = m_clientLevels[clientId];
            }

            std::cout << "Client-ID " << clientId << " solicită nivelul: " << levelType << std::endl;

            Map map(1);  // Nivel default
            if (levelType == "Usor") {
                map = Map(1);
                map.GenerateWalls(1);
            }
            else if (levelType == "Mediu") {
                map = Map(2);
                map.GenerateWalls(1);

            }
            else if (levelType == "Greu") {
                map = Map(3);
                map.GenerateWalls(1);

            }
            else {
                return crow::response(400, "Server: Nivel necunoscut");
            }
            std::cout << "\n";
            std::cout << "\n";
            map.DisplayMap();
            std::cout << "\n";
            std::cout << "\n";


            // Crează răspunsul JSON
            crow::json::wvalue mapJson;
            const auto& mapData = map.GetMap();

            for (size_t i = 0; i < mapData.size(); ++i) {
                crow::json::wvalue rowJson;
                for (size_t j = 0; j < mapData[i].size(); ++j) {
                    const auto& cell = mapData[i][j];
                    crow::json::wvalue cellJson;
                    cellJson["wall"] = (cell.typeWall == Wall::TypeWall::destructible) ? "destructible" : "indestructible";
                    cellJson["space"] = cell.space;
                    cellJson["border"] = cell.border;
                    rowJson[std::to_string(j)] = std::move(cellJson);
                }
                mapJson[std::to_string(i)] = std::move(rowJson);
            }

            std::cout << "Răspuns JSON generat!" << std::endl;
            return crow::response(mapJson);
        }
        catch (const std::exception& e) {
            std::cout << "Eroare internă: " << e.what() << std::endl;
            return crow::response(500, "Server: Internal server error: " + std::string(e.what()));
        }
        });


    CROW_ROUTE(m_app, "/get_tank")
        ([this](const crow::request& req) {
        crow::json::wvalue response;
        auto clientId = req.url_params.get("id");

        if (clientId) {

            if (m_tanks.find(clientId) == m_tanks.end()) {
                return crow::response(404, R"({"error":"Tank not found for given Client ID"})");
            }
            const auto& tank = m_tanks[clientId];
            Tank::ColorTank color = tank.GetTank().GetColor();

            std::string rezColorTank;
            switch (color) {
            case Tank::ColorTank::Red:
                rezColorTank = "Red";
                break;
            case Tank::ColorTank::Blue:
                rezColorTank = "Blue";
                break;
            case Tank::ColorTank::Green:
                rezColorTank = "Green";
                break;
            default:
                rezColorTank = "Unknown";
                break;
            }

            std::cout << "Tank color for Client ID " << clientId << ": " << rezColorTank << "\n\n";

            return crow::response(rezColorTank);
        }

        return crow::response(400, R"({"error":"Client ID missing"})");
            });


    CROW_ROUTE(m_app, "/move_tank/up")([this](const crow::request& req) {
        auto clientId = req.url_params.get("id");
        if (!clientId) {
            return crow::response(400, "Missing client ID");
        }

        MoveTank(clientId, MovementObject::Direction::Up);
        std::string word = GetTankPositionString(clientId);
        return crow::response(200, "S-a mutat sus " + word);
        });

    CROW_ROUTE(m_app, "/move_tank/down")([this](const crow::request& req) {
        auto clientId = req.url_params.get("id");
        if (!clientId) {
            return crow::response(400, "Missing client ID");
        }

        MoveTank(clientId, MovementObject::Direction::Down);
        std::string word = GetTankPositionString(clientId);
        return crow::response(200, "S-a mutat jos " + word);
        });

    CROW_ROUTE(m_app, "/move_tank/left")([this](const crow::request& req) {
        auto clientId = req.url_params.get("id");
        if (!clientId) {
            return crow::response(400, "Missing client ID");
        }

        MoveTank(clientId, MovementObject::Direction::Left);
        std::string word = GetTankPositionString(clientId);
        return crow::response(200, "S-a mutat la stanga " + word);
        });

    CROW_ROUTE(m_app, "/move_tank/right")([this](const crow::request& req) {
        auto clientId = req.url_params.get("id");
        if (!clientId) {
            return crow::response(400, "Missing client ID");
        }

        MoveTank(clientId, MovementObject::Direction::Right);
        std::string word = GetTankPositionString(clientId);
        return crow::response(200, "S-a mutat la dreapta " + word);
        });


    unsigned int numThreads = std::thread::hardware_concurrency(); // Determină numărul de fire
    if (numThreads == 0) numThreads = 4; // Asigură-te că există cel puțin un fir

    m_app.port(8080).concurrency(numThreads).run();
}


//if (clientId) {

//    // Verifică dacă tank-ul există pentru clientId
//    if (m_tanks.find(clientId) == m_tanks.end()) {
//        return crow::response(404, R"({"error":"Tank not found for given Client ID"})");
//    }
//    // Obține tank-ul asociat
//    const auto& tank = m_tanks[clientId];
//    Tank::ColorTank color = std::get<2>(tank);

//    // Determină culoarea tank-ului
//    std::string rezColorTank;
//    switch (color) {
//    case Tank::ColorTank::Red:
//        rezColorTank = "Red";
//        break;
//    case Tank::ColorTank::Blue:
//        rezColorTank = "Blue";
//        break;
//    case Tank::ColorTank::Green:
//        rezColorTank = "Green";
//        break;
//    default:
//        rezColorTank = "Unknown";
//        break;
//    }

//    std::cout << "Tank color for Client ID " << clientId << ": " << rezColorTank << "\n\n";

//    // Trimite răspunsul
//    return crow::response(rezColorTank);
//}

//// Dacă clientId nu a fost specificat
//return crow::response(400, R"({"error":"Client ID missing"})");
//    });


////var pt cand merge BD

//CROW_ROUTE(m_app, "/move_tank")([this](const crow::request& req) {
//    auto client_id = req.url_params.get("id");
//    char* direction = req.url_params.get("direction");

//    if (client_id && direction) {
//        auto it = m_tanks.find(client_id);
//        if (it != m_tanks.end()) {
//            // Transformă caracterul direcției într-un obiect Direction
//            MovementObject::Direction dir;
//            if (strcmp(direction, "U") == 0) {
//                dir = MovementObject::Direction::Up;
//            }
//            else if (strcmp(direction, "D") == 0) {
//                dir = MovementObject::Direction::Down;
//            }
//            else if (strcmp(direction, "L") == 0) {
//                dir = MovementObject::Direction::Left;
//            }
//            else if (strcmp(direction, "R") == 0) {
//                dir = MovementObject::Direction::Right;
//            }
//            else {
//                return crow::response(400, "Invalid direction");
//            }

//                // Transformă caracterul direcției într-un obiect Direction

//            //std::cout << direction;
//            //    MovementObject::Direction dir;
//            //    if (strcmp(direction, "U") == 0) {  // Compară cu "U"
//            //        // Mișcă în sus
//            //        return crow::response(200, "S-a mutat sus");
//            //    }
//            //    else if (strcmp(direction, "D") == 0) {  // Compară cu "D"
//            //        // Mișcă în jos
//            //        return crow::response(200, "S-a mutat jos");
//            //    }
//            //    else if (strcmp(direction, "L") == 0) {  // Compară cu "L"
//            //        // Mișcă în stânga
//            //        return crow::response(200, "S-a mutat la stânga");
//            //    }
//            //    else if (strcmp(direction, "R") == 0) {  // Compară cu "R"
//            //        // Mișcă în dreapta
//            //        return crow::response(200, "S-a mutat la dreapta");
//            //    }
//            //    else {
//            //        return crow::response(400, "Direcție invalidă");
//            //    

//                // Mișcă obiectul

//                std::cout << "inainte de move";
//                it->second.Move(dir);
//                std::cout << "dupa de move";
//                std::cout << "New position: (" << std::to_string(it->second.GetX()) << ", " << std::to_string(it->second.GetY()) << ")";
//                // Răspunde cu noua poziție
//                return crow::response(200, "New position: (" + std::to_string(it->second.GetX()) + ", " + std::to_string(it->second.GetY()) + ")");
//            }
//            return crow::response(404, "Tank not found");
//        }

//        return crow::response(400, "Missing parameters");
//    
//    });


