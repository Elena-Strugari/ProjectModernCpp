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


void ClientServer::UserWindow()
{
    try {
        cpr::Response response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/user" });

        if (response.status_code == 200) {
            std::cout << "Mesaj de la server: " << response.text << std::endl;
        }
        else {
            std::cerr << "Eroare la conectare. Cod răspuns: " << response.status_code << std::endl;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Excepție la conectare: " << ex.what() << std::endl;
    }

}


bool ClientServer::verificare()
{
    qDebug() << "Am intrat in noua functie de verificare din ClientServer.";
    try {
        QString name = "John";
        std::string nameS = name.toUtf8().constData();

        cpr::Response r = cpr::Post(
            cpr::Url{ std::string(SERVER_URL) + "/sendName" },
            cpr::Body{ nameS },
            cpr::Header{ {"Content-Type", "text/plain"} }
        );
        if (r.status_code == 200) {
            qDebug() << "Server returned message: " << r.text.c_str();

            return true;
        }
        else {
            qDebug() << "Registration failed. Status code: " << r.status_code;
            qDebug() << "Server response: " << QString::fromStdString(r.text);
            return false;
        }
    }
    catch (const std::exception& ex) {
        qDebug() << "Error during verification: " << ex.what();
        return false;
    }
}



bool ClientServer::LoginClient(const std::string& username) {
    try {
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

bool ClientServer::ControlsClient(const std::string& controls)
{
    try {
        cpr::Response response = cpr::Post(
            cpr::Url{ std::string(SERVER_URL) + "/controls" },
            cpr::Body{ controls },
            cpr::Header{ {"Content-Type", "application/json"} }
        );

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
}


/*QJsonDocument ClientServer::GetMap() {
     auto response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/get_map" });
     if (response.status_code == 200) {
         QJsonDocument jsonDoc = QJsonDocument::fromJson(QString::fromStdString(response.text).toUtf8());
         if (!jsonDoc.isNull()) {
              return jsonDoc;
         }
         else {
             throw std::runtime_error("Invalid JSON received");
         }
     }
     else {
       throw std::runtime_error("Failed to fetch map from server");
     }
}*/




//QJsonDocument ClientServer::GetMap() {
//    auto response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/get_map" });
//
//    // Debug în QMessageBox
//    QString message;
//    message += "Server Response Status Code: " + QString::number(response.status_code) + "\n";
//    message += "Server Response Text: " + QString::fromStdString(response.text);
//
//    QMessageBox::information(nullptr, "Server Response Debug", message);
//
//    // Verifică dacă răspunsul este valid
//    if (response.status_code == 200) {
//        QJsonDocument jsonDoc = QJsonDocument::fromJson(QString::fromStdString(response.text).toUtf8());
//
//        if (!jsonDoc.isNull()) {
//            QMessageBox::information(nullptr, "Parsed JSON", jsonDoc.toJson(QJsonDocument::Indented));
//            return jsonDoc;
//        }
//        else {
//            QMessageBox::critical(nullptr, "Error", "Invalid JSON received from server");
//            throw std::runtime_error("Invalid JSON received from server");
//        }
//    }
//    else {
//        QMessageBox::critical(nullptr, "Error", "Failed to fetch map from server. Status code: " + QString::number(response.status_code));
//        throw std::runtime_error("Failed to fetch map from server. Status code: " + std::to_string(response.status_code));
//    }
//}


//QJsonDocument ClientServer::GetMap() {
//    auto response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/get_map" });
//
//    QString responseText = QString::fromStdString(response.text);
//   // std::cout << "Raw Server Response: " << responseText.toStdString() << std::endl;
//
//    // Debug in QMessageBox
//    QString message;
//    message += "Server Response Status Code: " + QString::number(response.status_code) + "\n";
//    message += "Server Response Text: " + responseText;
//
//    QMessageBox::information(nullptr, "Server Response Debug", message);
//
//    // Check response validity
//    if (response.status_code == 200) {
//        QJsonParseError jsonError;
//        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseText.toUtf8(), &jsonError);
//
//        if (jsonError.error == QJsonParseError::NoError) {
//            QMessageBox::information(nullptr, "Parsed JSON", jsonDoc.toJson(QJsonDocument::Indented));
//            return jsonDoc;
//        }
//        else {
//            QMessageBox::critical(nullptr, "JSON Parsing Error", "Error: " + jsonError.errorString());
//            throw std::runtime_error("JSON Parsing Error: " + jsonError.errorString().toStdString());
//        }
//    }
//    else {
//        QMessageBox::critical(nullptr, "Error", "Failed to fetch map from server. Status code: " + QString::number(response.status_code));
//        throw std::runtime_error("Failed to fetch map from server. Status code: " + std::to_string(response.status_code));
//    }
//}

//QJsonDocument ClientServer::GetMap() {
//    auto response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/get_map" });
//
//    QString responseText = QString::fromStdString(response.text);
//    QJsonParseError jsonError;
//    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseText.toUtf8(), &jsonError);
//
//    if (jsonError.error != QJsonParseError::NoError) {
//        QMessageBox::critical(nullptr, "JSON Parsing Error", "Error: " + jsonError.errorString());
//        throw std::runtime_error("JSON Parsing Error: " + jsonError.errorString().toStdString());
//    }
//
//    // Debug: Display the parsed JSON
//    QMessageBox::information(nullptr, "Parsed JSON", jsonDoc.toJson(QJsonDocument::Indented));
//
//    // Process the map data
//    QJsonObject rootObj = jsonDoc.object();
//    int width = rootObj["width"].toInt();
//    int height = rootObj["height"].toInt();
//    QJsonObject cells = rootObj["cells"].toObject();
//
//    for (const QString& rowKey : cells.keys()) {
//        QJsonObject row = cells[rowKey].toObject();
//        for (const QString& colKey : row.keys()) {
//            QJsonObject cell = row[colKey].toObject();
//            int type = cell["type"].toInt();
//            bool border = cell["border"].toBool();
//
//            // Example: Log cell information
//            qDebug() << "Cell (" << rowKey << "," << colKey << "): Type =" << type << ", Border =" << border;
//        }
//    }
//
//    return jsonDoc;
//}
//


//QJsonDocument ClientServer::GetMap() {
//    auto response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/get_map" });
//
//    // Convert server response to QString for parsing
//    QString responseText = QString::fromStdString(response.text);
//
//    // Parse the JSON response
//    QJsonParseError jsonError;
//    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseText.toUtf8(), &jsonError);
//
//    // Check for JSON parsing errors
//    if (jsonError.error != QJsonParseError::NoError) {
//        QMessageBox::critical(nullptr, "JSON Parsing Error", "Error: " + jsonError.errorString());
//        throw std::runtime_error("JSON Parsing Error: " + jsonError.errorString().toStdString());
//    }
//
//    // Debug: Display the parsed JSON
//    QMessageBox::information(nullptr, "Parsed JSON", jsonDoc.toJson(QJsonDocument::Indented));
//
//    // Process the map data
//    QJsonObject rootObj = jsonDoc.object();
//    int width = rootObj["width"].toInt();
//    int height = rootObj["height"].toInt();
//
//    qDebug() << "Map Dimensions: " << width << "x" << height;
//
//    // Process "cells" as an array
//    QJsonArray cells = rootObj["cells"].toArray();
//    for (int i = 0; i < cells.size(); ++i) {
//        QJsonArray row = cells[i].toArray();
//        for (int j = 0; j < row.size(); ++j) {
//            QJsonObject cell = row[j].toObject();
//
//            int type = cell["type"].toInt();
//            bool border = cell["border"].toBool();
//
//            // Log cell information
//            qDebug() << "Cell (" << i << "," << j << "): Type =" << type << ", Border =" << border;
//        }
//    }
//
//    return jsonDoc;
//}


//......................................................................................................................
//void ClientServer::FetchAndProcessMap() {
//    try {
//        // Perform GET request
//        auto response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/get_map" });
//
//        // Log raw response for debugging
//        if (response.text.empty()) {
//            QMessageBox::information(nullptr, "Error", "The server returned an empty response 111111.");
//        }
//
//        QString responseText = QString::fromStdString(response.text);
//        qDebug() << "Raw Response:" << responseText;
//
//        // Check if response is empty
//        if (responseText.isEmpty()) {
//            QMessageBox::information(nullptr, "Error", "The server returned an empty response.");
//            return;
//        }
//        responseText = responseText.trimmed();
//
//
//        // Parse JSON response
//        QJsonParseError jsonError;
//        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseText.toUtf8(), &jsonError);
//
//        // Check if JSON parsing failed
//        if (jsonDoc.isNull()) {
//            QMessageBox::critical(nullptr, "Error", "Invalid JSON received from server.");
//            qDebug() << "JSON Parsing Error:" << jsonError.errorString();
//            return;
//        }
//
//        // Process the JSON document
//        QJsonObject rootObj = jsonDoc.object();
//        int width = rootObj["width"].toInt();
//        int height = rootObj["height"].toInt();
//        QJsonArray mapArray = rootObj["map"].toArray();
//
//        qDebug() << "Map Dimensions:" << width << "x" << height;
//        for (int i = 0; i < mapArray.size(); ++i) {
//            QJsonArray row = mapArray[i].toArray();
//            QString rowString;
//            for (int j = 0; j < row.size(); ++j) {
//                int cell = row[j].toInt();
//                rowString += QString::number(cell) + " ";
//            }
//            qDebug() << "Row" << i << ":" << rowString;
//        }
//    }
//    catch (const std::exception& e) {
//        QMessageBox::critical(nullptr, "Error", e.what());
//    }
//}
//..............................................................................................................................
//void ClientServer::FetchAndProcessMap() {
//    try {
//        // Perform GET request
//        auto response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/get_map" });
//
//        // Log raw response for debugging
//        QString responseText = QString::fromStdString(response.text);
//        qDebug() << "Raw JSON Response:" << responseText;
//
//        if (responseText.trimmed().isEmpty()) {
//            QMessageBox::critical(nullptr, "Error", "The server returned an empty response.");
//            return;
//        }
//
//        // Parse JSON response
//        QJsonParseError jsonError;
//        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseText.toUtf8(), &jsonError);
//
//        if (jsonDoc.isNull()) {
//            QMessageBox::critical(nullptr, "JSON Parsing Error", "Error: " + jsonError.errorString());
//            qDebug() << "JSON Parsing Error:" << jsonError.errorString();
//            return;
//        }
//
//        // Extract JSON data
//        QJsonObject rootObj = jsonDoc.object();
//        int width = rootObj["width"].toInt();
//        int height = rootObj["height"].toInt();
//        QJsonArray mapArray = rootObj["map"].toArray();
//
//        qDebug() << "Map Dimensions: " << width << "x" << height;
//
//        // Process the map array
//        for (int i = 0; i < mapArray.size(); ++i) {
//            QJsonArray row = mapArray[i].toArray();
//            QString rowString;
//            for (int j = 0; j < row.size(); ++j) {
//                int cell = row[j].toInt();
//                rowString += QString::number(cell) + " ";
//            }
//            qDebug() << "Row " << i << ": " << rowString;
//        }
//
//    }
//    catch (const std::exception& e) {
//        QMessageBox::critical(nullptr, "Error", e.what());
//        qDebug() << "Exception: " << e.what();
//    }
//}

//void ClientServer::FetchAndProcessMap() {
//    try {
//        // Perform GET request
//        auto response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/get_map" });
//
//        qDebug() << "Response Status Code:" << response.status_code;
//        qDebug() << "Raw Response Text:" << QString::fromStdString(response.text);
//        qDebug() << "Raw JSON Response:" << QString::fromStdString(response.text);
//
//        // Check for empty response
//        if (response.text.empty()) {
//            QMessageBox::critical(nullptr, "Error", "The server returned an empty response.");
//            return;
//        }
//
//        // Parse JSON response
//        QJsonParseError jsonError;
//        QJsonDocument jsonDoc = QJsonDocument::fromJson(QString::fromStdString(response.text).toUtf8(), &jsonError);
//
//        if (jsonDoc.isNull()) {
//            QMessageBox::critical(nullptr, "JSON Parsing Error", "Error: " + jsonError.errorString());
//            qDebug() << "JSON Parsing Error:" << jsonError.errorString();
//            return;
//        }
//
//        // Extract JSON data
//        QJsonObject rootObj = jsonDoc.object();
//        int width = rootObj["width"].toInt();
//        int height = rootObj["height"].toInt();
//        QJsonArray mapArray = rootObj["map"].toArray();
//
//        qDebug() << "Map Dimensions: " << width << "x" << height;
//
//        // Process the map array
//        for (int i = 0; i < mapArray.size(); ++i) {
//            QJsonArray row = mapArray[i].toArray();
//            QString rowString;
//            for (int j = 0; j < row.size(); ++j) {
//                int cell = row[j].toInt();
//                rowString += QString::number(cell) + " ";
//            }
//            qDebug() << "Row " << i << ": " << rowString;
//        }
//
//    }
//    catch (const std::exception& e) {
//        QMessageBox::critical(nullptr, "Error", e.what());
//        qDebug() << "Exception: " << e.what();
//    }
//}
//void ClientServer::FetchAndProcessMap() {
//    try {
//        // Perform GET request
//        auto response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/get_map" });
//
//        // Debugging - Log response status and content
//        qDebug() << "Response Status Code:" << response.status_code;
//        qDebug() << "Raw Response Text:" << QString::fromStdString(response.text);
//        //Alte testari
//        qDebug() << "Status Code:" << response.status_code;
//        qDebug() << "Error Message (if any):" << QString::fromStdString(response.error.message);
//        qDebug() << "Raw Response Text:" << QString::fromStdString(response.text);
//
//        // Check for empty response
//        if (response.text.empty()) {
//            QMessageBox::critical(nullptr, "Error", "The server returned an empty response.");
//            return;
//        }
//
//        // Parse JSON response
//        QJsonParseError jsonError;
//        QJsonDocument jsonDoc = QJsonDocument::fromJson(QString::fromStdString(response.text).toUtf8(), &jsonError);
//
//        // Check for JSON parsing errors
//        if (jsonDoc.isNull()) {
//            QMessageBox::critical(nullptr, "JSON Parsing Error", "Error: " + jsonError.errorString());
//            qDebug() << "JSON Parsing Error:" << jsonError.errorString();
//            return;
//        }
//
//        // Debugging - Log parsed JSON
//        qDebug() << "Parsed JSON:" << jsonDoc.toJson(QJsonDocument::Indented);
//
//        // Extract JSON data
//        QJsonObject rootObj = jsonDoc.object();
//        int width = rootObj["width"].toInt();
//        int height = rootObj["height"].toInt();
//        QJsonArray mapArray = rootObj["map"].toArray();
//
//        // Debugging - Log map dimensions
//        qDebug() << "Map Dimensions: " << width << "x" << height;
//
//        // Process the map array
//        for (int i = 0; i < mapArray.size(); ++i) {
//            QJsonArray row = mapArray[i].toArray();
//            QString rowString;
//            for (int j = 0; j < row.size(); ++j) {
//                int cell = row[j].toInt();
//                rowString += QString::number(cell) + " ";
//            }
//            // Debugging - Log each row
//            qDebug() << "Row " << i << ": " << rowString;
//        }
//
//    }
//    catch (const std::exception& e) {
//        // Handle exceptions
//        QMessageBox::critical(nullptr, "Error", e.what());
//        qDebug() << "Exception: " << e.what();
//    }
//}

//void ClientServer::FetchAndProcessMap() {
//    try {
//        // Perform GET request
//        auto response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/get_map" });
//
//        // Debugging - Log response status and content
//        qDebug() << "Response Status Code:" << response.status_code;
//        qDebug() << "Raw Response Text:" << QString::fromStdString(response.text);  // Log the raw response text
//
//        // Verifică dacă răspunsul este gol
//        if (response.text.empty()) {
//            qDebug() << "Server returned an empty response.";
//            QMessageBox::critical(nullptr, "Error", "The server returned an empty response.");
//            return;
//        }
//
//        // Verify if the content is in JSON format
//        if (response.text.find("{") != std::string::npos) {
//            qDebug() << "Server returned a valid JSON response.";
//        }
//        else {
//            qDebug() << "The response is not a valid JSON.";
//            QMessageBox::critical(nullptr, "Error", "The server did not return a valid JSON.");
//            return;
//        }
//
//        // Parse JSON response
//        QJsonParseError jsonError;
//        QJsonDocument jsonDoc = QJsonDocument::fromJson(QString::fromStdString(response.text).toUtf8(), &jsonError);
//
//        // Check for JSON parsing errors
//        if (jsonDoc.isNull()) {
//            QMessageBox::critical(nullptr, "JSON Parsing Error", "Error: " + jsonError.errorString());
//            qDebug() << "JSON Parsing Error:" << jsonError.errorString();
//            return;
//        }
//
//        // Debugging - Log parsed JSON
//        qDebug() << "Parsed JSON:" << jsonDoc.toJson(QJsonDocument::Indented);
//
//        // Extract JSON data
//        QJsonObject rootObj = jsonDoc.object();
//        int width = rootObj["width"].toInt();
//        int height = rootObj["height"].toInt();
//        QJsonArray mapArray = rootObj["map"].toArray();
//
//        // Debugging - Log map dimensions
//        qDebug() << "Map Dimensions: " << width << "x" << height;
//
//        // Process the map array
//        for (int i = 0; i < mapArray.size(); ++i) {
//            QJsonArray row = mapArray[i].toArray();
//            QString rowString;
//            for (int j = 0; j < row.size(); ++j) {
//                int cell = row[j].toInt();
//                rowString += QString::number(cell) + " ";
//            }
//            // Debugging - Log each row
//            qDebug() << "Row " << i << ": " << rowString;
//        }
//
//    }
//    catch (const std::exception& e) {
//        // Handle exceptions
//        QMessageBox::critical(nullptr, "Error", e.what());
//        qDebug() << "Exception: " << e.what();
//    }
//}

//void ClientServer::FetchAndProcessMap()
//{
//    qDebug() << "Am intrat in metoda FetchAndProcessMap.";
//    try {
//        // Trimite cererea GET către server pentru a obține harta
//        cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:8080/get_map" });
//        // qDebug() << "Am intrat in clasa FetchAndProcessMap";
//
//        if (response.status_code == 200) {
//            // Parsează răspunsul JSON folosind biblioteca nlohmann::json
//            json mapData = json::parse(response.text);
//
//            // Afișează dimensiunile hărții
//            int width = mapData["width"];
//            int height = mapData["height"];
//            std::cout << "Map Dimensions: " << width << " x " << height << std::endl;
//            qDebug() << "Dimensiunile hartii sunt " << width << " x " << height;
//
//            // Afișează harta în formatul unui tablou
//            json mapArray = mapData["map"];
//
//            // Convertește `mapArray` din json la `QJsonArray` pentru a-l folosi în Qt
//            QJsonArray qMapArray;
//            for (const auto& row : mapArray) {
//                QJsonArray qRow;
//                for (const auto& cell : row) {
//                    qRow.append(QJsonValue(static_cast<int>(cell)));  // Adaugă celula ca QJsonValue
//                }
//                qMapArray.append(qRow);
//            }
//
//            // Salvează qMapArray într-o variabilă globală sau membru pentru utilizare ulterioară
//            this->mapData = qMapArray;  // Presupunând că ai definit `QJsonArray mapData` în ClientServer
//        }
//        else {
//            std::cout << "Failed to fetch map: " << response.status_code << std::endl;
//        }
//    }
//    catch (const std::exception& ex) {
//        std::cerr << "Exception: " << ex.what() << std::endl;
//    }
//}
void ClientServer::FetchAndProcessMap()
{
    qDebug() << "Am intrat in metoda FetchAndProcessMap.";
    try {
        // Trimite cererea GET către server pentru a obține harta
        cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:8080/get_map" });

        if (response.status_code == 200) {
            // Parsează răspunsul JSON folosind biblioteca nlohmann::json
            json mapData = json::parse(response.text);

            // Afișează dimensiunile hărții
            int width = mapData["width"];
            int height = mapData["height"];
            std::cout << "Map Dimensions: " << width << " x " << height << std::endl;
            qDebug() << "Dimensiunile hartii sunt " << width << " x " << height;

            // Afișează harta în formatul unui tablou
            json mapArray = mapData["map"];

            // Convertește `mapArray` din json la `QJsonArray` pentru a-l folosi în Qt
            QJsonArray qMapArray;
            for (const auto& row : mapArray) {
                QJsonArray qRow;
                for (const auto& cell : row) {
                    qRow.append(QJsonValue(static_cast<int>(cell)));  // Adaugă celula ca QJsonValue
                }
                qMapArray.append(qRow);
            }

            // Emit semnalul cu harta procesată
            //emit mapDataReady(qMapArray);
        }
        else {
            std::cout << "Failed to fetch map: " << response.status_code << std::endl;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
}


//bool ClientServer::CheckCode()
//{
//    try {
//        auto response = cpr::Post(
//            cpr::Url{ std::string(SERVER_URL) + "/check_code" }//,
//            /*cpr::Body{ "{\"username\":\"" + username + "\"}" },
//            cpr::Header{ {"Content-Type", "application/json"} }*/
//        );

//        if (response.status_code == 200) {
//            std::cout << "Login successful: " << response.text << std::endl;
//            return true;
//        }
//        else {
//            std::cerr << "Login failed: " << response.text << " (Code: " << response.status_code << ")" << std::endl;
//            return false;
//        }
//    }
//    catch (const std::exception& ex) {
//        std::cerr << "Exception during login: " << ex.what() << std::endl;
//        return false;
//    }
//}
bool ClientServer::JoinGame(const std::string& gameCode, const std::string& username)
{
    try {
        // Create a JSON object with the game code and username
        nlohmann::json jsonBody;
        jsonBody["game_code"] = gameCode;
        jsonBody["username"] = username;

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


//bool ClientServer::JoinGame(const std::string& gameCode, const std::string& username) {
//    try {
//        // Create a JSON object with the game code and username
//        nlohmann::json jsonBody;
//        jsonBody["game_code"] = gameCode;
//        jsonBody["username"] = username;
//
//        // Convert the JSON object to a string
//        std::string jsonString = jsonBody.dump();
//
//        // Send a POST request to the server to join the game
//        cpr::Response response = cpr::Post(
//            cpr::Url{ std::string(SERVER_URL) + "/join_game" },
//            cpr::Body{ jsonString },
//            cpr::Header{ {"Content-Type", "application/json"} }
//        );
//
//        if (response.status_code == 200) {
//            std::cout << "Successfully joined the game: " << response.text << std::endl;
//            return true;
//        }
//        else {
//            std::cerr << "Failed to join the game. Server response: " << response.status_code << " " << response.text << std::endl;
//            return false;
//        }
//    }
//    catch (const std::exception& ex) {
//        std::cerr << "Exception during joining the game: " << ex.what() << std::endl;
//        return false;
//    }
//}



std::string ClientServer::GenerateCode(uint8_t level)
{
    try {
        // Include the level in the request URL or as a query parameter
        cpr::Response response = cpr::Get(
            cpr::Url{ std::string(SERVER_URL) + "/generate_code" },
            cpr::Parameters{ {"level", std::to_string(level)} }  // Send the level as a query parameter
        );

        if (response.status_code == 200) {
            std::cout << "Generated Game Code: " << response.text << std::endl;
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


//bool ClientServer::JoinGame(const std::string& gameCode, const std::string& username)
//{
//    try {
//        nlohmann::json jsonBody;
//        jsonBody["game_code"] = gameCode;
//        jsonBody["username"] = username;

//        std::string jsonString = jsonBody.dump();  // Convert JSON to string

//        cpr::Response response = cpr::Post(
//            cpr::Url{ std::string(SERVER_URL) + "/join_game" },
//            cpr::Body{ jsonString },
//            cpr::Header{ {"Content-Type", "application/json"} }
//        );

//        if (response.status_code == 200) {
//            std::cout << "Joined the game successfully: " << response.text << std::endl;
//            return true;
//        }
//        else {
//            std::cerr << "Failed to join game: " << response.status_code << " " << response.text << std::endl;
//            return false;
//        }
//    }
//    catch (const std::exception& ex) {
//        std::cerr << "Exception during joining game: " << ex.what() << std::endl;
//        return false;
//    }
//}


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



//void Client::onChooseLevel(const std::string& clientId, const std::string& level) {
//    // std::string clientId = clientIdInput->text().toStdString();
//     /*if (clientId.empty()) {
//         QMessageBox::warning(this, "Error", "Client ID is required!");
//         return;
//     }*/
//
//    cpr::Response r = cpr::Post(
//        cpr::Url{ "http://localhost:8080/choose_level" },
//        cpr::Header{ {"Client-ID", clientId} },
//        cpr::Body{ level }
//    );
//
//    if (r.status_code == 200) {
//        outputLabel->setText("Level chosen successfully: " + QString::fromStdString(r.text));
//    }
//    else {
//        outputLabel->setText("Error choosing level: " + QString::fromStdString(r.text));
//    }
//}
//
//void Client::onChooseSmall() {
//    onChooseLevel(clientId, "Easy");
//}
//
//void Client::onChooseMedium() {
//    onChooseLevel("Medium");
//}
//
//void Client::onChooseLarge() {
//    onChooseLevel("Hard");
//}
//
//
//
//#include "Client.h"
//#include <QMessageBox>
//
//Client::Client(QWidget* parent) : QWidget(parent) {
//    QVBoxLayout* layout = new QVBoxLayout(this);
//
//    // Input pentru Client ID și Level
//    clientIdInput = new QLineEdit(this);
//    clientIdInput->setPlaceholderText("Enter Client ID");
//    levelInput = new QLineEdit(this);
//    levelInput->setPlaceholderText("Enter Level (Usor, Mediu, Greu)");
//
//    QPushButton* chooseLevelButton = new QPushButton("Choose Level", this);
//    QPushButton* getMapButton = new QPushButton("Get Map", this);
//
//    QPushButton* moveUpButton = new QPushButton("Move Up", this);
//    QPushButton* moveDownButton = new QPushButton("Move Down", this);
//    QPushButton* moveLeftButton = new QPushButton("Move Left", this);
//    QPushButton* moveRightButton = new QPushButton("Move Right", this);
//
//    outputLabel = new QLabel(this);
//
//    // Adăugăm widget-uri la layout
//    layout->addWidget(clientIdInput);
//    layout->addWidget(levelInput);
//    layout->addWidget(chooseLevelButton);
//    layout->addWidget(getMapButton);
//    layout->addWidget(moveUpButton);
//    layout->addWidget(moveDownButton);
//    layout->addWidget(moveLeftButton);
//    layout->addWidget(moveRightButton);
//    layout->addWidget(outputLabel);
//
//    setLayout(layout);
//
//    // Conectăm butoanele la sloturi
//    connect(chooseLevelButton, &QPushButton::clicked, this, &Client::onChooseLevel);
//    connect(getMapButton, &QPushButton::clicked, this, &Client::onGetMap);
//    connect(moveUpButton, &QPushButton::clicked, this, &Client::onMoveTankUp);
//    connect(moveDownButton, &QPushButton::clicked, this, &Client::onMoveTankDown);
//    connect(moveLeftButton, &QPushButton::clicked, this, &Client::onMoveTankLeft);
//    connect(moveRightButton, &QPushButton::clicked, this, &Client::onMoveTankRight);
//}
//
//void Client::onChooseLevel() {
//    std::string clientId = clientIdInput->text().toStdString();
//    std::string level = levelInput->text().toStdString();
//
//    cpr::Response r = cpr::Post(
//        cpr::Url{ "http://localhost:8080/choose_level" },
//        cpr::Header{ {"Client-ID", clientId} },
//        cpr::Body{ level }
//    );
//
//    if (r.status_code == 200) {
//        outputLabel->setText("Level chosen successfully: " + QString::fromStdString(r.text));
//    }
//    else {
//        outputLabel->setText("Error choosing level: " + QString::fromStdString(r.text));
//    }
//}
//
//void Client::onGetMap() {
//    std::string clientId = clientIdInput->text().toStdString();
//    std::string level = levelInput->text().toStdString();
//
//    cpr::Response r = cpr::Get(
//        cpr::Url{ "http://localhost:8080/get_map" },
//        cpr::Header{ {"Client-ID", clientId} },
//        cpr::Body{ level }
//    );
//
//    if (r.status_code == 200) {
//        //outputLabel->setText("Map retrieved successfully! JSON:\n" + QString::fromStdString(r.text));
//        outputLabel->setText("Map retrieved successfully! JSON:\n");
//    }
//    else {
//        outputLabel->setText("Error retrieving map: " + QString::fromStdString(r.text));
//    }
//}
//
//void Client::sendMoveRequest(const std::string& direction) {
//    std::string clientId = clientIdInput->text().toStdString();
//    std::string url = "http://localhost:8080/move_tank/" + direction + "?id=" + clientId;
//
//    cpr::Response r = cpr::Get(cpr::Url{ url });
//
//    if (r.status_code == 200) {
//        outputLabel->setText("Move successful: " + QString::fromStdString(r.text));
//    }
//    else {
//        outputLabel->setText("Move error: " + QString::fromStdString(r.text));
//    }
//}
//
//void Client::onMoveTankUp() {
//    sendMoveRequest("up");
//}
//
//void Client::onMoveTankDown() {
//    sendMoveRequest("down");
//}
//
//void Client::onMoveTankLeft() {
//    sendMoveRequest("left");
//}
//
//void Client::onMoveTankRight() {
//    sendMoveRequest("right");
//}

