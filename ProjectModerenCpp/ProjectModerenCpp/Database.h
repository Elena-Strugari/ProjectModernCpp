//#pragma once
//#include <sqlite3.h>
//#include <string>
//
//
//
//class Database
//{
//public:
//    Database(const std::string& dbName);
//    ~Database();
//
//    bool AddClient(const std::string& clientId, int score);
//    bool UpdateScore(const std::string& clientId, int newScore);
//    int GetScore(const std::string& clientId);
//    bool DeleteClient(const std::string& clientId);
//    bool ClientExists(const std::string& clientId);
//    bool SaveKeyBindings(const std::string& clientId, const std::string& up, const std::string& down, const std::string& left, const std::string& right, const std::string& shoot);
//    bool GetKeyBindings(const std::string& username, std::string& up, std::string& down, std::string& left, std::string& right, std::string& shoot);
//
//
//private:
//    std::string databaseName;
//    void InitializeDatabase();
//    sqlite3* db;
//
//};

#pragma once
#include <sqlite3.h>
#include <string>

class Database
{
public:
    Database(const std::string& dbName);
    ~Database();

    bool AddClient(const std::string& clientId, int score);
    bool UpdateScore(const std::string& clientId, int newScore);
    int GetScore(const std::string& clientId);
    bool DeleteClient(const std::string& clientId);
    bool ClientExists(const std::string& clientId);

    // Functions for key bindings
    bool SaveKeyBindings(const std::string& clientId, int up, int down, int left, int right, int shoot);
    bool GetKeyBindings(const std::string& username, int& up, int& down, int& left, int& right, int& shoot);

private:
    std::string databaseName;
    void InitializeDatabase();
    sqlite3* db;
};
