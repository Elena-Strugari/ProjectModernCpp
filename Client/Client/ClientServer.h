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
	static bool JoinGame(const std::string& gameCode, const std::string& username);

	static std::string GenerateCode(uint8_t level);
	//static bool CheckCode();

	static void ProcessMap(const QJsonDocument& jsonDoc);
	static void FetchAndProcessMap();

	static bool ControlsClient(const std::string& controlsClient);
	static bool verificare();

	static void GetGeneralSettings();
	static bool SetGeneralSettings(const std::string& settingsJson);

	static void GetInGameSettings();
	static bool SetInGameSettings(const std::string& settingsJson);

private:

};

