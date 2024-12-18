#pragma once
#include "ClientServer.h"
#include <iostream>


void ClientServer::connectServer() {
    std::string server_url = "http://localhost:8080/connect";

    try {
        cpr::Response response = cpr::Get(cpr::Url{ server_url });

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


bool ClientServer::loginClient(const std::string& clientId) {
    try {
        cpr::Response response = cpr::Post(
            cpr::Url{ "http://localhost:8080/login" },
            cpr::Payload{ {"client_id", clientId} }
        );

        if (response.status_code == 200) {
            qDebug() << "Login successful: " << QString::fromStdString(response.text);
            return true;
        }
        else {
            qDebug() << "Login failed. Status code: " << response.status_code;
            return false;
        }
    }
    catch (const std::exception& ex) {
        qDebug() << "Exception during login: " << ex.what();
        return false;
    }
}

bool ClientServer::registerClient(const std::string& clientId) {
    try {
        cpr::Response response = cpr::Post(
            cpr::Url{ "http://localhost:8080/register" },
            cpr::Payload{ {"client_id", clientId} }
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


//void ClientApp::onChooseLevel(const std::string& clientId, const std::string& level) {
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
//void ClientApp::onChooseSmall() {
//    onChooseLevel(clientId, "Easy");
//}
//
//void ClientApp::onChooseMedium() {
//    onChooseLevel("Medium");
//}
//
//void ClientApp::onChooseLarge() {
//    onChooseLevel("Hard");
//}
//
//
//
//#include "ClientApp.h"
//#include <QMessageBox>
//
//ClientApp::ClientApp(QWidget* parent) : QWidget(parent) {
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
//    connect(chooseLevelButton, &QPushButton::clicked, this, &ClientApp::onChooseLevel);
//    connect(getMapButton, &QPushButton::clicked, this, &ClientApp::onGetMap);
//    connect(moveUpButton, &QPushButton::clicked, this, &ClientApp::onMoveTankUp);
//    connect(moveDownButton, &QPushButton::clicked, this, &ClientApp::onMoveTankDown);
//    connect(moveLeftButton, &QPushButton::clicked, this, &ClientApp::onMoveTankLeft);
//    connect(moveRightButton, &QPushButton::clicked, this, &ClientApp::onMoveTankRight);
//}
//
//void ClientApp::onChooseLevel() {
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
//void ClientApp::onGetMap() {
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
//void ClientApp::sendMoveRequest(const std::string& direction) {
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
//void ClientApp::onMoveTankUp() {
//    sendMoveRequest("up");
//}
//
//void ClientApp::onMoveTankDown() {
//    sendMoveRequest("down");
//}
//
//void ClientApp::onMoveTankLeft() {
//    sendMoveRequest("left");
//}
//
//void ClientApp::onMoveTankRight() {
//    sendMoveRequest("right");
//}

