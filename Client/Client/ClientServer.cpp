﻿#pragma once
#define _ITERATOR_DEBUG_LEVEL 2

#include "ClientServer.h"
#include <stdexcept>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>

#include <iostream>

constexpr auto SERVER_URL = "http://localhost:8080";
 
void ClientServer::connectServer() {

    try {
        cpr::Response response = cpr::Get(cpr::Url{ std::string(SERVER_URL)+ "/connect"});

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

void ClientServer::StartGameWindow()
{
    try {
        cpr::Response response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/startGame" });

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
    QString name = "John";
    std::string nameS = name.toUtf8().constData();

    // Trimite cererea POST către server
    cpr::Response r = cpr::Post(
        cpr::Url{ std::string(SERVER_URL) + "/sendName" },
        cpr::Body{ nameS },
        cpr::Header{ {"Content-Type", "text/plain"} }
    );

    // Afișează răspunsul serverului
    if (r.status_code == 200) {
        qDebug() << "Registration successful: " << QString::fromStdString(r.text);
        return true;
    }
    else {
        qDebug() << "Registration failed. Status code: " << r.status_code;
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

//bool ClientServer::ControlsClient(const std::string& client, const std::string& controlsClient)
bool ClientServer::ControlsClient(const std::string& controlsClient)
{
    try {
        cpr::Response response = cpr::Post(
            cpr::Url{ std::string(SERVER_URL) + "/controls" },
            cpr::Body{ "{\"controls\":\"" + controlsClient + "\"}"},
            cpr::Header{ {"Content-Type", "application/json"} }
        );

        if (response.status_code == 200) {
            qDebug() << "Success: " << QString::fromStdString(response.text);
            return true;
        }
        else {
            qDebug() << "Error: " << response.status_code;
            return false;
        }
    }
    catch (const std::exception& ex) {
        qDebug() << "Exception during registration: " << ex.what();
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

#include <QMessageBox>
#include <QDebug>

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


//
void ClientServer::FetchAndProcessMap() {
    try {
        // Perform GET request
        auto response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/get_map" });

        // Log raw response for debugging
        if (response.text.empty()) {
            QMessageBox::information(nullptr, "Error", "The server returned an empty response 111111.");
        }

        QString responseText = QString::fromStdString(response.text);
        qDebug() << "Raw Response:" << responseText;

        // Check if response is empty
        if (responseText.isEmpty()) {
            QMessageBox::information(nullptr, "Error", "The server returned an empty response.");
            return;
        }
        responseText = responseText.trimmed();


        // Parse JSON response
        QJsonParseError jsonError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseText.toUtf8(), &jsonError);

        // Check if JSON parsing failed
        if (jsonDoc.isNull()) {
            QMessageBox::critical(nullptr, "Error", "Invalid JSON received from server.");
            qDebug() << "JSON Parsing Error:" << jsonError.errorString();
            return;
        }

        // Process the JSON document
        QJsonObject rootObj = jsonDoc.object();
        int width = rootObj["width"].toInt();
        int height = rootObj["height"].toInt();
        QJsonArray mapArray = rootObj["map"].toArray();

        qDebug() << "Map Dimensions:" << width << "x" << height;
        for (int i = 0; i < mapArray.size(); ++i) {
            QJsonArray row = mapArray[i].toArray();
            QString rowString;
            for (int j = 0; j < row.size(); ++j) {
                int cell = row[j].toInt();
                rowString += QString::number(cell) + " ";
            }
            qDebug() << "Row" << i << ":" << rowString;
        }
    }
    catch (const std::exception& e) {
        QMessageBox::critical(nullptr, "Error", e.what());
    }
}



 void ClientServer::GenerateCode()
 {
     try {
         cpr::Response response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/generate_code" });

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

 bool ClientServer::CheckCode()
 {
     try {
         auto response = cpr::Post(
             cpr::Url{ std::string(SERVER_URL) + "/check_code" }//,
             /*cpr::Body{ "{\"username\":\"" + username + "\"}" },
             cpr::Header{ {"Content-Type", "application/json"} }*/
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

 void ClientServer::Level()
 {
     try {
         cpr::Response response = cpr::Get(cpr::Url{ std::string(SERVER_URL) + "/level" });

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

