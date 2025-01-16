#pragma once
#include <QtWidgets/QMainWindow>
#include <QJsonArray>
#include <cpr/cpr.h>
#include <string>


class ClientServer
{

public:

	static void connectServer();
	static void StartGameWindow();
	//static void UserWindow();

	static bool LoginClient(const std::string& clientId);

	static bool RegisterClient(const std::string& clientId);

	QJsonArray GetMap();
	static bool JoinGame(const std::string& gameCode, const std::string& username);

	//static std::string GenerateCode(uint8_t level);
	static std::string GenerateCode(uint8_t level, const std::string& username);
	
	void FetchAndProcessMap(const std::string& gameCode);

	static bool ControlsClient(const std::string& controlsClient);
	//static bool verificare();

	static void GetGeneralSettings();
	static bool SetGeneralSettings(const std::string& settingsJson);

	static bool SaveSettings(const std::string& volume);

	static void GetInGameSettings();
	static bool SetInGameSettings(const std::string& settingsJson);
	static bool SendKeyPress(int key);
	static std::string m_username;
private:
	QJsonArray mapData;
};

