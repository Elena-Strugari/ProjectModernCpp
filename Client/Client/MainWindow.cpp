#include "MainWindow.h"
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
        GameWindow();  // Transition to the game window
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
        GameWindow();
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
        GameWindow();
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
        GameWindow();
        DisplayCode(QString(gameCode.c_str()));
    }
}

void MainWindow::GameWindow()
{
    GameMapWindow* gameMapWindow = new GameMapWindow();
    gameMapWindow->show();
    connect(gameMapWindow, &GameMapWindow::SettingsClicked, this, &MainWindow::HandleInGameSettings);
    DisplayMap();
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
}
void MainWindow::HandleGeneralSettings()
{
    GeneralSettingsWindow* generalSettings = new GeneralSettingsWindow(this);
    generalSettings->show();
}
void MainWindow::DisplayMap() {
    try {
        ClientServer client;
        client.FetchAndProcessMap();
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}


