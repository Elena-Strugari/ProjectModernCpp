﻿#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>


#include "ClientServer.h"
#include "StartGameWindow.h"
#include "LoginWindow.h"
#include "ControlChoiceWindow.h"
#include "CreateOrJoinGameWindow.h"
#include "LevelSelectionWindow.h"
#include "GameMapWindow.h"
#include "InGameSettingsWindow.h"
#include "GeneralSettingsWindow.h"
#include "DisplayCodeWindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connectServer();
    StartGameWindoww();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::connectServer() {
    try {
        ClientServer::connectServer();
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}


void MainWindow::StartGameWindoww() {
    try {
        StartGameWindow* startGameWindow = new StartGameWindow(this);
        setCentralWidget(startGameWindow);
        connect(startGameWindow, &StartGameWindow::startGame, this, &MainWindow::onStartGameClicked);
        ClientServer::StartGameWindow();
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void MainWindow::onStartGameClicked() {
    LogUserWindow();
}

void MainWindow::LogUserWindow()
{
    try {
        LoginWindow* loginWindow = new LoginWindow();
        loginWindow->show();
        ClientServer::verificare();

        connect(loginWindow, &LoginWindow::Login, this, &MainWindow::HandleLogin);
        connect(loginWindow, &LoginWindow::RegisterUser, this, &MainWindow::HandleRegister);
        close();
        ClientServer::UserWindow();
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void MainWindow::HandleLogin(const QString& username)
{
    std::string stdUsername = username.toUtf8().constData();

    if (ClientServer::LoginClient(stdUsername)) {
        QMessageBox::information(this, "Login", "Welcome, " + username + "!");
        CreateJoinWindow();
        close();
      //  DisplayMap();
    }
    else {
        QMessageBox::warning(this, "Error", "Login failed. This name does not exist.");
    }

}

void MainWindow::HandleRegister(const QString& username)
{
    std::string stdUsername = username.toUtf8().constData();

    if (ClientServer::RegisterClient(stdUsername)) {
        QMessageBox::information(this, "Joined", "Welcome, " + username + "!");
        ControlChoiceWindow* controlWindow = new ControlChoiceWindow(username);
        controlWindow->show();
        connect(controlWindow, &ControlChoiceWindow::ControlsSet, this, &MainWindow::HandleControlsSet);

    }
    else {
        QMessageBox::warning(this, "Error", "Registration failed. Please try again.");
    }
}

void MainWindow::HandleControlsSet(const QMap<QString, QString>& controls, const QString& username)
{
    QJsonObject jsonObject;
    jsonObject.insert("username", username);
    for (auto it = controls.begin(); it != controls.end(); ++it) {
        jsonObject.insert(it.key(), it.value());
    }
    QJsonDocument jsonDoc(jsonObject);
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    QMessageBox::information(this, "JSON Sent to Server", "The following JSON was sent:\n\n" + jsonString);


    std::string controlsStr = jsonString.toUtf8().constData();
    if (ClientServer::ControlsClient(controlsStr))
    {
        QMessageBox::information(this, "Success", "Controls have been successfully set!");
        CreateJoinWindow();
    }
    else
        QMessageBox::warning(this, "Error", "Failed to set controls: ");


}

void MainWindow::CreateJoinWindow()
{
    CreateOrJoinGameWindow* createJoinWindow = new CreateOrJoinGameWindow();
    createJoinWindow->show();
    connect(createJoinWindow, &CreateOrJoinGameWindow::GeneralSettings, this, &MainWindow::HandleGeneralSettings);
    connect(createJoinWindow, &CreateOrJoinGameWindow::Generate, this, &MainWindow::HandleCreateCode);
    connect(createJoinWindow, &CreateOrJoinGameWindow::CheckCode, this, &MainWindow::HandleCheckCode);
}

void MainWindow::HandleCreateCode()
{
    LevelSelectionWindow* levelWindow = new LevelSelectionWindow();
    levelWindow->show();

    connect(levelWindow, &LevelSelectionWindow::LevelEasy, this, &MainWindow::HandleLevel1);
    connect(levelWindow, &LevelSelectionWindow::LevelMediu, this, &MainWindow::HandleLevel2);
    connect(levelWindow, &LevelSelectionWindow::LevelHard, this, &MainWindow::HandleLevel3);

}

void MainWindow::HandleCheckCode(const QString& gameCode, const QString& username)
{
    if (ClientServer::JoinGame(gameCode.toUtf8().constData(), username.toUtf8().constData())) {
        QMessageBox::information(this, "Success", "Code verified. Loading game map...");
        GameWindow(gameCode.toUtf8().constData());  // Transition to the game window
    }
    else {
        QMessageBox::warning(this, "Error", "Invalid code. Please try again.");
    }
}

void MainWindow::HandleLevel1()
{
    std::string gameCode = ClientServer::GenerateCode(1);

    if (gameCode.empty()) {
        QMessageBox::information(this, "Error", "Failed to generate code.");
    }
    else {
        GameWindow(gameCode.c_str());
        DisplayCode(QString(gameCode.c_str()));
    }

}

void MainWindow::HandleLevel2()
{
    std::string gameCode = ClientServer::GenerateCode(2);

    if (gameCode.empty()) {
        QMessageBox::information(this, "Error", "Failed to generate code.");
    }
    else {
        GameWindow(gameCode.c_str());
        DisplayCode(QString(gameCode.c_str()));
    }
}
void MainWindow::HandleLevel3()
{
    std::string gameCode = ClientServer::GenerateCode(3);

    if (gameCode.empty()) {
        QMessageBox::information(this, "Error", "Failed to generate code.");
    }
    else {
        GameWindow(gameCode.c_str());
        DisplayCode(QString(gameCode.c_str()));
    }
}

void MainWindow::GameWindow(const QString& gameCode)
{
    //GameMapWindow* gameMapWindow = new GameMapWindow();
    //gameMapWindow->show();
    //connect(gameMapWindow, &GameMapWindow::KeyPressed, this, &MainWindow::HandleKeyPressedOnMap);
    //// de facut rute 
    //connect(gameMapWindow, &GameMapWindow::SettingsClicked, this, &MainWindow::HandleInGameSettings);
    //DisplayMap(gameCode);

        qDebug() << "Am intrat în GameWindow().";

        // Creează o instanță de GameMapWindow
        GameMapWindow* gameMapWindow = new GameMapWindow();
        gameMapWindow->show();

        // Conectează semnalul pentru settingsClicked
        connect(gameMapWindow, &GameMapWindow::SettingsClicked, this, &MainWindow::HandleInGameSettings);

        // Creează o instanță de ClientServer (sau folosește una existentă)
        ClientServer client;
        client.FetchAndProcessMap();
        try {
            // Obține harta de la server folosind metoda getMap
            QJsonArray mapData = client.GetMap();

            // Debug pentru a verifica datele
            qDebug() << "Conținutul mapData obținut de la server:";
            for (const auto& row : mapData) {
                qDebug() << row;
            }

            // Transmite datele către GameMapWindow pentru afișare
            gameMapWindow->displayMap(mapData);
        }
        catch (const std::exception& e) {
            // În caz de eroare, afișează un mesaj de eroare
            QMessageBox::critical(this, "Error", e.what());
        }
}

void MainWindow::HandleKeyPressedOnMap(int key)
{
   /* if (ClientServer::SendKeyPress(key))
    {
       qDebug() << "Key press successfully sent to server.";
    }
    else {
       qDebug() << "Failed to send key press to server.";
    }*/
}


void MainWindow::DisplayCode(const QString& message)
{
    DisplayCodeWindow* displayCode = new DisplayCodeWindow();
    displayCode->setMessage(message);
    displayCode->show();
}

// 
//void MainWindow::DisplayMap() {
//    try {
//        //QJsonDocument response = ClientServer::GetMap();
//        ClientServer::FetchAndProcessMap();
//       /* if (response.isNull()) {
//            throw std::runtime_error("Empty response from server");
//        }
//
//        QJsonObject mapObject = response.object();
//        int width = mapObject["width"].toInt();
//        int height = mapObject["height"].toInt();
//        QJsonArray cells = mapObject["cells"].toArray();
//
//        for (int y = 0; y < height; ++y) {
//            QJsonArray row = cells[y].toArray();
//            for (int x = 0; x < width; ++x) {
//                QJsonObject cell = row[x].toObject();
//                QString type = cell["type"].toString();
//
//                qDebug() << "Cell (" << x << "," << y << "):" << type;
//            }
//        }*/
//    }
//    catch (const std::exception& e) {
//        QMessageBox::critical(this, "Error", e.what());
//    }
//}
void MainWindow::HandleInGameSettings()
{
    InGameSettingsWindow* settingsWindow = new InGameSettingsWindow(this);
    settingsWindow->positionInTopRight(this);
    settingsWindow->show();

    connect(settingsWindow, &InGameSettingsWindow::backToGame, this, &MainWindow::HandleBackToGameSetting);
    connect(settingsWindow, &InGameSettingsWindow::exitGame, this, &MainWindow::HandleExitGameSetting);
    connect(settingsWindow, &InGameSettingsWindow::SaveSettings, this, &MainWindow::HandleSaveSettings);
}

// Slotul în MainWindow care se ocupă de Back to Game
void MainWindow::HandleBackToGameSetting() {
    qDebug() << "Back to game!";
}

// Alte sloturi similare
void MainWindow::HandleExitGameSetting() {
    qDebug() << "Exit game!";
}

void MainWindow::HandleSaveSettings(int volume)
{

    qDebug() << "Save settings!";
    std::string volumeStr = std::to_string(volume);

    // Trimite volumul la server (sau orice alte setări)
    if (ClientServer::SaveSettings(volumeStr)) {
        QMessageBox::information(this, "Success", "General settings have been saved to the server!");
    }
    else {
        QMessageBox::warning(this, "Error", "Failed to save general settings to the server.");
    }

}

void MainWindow::HandleEditControls()
{
    qDebug() << "Edit Controls!";

}

void MainWindow::HandleLogOut()
{
    qDebug() << "LogOut!";

}

void MainWindow::HandleDeleteAccount()
{
    qDebug() << "Delete Account!";

}

void MainWindow::HandleGeneralSettings()
{
    GeneralSettingsWindow* generalSettings = new GeneralSettingsWindow(this);
    generalSettings->show();
    //generalSettings->raise();  // Bring it to the front
    //generalSettings->activateWindow();

    connect(generalSettings, &GeneralSettingsWindow::SaveSettings, this, &MainWindow::HandleSaveSettings);
    connect(generalSettings, &GeneralSettingsWindow::EditControls, this, &MainWindow::HandleEditControls);
    connect(generalSettings, &GeneralSettingsWindow::Logout, this, &MainWindow::HandleLogOut);
    connect(generalSettings, &GeneralSettingsWindow::Delete, this, &MainWindow::HandleDeleteAccount);
}

//void MainWindow::HandleKeyPressedOnMap(int key)
//{
//    if (ClientServer::SendKeyPress(key))
//    {
//        qDebug() << "Key press successfully sent to server.";
//    }
//    else {
//        qDebug() << "Failed to send key press to server.";
//    }
//}
//void MainWindow::DisplayMap(const QString& gameCode) {
//    try {
//        ClientServer client;
//        //client.FetchAndProcessMap();
//        //ClientServer::GetGameMap(gameCode.toUtf8().constData());
//        client.GetGameMap(gameCode.toUtf8().constData());
//    }
//    catch (const std::exception& e) {
//        QMessageBox::critical(this, "Error", e.what());
//    }
//}


