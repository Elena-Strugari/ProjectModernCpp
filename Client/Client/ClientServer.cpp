#pragma once
#include "ClientServer.h"
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

bool ClientServer::ControlsClient(const std::string& controlsClient)
{
    return false;
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

