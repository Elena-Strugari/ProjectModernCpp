#pragma once
#include <QtWidgets/QMainWindow>
#include <cpr/cpr.h>


class ClientServer
{

public:

	static void connectServer();
	static void StartGameWindow();
	static void UserWindow();

	static bool LoginClient(const std::string& clientId);

	static bool RegisterClient(const std::string& clientId);


	static QJsonDocument GetMap();

	static void GenerateCode();
	static bool CheckCode();

	static void Level();
	static void ProcessMap(const QJsonDocument& jsonDoc);
	static void FetchAndProcessMap();


	//static bool ControlsClient(const std::string& client, const std::string& controlsClient);
	static bool ControlsClient( const std::string& controlsClient);
	static bool verificare();

	static void GetGeneralSettings();  
	static bool SetGeneralSettings(const std::string& settingsJson);

	static void GetInGameSettings();  
	static bool SetInGameSettings(const std::string& settingsJson);

private:

};


//#include "ui_Client.h"
//
//#include <QWidget>
//#include <QPushButton>
//#include <QLineEdit>
//#include <QLabel>
//#include <QVBoxLayout>
//#include <cpr/cpr.h>
//
////class Client : public QMainWindow
//class Client : public QWidget
//{
//    Q_OBJECT
//
//public:
//
//    explicit Client(QWidget* parent = nullptr);
//    // ~Client();
//
//private slots:
//    void onChooseLevel();
//    void onGetMap();
//    void onMoveTankUp();
//    void onMoveTankDown();
//    void onMoveTankLeft();
//    void onMoveTankRight();
//
//private:
//    //Ui::ClientClass ui;
//
//    QLineEdit* clientIdInput;
//    QLineEdit* levelInput;
//    QLabel* outputLabel;
//
//    void sendMoveRequest(const std::string& direction);
//};
