#pragma once
#include "routing.h"
#include "libs/nlohmann/json.hpp"
//#include "GameManager.h"
#include "Game.h"

using json = nlohmann::json;

#include <sstream>

using namespace http;
Database db("testDatabase2.db");
namespace http {
    std::unordered_map<std::string, Player> playersActive;
    std::unordered_map<std::string, Game> games;

}


void http::Routing::Run()
{
    CROW_ROUTE(m_app, "/connect")([]() {
        return crow::response(200, "Server: Conectare reusita!");
        });
    CROW_ROUTE(m_app, "/startGame")([]() {
        return crow::response(200, "Server: Conectare reusita la start!");
        });
    CROW_ROUTE(m_app, "/user")([]() {
        return crow::response(200, "Server: Conectare reusita la user!");
        });

    CROW_ROUTE(m_app, "/sendName").methods(crow::HTTPMethod::Post)([](const crow::request& req) {
        auto body = req.body;
        std::string response;
        if (body == "John") {
            response = "Server: Hello, John! Your name is recognized.";
            return crow::response(200, response);
        }
        else {
            response = "Server: Hello, " + body + "! Your name is not John, but it's still nice.";
            return crow::response(401, response);
        }
        });

    CROW_ROUTE(m_app, "/login").methods("POST"_method)([](const crow::request& req) {
        auto json = crow::json::load(req.body);
        if (!json || !json.has("username")) {
            return crow::response(400, "Invalid JSON");
        }

        std::string username = json["username"].s();
        if (db.ClientExists(username)) {

            Player player(username, db);
            playersActive.emplace(username, std::move(player));

            return crow::response(200, "Login successful");
        }
        else {
            return crow::response(401, "Invalid username");
        }
        });

    CROW_ROUTE(m_app, "/register").methods(crow::HTTPMethod::POST)([](const crow::request& req) {

        auto json = crow::json::load(req.body);
        if (!json) {
            return crow::response(400, "Invalid JSON");
        }

        std::string username = json["username"].s();

        if (db.ClientExists(username)) {
            return crow::response(409, "Registration failed: User already exists");
        }
        else {
            db.AddClient(username, 0);
            Player player(username, db);
            playersActive.emplace(username, std::move(player));
            return crow::response(200, "Registration successful");
        }
        });


    CROW_ROUTE(m_app, "/controls").methods("POST"_method)([](const crow::request& req) {
        // Parse the JSON request body
        nlohmann::json json;
        try {
            json = nlohmann::json::parse(req.body);
        }
        catch (const std::exception& e) {
            return crow::response(400, "Invalid JSON format: " + std::string(e.what()));
        }

        // Validate that all necessary fields are present in the JSON
        if (!json.contains("username") || !json.contains("Up") || !json.contains("Down") ||
            !json.contains("Left") || !json.contains("Right") || !json.contains("Shoot")) {
            return crow::response(400, "Invalid JSON or missing fields");
        }

        std::string username = json["username"];
        std::string up = json["Up"];
        std::string down = json["Down"];
        std::string left = json["Left"];
        std::string right = json["Right"];
        std::string shoot = json["Shoot"];

        std::cout << "Received controls for " << username << ": " << "Up = " << up << ", Down = " << down
            << ", Left = " << left << ", Right = " << right << ", Shoot = " << shoot << std::endl;
        if (playersActive.find(username) == playersActive.end()) {
            return crow::response(404, "User is not Active");
        }

        bool success = db.SaveKeyBindings(username, up, down, left, right, shoot);
        if (!success) {
            return crow::response(500, "Failed to save key bindings");
        }
        return crow::response(200, "Controls successfully set for user: " + username);
        });




    //CROW_ROUTE(m_app, "/get_map").methods("GET"_method)([]() {
    //    try {
    //        Map gameMap(1); // Creează o instanță a clasei Map

    //        // Crearea structurii JSON
    //        crow::json::wvalue jsonMap;
    //        jsonMap["width"] = gameMap.GetWidth();
    //        jsonMap["height"] = gameMap.GetHeight();

    //        const auto& mapData = gameMap.GetMap();

    //        // Construim JSON-ul rând cu rând
    //        for (size_t i = 0; i < mapData.size(); ++i) {
    //            crow::json::wvalue rowJson;
    //            for (size_t j = 0; j < mapData[i].size(); ++j) {
    //                const auto& cell = mapData[i][j];
    //                crow::json::wvalue cellJson;

    //                // Determinăm tipul celulei
    //                /*if (std::holds_alternative<Map::Empty>(cell.content)) {
    //                    cellJson["type"] = "Empty";
    //                }
    //                else if (std::holds_alternative<Map::Bomb>(cell.content)) {
    //                    cellJson["type"] = "Bomb";
    //                }
    //                else if (std::holds_alternative<Map::BonusLife>(cell.content)) {
    //                    cellJson["type"] = "BonusLife";
    //                }
    //                else if (std::holds_alternative<Wall::TypeWall>(cell.content)) {
    //                    auto wallType = std::get<Wall::TypeWall>(cell.content);
    //                    cellJson["type"] = (wallType == Wall::TypeWall::indestructible)
    //                        ? "Wall_Indestructible"
    //                        : "Wall_Destructible";
    //                }
    //                else if (std::holds_alternative<Map::Tank>(cell.content)) {
    //                    cellJson["type"] = "Tank";
    //                }
    //                else if (std::holds_alternative<Map::Bullet>(cell.content)) {
    //                    cellJson["type"] = "Bullet";
    //                }*/

    //                if (std::holds_alternative<Map::Empty>(cell.content)) {
    //                   // std::cout << "Cell (" << i << "," << j << ") is Empty.\n";
    //                    cellJson["type"] = "Empty";
    //                }
    //                else if (std::holds_alternative<Map::Bomb>(cell.content)) {
    //                    //std::cout << "Cell (" << i << "," << j << ") is Bomb.\n";
    //                    cellJson["type"] = "Bomb";
    //                }
    //                else if (std::holds_alternative<Map::BonusLife>(cell.content)) {
    //                    //std::cout << "Cell (" << i << "," << j << ") is BonusLife.\n";
    //                    cellJson["type"] = "BonusLife";
    //                }
    //                else if (std::holds_alternative<Wall::TypeWall>(cell.content)) {
    //                    auto wallType = std::get<Wall::TypeWall>(cell.content);
    //                   // std::cout << "Cell (" << i << "," << j << ") is Wall of type: "
    //                       // << (wallType == Wall::TypeWall::indestructible ? "Indestructible" : "Destructible") << "\n";
    //                    cellJson["type"] = (wallType == Wall::TypeWall::indestructible)
    //                        ? "Wall_Indestructible"
    //                        : "Wall_Destructible";
    //                }
    //                else if (std::holds_alternative<Map::Tank>(cell.content)) {
    //                    //std::cout << "Cell (" << i << "," << j << ") is Tank.\n";
    //                    cellJson["type"] = "Tank";
    //                }
    //                else if (std::holds_alternative<Map::Bullet>(cell.content)) {
    //                   // std::cout << "Cell (" << i << "," << j << ") is Bullet.\n";
    //                    cellJson["type"] = "Bullet";
    //                }
    //                else {
    //                    std::cout << "Cell (" << i << "," << j << ") is unrecognized!\n";
    //                }

    //                // Adăugăm alte detalii opționale
    //                cellJson["border"] = cell.border;

    //                // Adăugăm celula la rând
    //                std::cout << "Cell (" << i << "," << j << "): " << cellJson.dump() << std::endl;

    //                rowJson[std::to_string(j)] = std::move(cellJson);
    //               
    //            }
    //            /*std::cout << "Row " << i << ": {";
    //            for (const auto& [key, value] : rowJson) {
    //                std::cout << "\"" << key << "\": " << value.dump() << ", ";
    //            }
    //            std::cout << "}" << std::endl;*/


    //            // Adăugăm rândul la JSON
    //            jsonMap["cells"][std::to_string(i)] = std::move(rowJson);
    //        }

    //        //std::cout << "Răspuns JSON generat:\n" << crow::json::dump(jsonMap) << std::endl;

    //        // Returnăm JSON-ul
    //        return crow::response(200, jsonMap);
    //    }
    //    catch (const std::exception& e) {
    //        return crow::response(500, "Server error: " + std::string(e.what()));
    //    }
    //    });

//CROW_ROUTE(m_app, "/get_map").methods("GET"_method)([]() {
//    try {
//        Map gameMap(1); // Create an instance of Map
//
//        crow::json::wvalue jsonMap; // Create the root JSON object
//        jsonMap["width"] = gameMap.GetWidth();
//        jsonMap["height"] = gameMap.GetHeight();
//
//        const auto& mapData = gameMap.GetMap();
//
//        // Create the "cells" array
//        crow::json::wvalue::list cellsJson;
//
//        for (size_t i = 0; i < mapData.size(); ++i) {
//            crow::json::wvalue::list rowJson; // Each row is a list
//            for (size_t j = 0; j < mapData[i].size(); ++j) {
//                const auto& cell = mapData[i][j];
//                crow::json::wvalue cellJson; // Create a JSON object for each cell
//
//                // Use numeric codes for cell types
//                if (std::holds_alternative<Map::Empty>(cell.content)) {
//                    cellJson["type"] = static_cast<int>(0);
//                }
//                else if (std::holds_alternative<Map::Bomb>(cell.content)) {
//                    cellJson["type"] = static_cast<int>(1);
//                }
//                else if (std::holds_alternative<Map::BonusLife>(cell.content)) {
//                    cellJson["type"] = static_cast<int>(2);
//                }
//                else if (std::holds_alternative<Wall::TypeWall>(cell.content)) {
//                    auto wallType = std::get<Wall::TypeWall>(cell.content);
//                    cellJson["type"] = static_cast<int>(
//                        (wallType == Wall::TypeWall::indestructible) ? 4 : 3);
//                }
//                else if (std::holds_alternative<Map::Tank>(cell.content)) {
//                    cellJson["type"] = static_cast<int>(5);
//                }
//                else if (std::holds_alternative<Map::Bullet>(cell.content)) {
//                    cellJson["type"] = static_cast<int>(6);
//                }
//                else {
//                    cellJson["type"] = static_cast<int>(-1); // Unrecognized
//                }
//
//                // Optional details like `border`
//                cellJson["border"] = static_cast<int>(cell.border);
//
//                // Add the cell JSON object to the row
//                //rowJson.push_back(std::move(cellJson));
//                std::cout << "cellJson before move: " << cellJson.dump()<< std::endl;
//
//                // Add to rowJson
//                rowJson.push_back(std::move(cellJson));
//
//                // Debug rowJson after adding cellJson
//                //std::cout << "rowJson after adding cell (" << i << ", " << j << "): " << rowJson.dump() << std::endl;
//
//            }
//
//            // Add the row to the "cells" array
//            cellsJson.push_back(std::move(rowJson));
//        }
//
//        // Assign the "cells" array to the root JSON object
//        jsonMap["cells"] = std::move(cellsJson);
//
//        // Return the JSON response
//        //if(!jsonMap.empty_object())
//        return crow::response(200, jsonMap);
//    }
//    catch (const std::exception& e) {
//        return crow::response(500, "Server error: " + std::string(e.what()));
//    }
//    });



//CROW_ROUTE(m_app, "/get_map").methods("GET"_method)([]() {
//    try {
//        Map gameMap(1); // Create an instance of Map
//
//        crow::json::wvalue json; // Create the root JSON object
//        json["width"] = gameMap.GetWidth();
//        json["height"] = gameMap.GetHeight();
//
//        const auto& mapData = gameMap.GetMap();
//
//        // Create the "cells" array
//        crow::json::wvalue::list jsonMap;
//
//        for (const auto& row : mapData) {
//            crow::json::wvalue::list jsonRow;
//            for (const auto& cell : row)
//            {
//                jsonRow.push_back(cell.ToInt());
//            }
//            jsonMap.push_back(std::move(jsonRow));
//        }
//        json["map"] = std::move(jsonMap);
//
//              
//            
//        return crow::response(200, json);
//    }
//    catch (const std::exception& e) {
//        return crow::response(500, "Server error: " + std::string(e.what()));
//    }
//    });

    CROW_ROUTE(m_app, "/get_map").methods("GET"_method)([]() {
        try {
            Map gameMap(1); // Create an instance of Map

            crow::json::wvalue json; // Create the root JSON object
            json["width"] = gameMap.GetWidth();
            json["height"] = gameMap.GetHeight();

            const auto& mapData = gameMap.GetMap();

            // Create the "cells" array
            crow::json::wvalue::list jsonMap;
            for (const auto& row : mapData) {
                crow::json::wvalue::list jsonRow;
                for (const auto& cell : row) {
                    jsonRow.push_back(cell.ToInt());
                }
                jsonMap.push_back(std::move(jsonRow));
            }
            json["map"] = std::move(jsonMap);

            // Serialize the JSON to ensure it's valid
            std::string serializedJson = json.dump();

            // Log the serialized JSON for debugging
            std::cout << "Serialized JSON Response: " << serializedJson << std::endl;

            // Return the serialized JSON
            //return crow::response(200, serializedJson);
            return crow::response(200, serializedJson);//.add_header("Content-Type", "application/json; charset=utf-8");

        }
        catch (const std::exception& e) {
            return crow::response(500, "Server error: " + std::string(e.what()));
        }
        });






    //CROW_ROUTE(m_app, "/get_map").methods("GET"_method)([]() {
    //    crow::json::wvalue jsonMap;
    //    jsonMap["width"] = 10;
    //    jsonMap["height"] = 10;
    //    jsonMap["cells"] = crow::json::load(R"({
    //        "0": {"0": {"type": "Empty", "border": false}},
    //        "1": {"0": {"type": "Wall_Destructible", "border": false}}
    //    })");
    //    return crow::response(200, jsonMap);
    //    });

    //CROW_ROUTE(m_app, "/get_map").methods("GET"_method)([]() {
    //    crow::json::wvalue jsonMap;
    //    jsonMap["width"] = 10;
    //    jsonMap["height"] = 10;
    //
    //    jsonMap["cells"]["0"]["0"] = { {"type", "Empty"}, {"border", false} };
    //    jsonMap["cells"]["1"]["0"] = { {"type", "Wall_Destructible"}, {"border", false} };
    //
    //    return crow::response(200, jsonMap); // Directly use jsonMap as the response body
    //    });

    //CROW_ROUTE(m_app, "/get_map").methods("GET"_method)([]() {
    //    crow::json::wvalue jsonMap;
    //
    //    // Correctly construct JSON
    //    jsonMap["width"] = 10;
    //    jsonMap["height"] = 10;
    //
    //    jsonMap["cells"]["0"]["0"] = { {"type", "Empty"}, {"border", false} };
    //    jsonMap["cells"]["1"]["0"] = { {"type", "Wall_Destructible"}, {"border", false} };
    //
    //    // Serialize JSON to string
    //    std::ostringstream os;
    //    os << jsonMap;
    //
    //    crow::response res(200);
    //    res.add_header("Content-Type", "application/json; charset=utf-8");
    //    res.body = os.str(); // Serialize JSON as response body
    //    return res;
    //    });

    //CROW_ROUTE(m_app, "/get_map").methods("GET"_method)([]() {
    //    try {
    //        Map gameMap(1); // Instanța clasei Map
    //
    //        // Structură JSON pentru mapă
    //        json jsonMap;
    //        jsonMap["width"] = gameMap.GetWidth();
    //        jsonMap["height"] = gameMap.GetHeight();
    //
    //        const auto& mapData = gameMap.GetMap();
    //        jsonMap["cells"] = json::array();
    //
    //        for (size_t i = 0; i < mapData.size(); ++i) {
    //            json rowJson = json::array();
    //            for (size_t j = 0; j < mapData[i].size(); ++j) {
    //                const auto& cell = mapData[i][j];
    //                json cellJson;
    //
    //                // Tipuri de celule
    //                if (std::holds_alternative<Map::Empty>(cell.content)) {
    //                    cellJson["type"] = "Empty";
    //                }
    //                else if (std::holds_alternative<Map::Bomb>(cell.content)) {
    //                    cellJson["type"] = "Bomb";
    //                }
    //                else if (std::holds_alternative<Map::BonusLife>(cell.content)) {
    //                    cellJson["type"] = "BonusLife";
    //                }
    //                else if (std::holds_alternative<Wall::TypeWall>(cell.content)) {
    //                    auto wallType = std::get<Wall::TypeWall>(cell.content);
    //                    cellJson["type"] = (wallType == Wall::TypeWall::indestructible)
    //                        ? "Wall_Indestructible"
    //                        : "Wall_Destructible";
    //                }
    //                else if (std::holds_alternative<Map::Tank>(cell.content)) {
    //                    cellJson["type"] = "Tank";
    //                }
    //                else if (std::holds_alternative<Map::Bullet>(cell.content)) {
    //                    cellJson["type"] = "Bullet";
    //                }
    //
    //                cellJson["border"] = cell.border;
    //
    //                // Adăugăm celula în rând
    //                rowJson.push_back(cellJson);
    //            }
    //            // Adăugăm rândul în matrice
    //            jsonMap["cells"].push_back(rowJson);
    //        }
    //
    //        // Afișăm JSON-ul generat
    //        std::cout << "Generated JSON Map:\n" << jsonMap.dump(4) << std::endl;
    //
    //        // Returnăm JSON-ul către client
    //        return crow::response(200, jsonMap.dump());
    //    }
    //    catch (const std::exception& e) {
    //        return crow::response(500, "Server error: " + std::string(e.what()));
    //    }
    //    });
    //
    //    CROW_ROUTE(m_app, "/generate_code")([]() {
    //        return crow::response(200, "Server: Generate code");
    //        });
    //    CROW_ROUTE(m_app, "/check_code")([]() {
    //        return crow::response(200, "Server: check coded!");
    //        });
    //    CROW_ROUTE(m_app, "/level")([]() {
    //        return crow::response(200, "Server: level corect!");
    //        });
    //




    CROW_ROUTE(m_app, "/generate_code").methods("GET"_method)([](const crow::request& req) {
        try {
            auto level = req.url_params.get("level");
            if (level == nullptr) {
                return crow::response(400, "Missing level parameter");
            }

            uint8_t levelInt = std::stoi(level);

            std::string gameCode = Game::GenerateGameCode();

            while (games.find(gameCode) != games.end()) {
                gameCode = Game::GenerateGameCode();
            }
            games[gameCode] = Game(levelInt, gameCode);

            //return crow::response(200, "Game code generated: " + gameCode);
            return crow::response(200,  gameCode);
        }
        catch (const std::exception& e) {
            return crow::response(500, "Error generating game code: " + std::string(e.what()));
        }
        });

    //CROW_ROUTE(m_app, "/join_game").methods("POST"_method)([](const crow::request& req) {
    //    auto json = crow::json::load(req.body);
    //    if (!json || !json.has("game_code") || !json.has("username")) {
    //        return crow::response(400, "Invalid JSON or missing fields");
    //    }

    //    std::string gameCode = json["game_code"].s();
    //    std::string username = json["username"].s();

    //    // Check if the game exists
    //    if (!GameManager::GameExists(gameCode)) {
    //        return crow::response(404, "Game code not found");
    //    }

    //    // Proceed with adding the player to the game...
    //    return crow::response(200, "Player joined the game");
    //    });


    //CROW_ROUTE(m_app, "/join_game").methods("POST"_method)([](const crow::request& req) {
    //    auto json = crow::json::load(req.body);
    //    if (!json || !json.has("game_code") || !json.has("username")) {
    //        return crow::response(400, "Invalid JSON or missing fields");
    //    }
    //
    //    std::string gameCode = json["game_code"].s();
    //    std::string username = json["username"].s();
    //
    //    // Check if the game code exists
    //    if (games.find(gameCode) == games.end()) {
    //        return crow::response(404, "Game code not found");
    //    }
    //
    //    Game& game = games[gameCode];
    //
    //    // Check if the game has already started
    //    if (game.gameStarted) {
    //        return crow::response(403, "Game already started");
    //    }
    //
    //    // Check if the player is already in the game
    //    if (std::find(game.players.begin(), game.players.end(), username) != game.players.end()) {
    //        return crow::response(409, "Player already in the game");
    //    }
    //
    //    // Add the player to the game
    //    game.players.push_back(username);
    //    std::cout << "Player " << username << " joined the game " << gameCode << std::endl;
    //
    //    return crow::response(200, "Player " + username + " joined the game successfully");
    //    });




            //CROW_ROUTE(m_app, "/choose_level").methods(crow::HTTPMethod::POST)([&](const crow::request& req) {
            //    try {
            //        std::string levelType = req.body;
            //        if (levelType.empty()) {
            //            return crow::response(400, "Server:Bad request: missing level type");
            //        }

            //        std::string clientId = req.get_header_value("Client-ID");
            //        if (clientId.empty()) {
            //            return crow::response(400, "Server:Bad request: missing client ID");
            //        }

            //        std::cout << "Nivel ales pentru Client-ID " << clientId << ": " << levelType << std::endl;
            //        AddClient(clientId, levelType);
            //        std::cout << "Nivel ales pentru Client-ID " << clientId << ": " << levelType << std::endl;

            //        return crow::response(200, "Server:Nivel ales: " + levelType);
            //    }
            //    catch (const std::exception& e) {
            //        return crow::response(500, "Server:Internal server error: " + std::string(e.what()));
            //    }
            //    });

            //CROW_ROUTE(m_app, "/get_map").methods(crow::HTTPMethod::GET)([&](const crow::request& req) {
            //    try {
            //        std::string clientId = req.get_header_value("Client-ID");
            //        if (clientId.empty()) {
            //            return crow::response(400, "Server: Missing Client-ID");
            //        }

            //        std::string levelType;
            //        {
            //            //std::lock_guard<std::mutex> lock(clientLevelsMutex);
            //            if (m_clientLevels.find(clientId) == m_clientLevels.end()) {
            //                return crow::response(400, "Server: Client ID invalid sau nu s-a ales un nivel");
            //            }
            //            levelType = m_clientLevels[clientId];
            //        }

            //        std::cout << "Client-ID " << clientId << " solicită nivelul: " << levelType << std::endl;

            //        Map map(1);  // Nivel default
            //        if (levelType == "Usor") {
            //            map = Map(1);
            //            map.GenerateWalls(1);
            //        }
            //        else if (levelType == "Mediu") {
            //            map = Map(2);
            //            map.GenerateWalls(1);

            //        }
            //        else if (levelType == "Greu") {
            //            map = Map(3);
            //            map.GenerateWalls(1);

            //        }
            //        else {
            //            return crow::response(400, "Server: Nivel necunoscut");
            //        }
            //        std::cout << "\n";
            //        std::cout << "\n";
            //        map.DisplayMap();
            //        std::cout << "\n";
            //        std::cout << "\n";


            //        // Crează răspunsul JSON
            //        crow::json::wvalue mapJson;
            //        const auto& mapData = map.GetMap();

            //        for (size_t i = 0; i < mapData.size(); ++i) {
            //            crow::json::wvalue rowJson;
            //            for (size_t j = 0; j < mapData[i].size(); ++j) {
            //                const auto& cell = mapData[i][j];
            //                crow::json::wvalue cellJson;
            //                cellJson["wall"] = (cell.typeWall == Wall::TypeWall::destructible) ? "destructible" : "indestructible";
            //                cellJson["space"] = cell.space;
            //                cellJson["border"] = cell.border;
            //                rowJson[std::to_string(j)] = std::move(cellJson);
            //            }
            //            mapJson[std::to_string(i)] = std::move(rowJson);
            //        }

            //        std::cout << "Răspuns JSON generat!" << std::endl;
            //        return crow::response(mapJson);
            //    }
            //    catch (const std::exception& e) {
            //        std::cout << "Eroare internă: " << e.what() << std::endl;
            //        return crow::response(500, "Server: Internal server error: " + std::string(e.what()));
            //    }
            //    });


            //CROW_ROUTE(m_app, "/get_tank")
            //    ([this](const crow::request& req) {
            //    crow::json::wvalue response;
            //    auto clientId = req.url_params.get("id");

            //    if (clientId) {

            //        if (m_tanks.find(clientId) == m_tanks.end()) {
            //            return crow::response(404, R"({"error":"Tank not found for given Client ID"})");
            //        }
            //        const auto& tank = m_tanks[clientId];
            //        Tank::ColorTank color = tank.GetTank().GetColor();

            //        std::string rezColorTank;
            //        switch (color) {
            //        case Tank::ColorTank::Red:
            //            rezColorTank = "Red";
            //            break;
            //        case Tank::ColorTank::Blue:
            //            rezColorTank = "Blue";
            //            break;
            //        case Tank::ColorTank::Green:
            //            rezColorTank = "Green";
            //            break;
            //        default:
            //            rezColorTank = "Unknown";
            //            break;
            //        }

            //        std::cout << "Tank color for Client ID " << clientId << ": " << rezColorTank << "\n\n";

            //        return crow::response(rezColorTank);
            //    }

            //    return crow::response(400, R"({"error":"Client ID missing"})");
            //        });


            //CROW_ROUTE(m_app, "/move_tank/up")([this](const crow::request& req) {
            //    auto clientId = req.url_params.get("id");
            //    if (!clientId) {
            //        return crow::response(400, "Missing client ID");
            //    }

            //    MoveTank(clientId, MovementObject::Direction::Up);
            //    std::string word = GetTankPositionString(clientId);
            //    return crow::response(200, "S-a mutat sus " + word);
            //    });

            //CROW_ROUTE(m_app, "/move_tank/down")([this](const crow::request& req) {
            //    auto clientId = req.url_params.get("id");
            //    if (!clientId) {
            //        return crow::response(400, "Missing client ID");
            //    }

            //    MoveTank(clientId, MovementObject::Direction::Down);
            //    std::string word = GetTankPositionString(clientId);
            //    return crow::response(200, "S-a mutat jos " + word);
            //    });

            //CROW_ROUTE(m_app, "/move_tank/left")([this](const crow::request& req) {
            //    auto clientId = req.url_params.get("id");
            //    if (!clientId) {
            //        return crow::response(400, "Missing client ID");
            //    }

            //    MoveTank(clientId, MovementObject::Direction::Left);
            //    std::string word = GetTankPositionString(clientId);
            //    return crow::response(200, "S-a mutat la stanga " + word);
            //    });

            //CROW_ROUTE(m_app, "/move_tank/right")([this](const crow::request& req) {
            //    auto clientId = req.url_params.get("id");
            //    if (!clientId) {
            //        return crow::response(400, "Missing client ID");
            //    }

            //    MoveTank(clientId, MovementObject::Direction::Right);
            //    std::string word = GetTankPositionString(clientId);
            //    return crow::response(200, "S-a mutat la dreapta " + word);
            //    });


            //unsigned int numThreads = std::thread::hardware_concurrency(); // Determină numărul de fire
            //if (numThreads == 0) numThreads = 4; // Asigură-te că există cel puțin un fir

           // m_app.port(8080).concurrency(numThreads).run();
    m_app.port(8080).run();
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






//CROW_ROUTE(m_app, "/move").methods("POST"_method)([](const crow::request& req) {
//    auto json = crow::json::load(req.body);
//    if (!json.has("username") || !json.has("direction")) {
//        return crow::response(400, "Missing parameters");
//    }
//
//    std::string username = json["username"].s();
//    std::string direction = json["direction"].s();
//
//    auto* player = PlayerManager::GetPlayer(username);
//    if (!player) {
//        return crow::response(404, "Player not found");
//    }
//
//    MovementObject::Direction dir;
//    if (direction == "up") dir = MovementObject::Direction::Up;
//    else if (direction == "down") dir = MovementObject::Direction::Down;
//    else if (direction == "left") dir = MovementObject::Direction::Left;
//    else if (direction == "right") dir = MovementObject::Direction::Right;
//    else return crow::response(400, "Invalid direction");
//
//    player->GetMovementObject().Move(dir);
//    return crow::response(200, "Player moved");
//    });
//CROW_ROUTE(m_app, "/shoot").methods("POST"_method)([](const crow::request& req) {
//    auto json = crow::json::load(req.body);
//    if (!json.has("username")) {
//        return crow::response(400, "Missing username");
//    }
//
//    std::string username = json["username"].s();
//    auto* player = PlayerManager::GetPlayer(username);
//    if (!player) {
//        return crow::response(404, "Player not found");
//    }
//
//    player->GetMovementObject().Shoot();
//    return crow::response(200, "Bullet shot");
//    });
//
//CROW_ROUTE(m_app, "/game_ws").websocket().onmessage([](crow::websocket::connection& conn, const std::string& data) {
//    conn.send_text("Game update: " + data);
//    });
