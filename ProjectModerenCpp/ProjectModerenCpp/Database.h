#pragma once
#include <sqlite3.h>
#include <string>



class Database
{
public:
    Database(const std::string& dbName);
    ~Database();

    bool addClient(const std::string& clientId, int score);
    bool updateScore(const std::string& clientId, int newScore);
    int getScore(const std::string& clientId);
    bool deleteClient(const std::string& clientId);
    bool clientExists(const std::string& clientId);
    bool saveKeyBindings(const std::string& clientId, const std::string& up, const std::string& down, const std::string& left, const std::string& right);


private:
    std::string databaseName;
    void initializeDatabase();
    sqlite3* db;

};
