#pragma once
#define _ITERATOR_DEBUG_LEVEL 2

#include "ClientServer.h"
#include <stdexcept>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QMessageBox>
#include <iostream>


#include "libs/nlohmann/json.hpp"
using json = nlohmann::json;


constexpr auto SERVER_URL = "http://localhost:8080";
std::string ClientServer::m_username = "";
std::string ClientServer::m_gameCode = "";
void ClientServer::connectServer()
{
    qDebug() << "Am intrat in functia de conectare la server din ClientServer.";
    try
    {
        cpr::Response response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/connect" });

        if (response.status_code == 200)
        {
            std::cout << "Mesaj de la server: " << response.text << std::endl;
        }
        else
        {
            std::cerr << "Eroare la conectare. Cod răspuns: " << response.status_code << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Excepție la conectare: " << ex.what() << std::endl;
    }
}


void ClientServer::StartGameWindow()
{
    qDebug() << "Am intrat in functia StartGameWindow din ClientServer.";
    try {
        cpr::Response response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/startGame" });

        if (response.status_code == 200) {
            std::cout << "Mesaj de la server: " << response.text << std::endl;
        }
        else {
            std::cerr << "Eroare la conectare. Cod răspuns: " << response.status_code << " - " << response.text << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Excepție la conectare: " << ex.what() << std::endl;
    }
}



bool ClientServer::LoginClient(const std::string& username) {
    try {
        m_username = username;
        auto response = cpr::Post(
            cpr::Url{ std::string(SERVER_URL) + "/login" },
            cpr::Body{ "{\"username\":\"" + username + "\"}" },
            cpr::Header{ {"Content-Type", "application/json"} }
        );

        if (response.status_code == 200) {
            std::cout << "Login successful: " << response.text << std::endl;
            return true;
        }
        else {
            std::cerr << "Login failed: " << response.text << " (Code: " << response.status_code << ")" << std::endl;
            return false;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception during login: " << ex.what() << std::endl;
        return false;
    }
}


bool ClientServer::RegisterClient(const std::string& username) {
    try {

        m_username = username;
        cpr::Response response = cpr::Post(
            cpr::Url{ std::string(SERVER_URL) + "/register" },
            cpr::Body{ "{\"username\":\"" + username + "\"}" },
            cpr::Header{ {"Content-Type", "application/json"} }
        );

        if (response.status_code == 200) {
            qDebug() << "Registration successful: " << QString::fromStdString(response.text);
            return true;
        }
        else {
            qDebug() << "Registration failed. Status code: " << response.status_code;
            return false;
        }
    }
    catch (const std::exception& ex) {
        qDebug() << "Exception during registration: " << ex.what();
        return false;
    }
}



void ClientServer::FetchAndProcessMap(const std::string& gameCode) {
    try {
        // Cerere GET la server
        cpr::Response response = cpr::Get(
              cpr::Url{ std::string(SERVER_URL) + "/get_map" },
              cpr::Parameters{ {"game_code", gameCode} }  // Pass the game code as a query parameter
     );

        if (response.status_code == 200) {
            // Parsează răspunsul serverului folosind nlohmann::json
            json mapData = json::parse(response.text);

            // Convertește JSON-ul primit în QJsonArray
            QJsonArray qMapArray;

            for (const auto& row : mapData["map"]) {
                QJsonArray qRow;
                for (const auto& cell : row) {
                    qRow.append(static_cast<int>(cell)); // Transformă valorile în int
                }
                qMapArray.append(qRow);
            }

            this->mapData = qMapArray;
        }
        else {
            qDebug() << "Eroare la fetch map: Cod status =" << response.status_code;
        }
    }
    catch (const std::exception& ex) {
        qDebug() << "Excepție: " << ex.what();
    }
}


QJsonArray ClientServer::GetMap()
{
    qDebug() << "Continutul mapData în getMap():";
    for (const auto& row : mapData) {
        qDebug() << row;
    }
    return mapData;
}

bool ClientServer::ControlsClient(const std::string& controls)
{
    try {
        // Creating a JSON object to send both username and controls
        nlohmann::json jsonBody;
        jsonBody["username"] = ClientServer::m_username;  // Username
        jsonBody["controls"] = nlohmann::json::parse(controls);  // Controls (this is expected to be a JSON string)

        // Convert the JSON object to a string
        std::string jsonString = jsonBody.dump();

        // Send the JSON object in the POST request
        cpr::Response response = cpr::Post(
            cpr::Url{ std::string(SERVER_URL) + "/controls" },
            cpr::Body{ jsonString },  // Send the JSON string as the body
            cpr::Header{ {"Content-Type", "application/json"} }  // Set the header to application/json
        );

        // Check if the server responded successfully
        if (response.status_code == 200) {
            std::cout << "Success: " << response.text << std::endl;
            return true;
        }
        else {
            std::cerr << "Error: " << response.status_code << " " << response.text << std::endl;
            return false;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception during controls submission: " << ex.what() << std::endl;
        return false;
    }
    return false;
}


std::string ClientServer::GenerateCode(uint8_t level, const std::string& username)
{
    try {
        std::string name = ClientServer::m_username;
        cpr::Response response = cpr::Get(
            cpr::Url{ std::string(SERVER_URL) + "/generate_code" },
            cpr::Parameters{
                {"level", std::to_string(level)},    // Add level as a query parameter
                {"username", name}               // Add username as a query parameter
            },
            cpr::Header{ {"Content-Type", "application/json"} }  // Optional, you can send this header
        );

        if (response.status_code == 200) {
            std::cout << "Generated Game Code: " << response.text << std::endl;
            m_gameCode = response.text;
            return response.text;  // Return the generated game code
        }
        else {
            std::cerr << "Error: " << response.status_code << " " << response.text << std::endl;
            return "";  // Return an empty string if there was an error
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception during generating game code: " << ex.what() << std::endl;
        return "";  // Return an empty string on exception
    }
}

bool ClientServer::JoinGame(const std::string& gameCode, const std::string& username)
{
    try {
        // Create a JSON object with the game code and username
        nlohmann::json jsonBody;
        jsonBody["game_code"] = gameCode;
        std::string name = ClientServer::m_username;
        jsonBody["username"] = name;

        // Convert the JSON object to a string
        std::string jsonString = jsonBody.dump();

        // Send a POST request to the server to join the game
        cpr::Response response = cpr::Post(
            cpr::Url{ std::string(SERVER_URL) + "/join_game" },
            cpr::Body{ jsonString },
            cpr::Header{ {"Content-Type", "application/json"} }
        );

        if (response.status_code == 200) {
            std::cout << "Successfully joined the game: " << response.text << std::endl;
            return true;
        }
        else {
            std::cerr << "Failed to join the game. Server response: " << response.status_code << " " << response.text << std::endl;
            return false;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception during joining the game: " << ex.what() << std::endl;
        return false;
    }
}

bool ClientServer::SendKeyPress(int keyCode) {
    try {
        // Create JSON payload
        std::string name = ClientServer::m_username;
        std::string code = ClientServer::m_gameCode;

        nlohmann::json keyPressJson;
        keyPressJson["username"] = name;
        keyPressJson["code"] = code;
        keyPressJson["key_code"] = keyCode;

        // Send POST request
        cpr::Response response = cpr::Post(
            cpr::Url{ std::string(SERVER_URL) + "/key_press" },
            cpr::Body{ keyPressJson.dump() },
            cpr::Header{ {"Content-Type", "application/json"} }
        );

        if (response.status_code == 200) {
            std::cout << "Key press sent successfully: " << response.text << std::endl;
            return true;
        }
        else {
            std::cerr << "Failed to send key press. Response: " << response.text << std::endl;
            return false;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception while sending key press: " << ex.what() << std::endl;
        return false;
    }
}

bool ClientServer::IsLastPlayer()
{
    // Create the JSON body for the request
    std::string name = ClientServer::m_username;
    std::string code = ClientServer::m_gameCode;

    json requestBody = {
        {"username", name},
        {"game_code", code}
    };

    // Send the POST request to the server
    cpr::Response response = cpr::Post(
        cpr::Url{ std::string(SERVER_URL) + " /is_last_player" },  // URL of your server
        cpr::Body{ requestBody.dump() },
        cpr::Header{ {"Content-Type", "application/json"} }
    );

    // Check the status code
    if (response.status_code == 200) {
        std::cout << response.text << std::endl;
        return true;
    }
    else {
        std::cerr << "Error: " << response.status_code << " - " << response.text << std::endl;
        return false;
    }
}



bool ClientServer::SaveSettings(const std::string& volume)
{
    try {
        // Trimite volumul către server printr-o cerere POST
        cpr::Response response = cpr::Post(
            cpr::Url{ std::string(SERVER_URL) + "/save_general_settings" },
            cpr::Body{ "{\"volume\":\"" + volume + "\"}" },
            cpr::Header{ {"Content-Type", "application/json"} }
        );

        if (response.status_code == 200) {
            std::cout << "Settings saved successfully: " << response.text << std::endl;
            return true;
        }
        else {
            std::cerr << "Failed to save settings: " << response.text << std::endl;
            return false;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Error during settings save request: " << ex.what() << std::endl;
        return false;
    }
}

void ClientServer::GetGeneralSettings() {
    try {
        cpr::Response response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/get_general_settings" });

        if (response.status_code == 200) {
            std::cout << "General settings retrieved: " << response.text << std::endl;

        }
        else {
            std::cerr << "Failed to retrieve general settings. Response code: " << response.status_code << std::endl;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception while getting general settings: " << ex.what() << std::endl;
    }
}
bool ClientServer::SetGeneralSettings(const std::string& settingsJson) {
    try {
        cpr::Response response = cpr::Post(
            cpr::Url{ std::string(SERVER_URL) + "/set_general_settings" },
            cpr::Body{ settingsJson },
            cpr::Header{ {"Content-Type", "application/json"} }
        );

        if (response.status_code == 200) {
            std::cout << "General settings updated: " << response.text << std::endl;
            return true;
        }
        else {
            std::cerr << "Failed to update general settings. Response code: " << response.status_code << std::endl;
            return false;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception while setting general settings: " << ex.what() << std::endl;
        return false;
    }
}
void ClientServer::GetInGameSettings() {
    try {
        cpr::Response response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/get_in_game_settings" });

        if (response.status_code == 200) {
            std::cout << "In game settings retrieved: " << response.text << std::endl;

        }
        else {
            std::cerr << "Failed to retrieve in game settings. Response code: " << response.status_code << std::endl;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception while getting in game settings: " << ex.what() << std::endl;
    }
}
bool ClientServer::SetInGameSettings(const std::string& settingsJson) {
    try {
        cpr::Response response = cpr::Post(
            cpr::Url{ std::string(SERVER_URL) + "/set_in_game_settings" },
            cpr::Body{ settingsJson },
            cpr::Header{ {"Content-Type", "application/json"} }
        );

        if (response.status_code == 200) {
            std::cout << "In game settings updated: " << response.text << std::endl;
            return true;
        }
        else {
            std::cerr << "Failed to update in game settings. Response code: " << response.status_code << std::endl;
            return false;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception while setting in game settings: " << ex.what() << std::endl;
        return false;
    }
}

