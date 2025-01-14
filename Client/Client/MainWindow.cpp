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
void MainWindow::CreateJoinWindow()
{
    CreateOrJoinGameWindow* createJoinWindow = new CreateOrJoinGameWindow();
    createJoinWindow->show();
    connect(createJoinWindow, &CreateOrJoinGameWindow::GeneralSettings, this, &MainWindow::HandleGeneralSettings);
    connect(createJoinWindow, &CreateOrJoinGameWindow::Generate, this, &MainWindow::HandleCreateCode);
    connect(createJoinWindow, &CreateOrJoinGameWindow::CheckCode, this, &MainWindow::HandleCheckCode);
}
void MainWindow::HandleLogin(const QString& username)
{
    std::string stdUsername = username.toUtf8().constData();

    if (ClientServer::LoginClient(stdUsername)) {
        QMessageBox::information(this, "Login", "Welcome, " + username + "!");
       CreateJoinWindow();
        close();
        //DisplayMap();
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


    std::string controlsStr= jsonString.toUtf8().constData();
    if (ClientServer::ControlsClient(controlsStr))
    {
        QMessageBox::information(this, "Success", "Controls have been successfully set!");
        CreateJoinWindow();
    }
    else
        QMessageBox::warning(this, "Error", "Failed to set controls: ");
   

}
void MainWindow::HandleCreateCode()
{
    LevelSelectionWindow* levelWindow = new LevelSelectionWindow();
    levelWindow->show();

    connect(levelWindow, &LevelSelectionWindow::LevelEasy, this, &MainWindow::HandleLevel1);
    connect(levelWindow, &LevelSelectionWindow::LevelMediu, this, &MainWindow::HandleLevel2);
    connect(levelWindow, &LevelSelectionWindow::LevelHard, this, &MainWindow::HandleLevel3);

}
void MainWindow::GameWindow()
{
    GameMapWindow* gameMapWindow = new GameMapWindow();
    gameMapWindow->show();
    connect(gameMapWindow, &GameMapWindow::SettingsClicked, this, &MainWindow::HandleInGameSettings);
}
void MainWindow::HandleCheckCode()
{
    if (ClientServer::CheckCode()) {
        QMessageBox::information(this, "Success", "Code verified. Loading game map...");

        // Creează și afișează fereastra GameMapWindow
        GameWindow();
    }
    else {
        QMessageBox::warning(this, "Error", "Invalid code. Please try again.");
    }
}
void MainWindow::HandleLevel1()
{
    // Call GenerateCode and store the returned game code
    std::string gameCode = ClientServer::GenerateCode(1);

    if (gameCode.empty()) {
        QMessageBox::information(this, "Error", "Failed to generate code.");
    }
    else {
        // Show the generated game code in a message box
        QMessageBox::information(this, "Success", "Generated Game Code: " + QString(gameCode.c_str()));
    }

    // Proceed with other logic
    QMessageBox::information(this, "Success", "Level 1");
    GameWindow();
}

void MainWindow::HandleLevel2()
{
    // Call GenerateCode and store the returned game code
    std::string gameCode = ClientServer::GenerateCode(2);

    if (gameCode.empty()) {
        QMessageBox::information(this, "Error", "Failed to generate code.");
    }
    else {
        // Show the generated game code in a message box
        QMessageBox::information(this, "Success", "Generated Game Code: " + QString::fromStdString(gameCode));
    }

    // Proceed with other logic
    QMessageBox::information(this, "Success", "Level 1");
    GameWindow();
}
void MainWindow::HandleLevel3()
{
    // Call GenerateCode and store the returned game code
    std::string gameCode = ClientServer::GenerateCode(3);

    if (gameCode.empty()) {
        QMessageBox::information(this, "Error", "Failed to generate code.");
    }
    else {
        // Show the generated game code in a message box
        QMessageBox::information(this, "Success", "Generated Game Code: " + QString::fromStdString(gameCode));
    }

    // Proceed with other logic
    QMessageBox::information(this, "Success", "Level 1");
    GameWindow();
}


//void MainWindow::HandleLevel1()
//{
//
//    if (!ClientServer::GenerateCode(1))
//        QMessageBox::information(this, "Error", "Not Generate Code");
//
//    QMessageBox::information(this, "Success", "Generate Code");
//
//    QMessageBox::information(this, "Success", "Level");
//    //ClientServer::Level();
//    GameWindow();
//}
//void MainWindow::HandleLevel2()
//{
//
//    if (!ClientServer::GenerateCode(2))
//        QMessageBox::information(this, "Error", "Not Generate Code");
//
//    QMessageBox::information(this, "Success", "Generate Code");
//
//    QMessageBox::information(this, "Success", "Level");
//    //ClientServer::Level();
//    GameWindow();
//}
//void MainWindow::HandleLevel3()
//{
//
//    if (!ClientServer::GenerateCode(3))
//        QMessageBox::information(this, "Error", "Not Generate Code");
//
//    QMessageBox::information(this, "Success", "Generate Code");
//
//    QMessageBox::information(this, "Success", "Level");
//   // ClientServer::Level();
//    GameWindow();
//}
// 
// 
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
    connect(settingsWindow, &InGameSettingsWindow::editControls, this, &MainWindow::HandleEditControls);
    connect(settingsWindow, &InGameSettingsWindow::SaveSettings, this, &MainWindow::HandleSaveSettings);
}
void MainWindow::HandleGeneralSettings()
{
    GeneralSettingsWindow* generalSettings = new GeneralSettingsWindow(this);
    generalSettings->show();
    connect(generalSettings, &GeneralSettingsWindow::SaveSettings, this, &MainWindow::HandleSaveSettings);
    connect(generalSettings, &GeneralSettingsWindow::EditControls, this, &MainWindow::HandleEditControls);
    connect(generalSettings, &GeneralSettingsWindow::Logout, this, &MainWindow::HandleLogOut);
    connect(generalSettings, &GeneralSettingsWindow::Delete, this, &MainWindow::HandleDeleteAccount);
}
void MainWindow::HandleBackToGameSetting()
{
    /*settingsWindow->close(); 
    gameMapWindow->show();  
    gameMapWindow->raise(); */
}
void MainWindow::HandleExitGameSetting()
{
    CreateJoinWindow();
}
void MainWindow::HandleEditControls()
{
  
}
void MainWindow::HandleLogOut()
{
    LogUserWindow();
}
void MainWindow::HandleDeleteAccount()
{
}
void MainWindow::HandleSaveSettings()
{
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

