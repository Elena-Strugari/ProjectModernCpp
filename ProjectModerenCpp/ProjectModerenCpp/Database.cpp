#include "Database.h"
#include <sqlite3.h>
#include <iostream>

Database::Database(const std::string& dbName) : databaseName(dbName), db(nullptr) {
    if (sqlite3_open(databaseName.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
    }
    else {
        InitializeDatabase();

    }
}

Database::~Database() {
    if (db) {
        sqlite3_close(db);
    }
}

void Database::InitializeDatabase() {
    const char* createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS clients (
            id TEXT PRIMARY KEY,
            score INTEGER,
            key_up TEXT,
            key_down TEXT,
            key_left TEXT,
            key_right TEXT,
            key_shoot TEXT
        );
    )";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "Failed to create table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}


bool Database::AddClient(const std::string& clientId, int score) {
    const char* insertSQL = "INSERT INTO clients (id, score) VALUES (?, ?);";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, clientId.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, score);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);

    return success;
}

bool Database::UpdateScore(const std::string& clientId, int newScore) {
    const char* updateSQL = "UPDATE clients SET score = ? WHERE id = ?;";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, updateSQL, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, newScore);
    sqlite3_bind_text(stmt, 2, clientId.c_str(), -1, SQLITE_TRANSIENT);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);

    return success;
}

int Database::GetScore(const std::string& clientId) {
    const char* selectSQL = "SELECT score FROM clients WHERE id = ?;";
    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db, selectSQL, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return -1;
    }

    sqlite3_bind_text(stmt, 1, clientId.c_str(), -1, SQLITE_TRANSIENT);

    int score = -1;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        score = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return score;
}

bool Database::DeleteClient(const std::string& clientId) {
    const char* deleteSQL = "DELETE FROM clients WHERE id = ?;";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, deleteSQL, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, clientId.c_str(), -1, SQLITE_TRANSIENT);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);

    if (success) {
        std::cout << "Client with ID '" << clientId << "' deleted successfully." << std::endl;
    }
    else {
        std::cerr << "Failed to delete client with ID '" << clientId << "'. Error: " << sqlite3_errmsg(db) << std::endl;
    }

    return success;
}

bool Database::ClientExists(const std::string& clientId) {
    const char* existsSQL = "SELECT 1 FROM clients WHERE id = ? LIMIT 1;";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, existsSQL, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, clientId.c_str(), -1, SQLITE_TRANSIENT);

    bool exists = sqlite3_step(stmt) == SQLITE_ROW;
    sqlite3_finalize(stmt);

    return exists;
}

bool Database::SaveKeyBindings(const std::string& clientId, const std::string& up, const std::string& down, const std::string& left, const std::string& right, const std::string& shoot) {
    const char* updateSQL = R"(
        UPDATE clients 
        SET key_up = ?, key_down = ?, key_left = ?, key_right = ?, key_shoot = ? 
        WHERE id = ?;
    )";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, updateSQL, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, up.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, down.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, left.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, right.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, shoot.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, clientId.c_str(), -1, SQLITE_TRANSIENT);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);

    if (success) {
        std::cout << "Key bindings for client '" << clientId << "' saved successfully." << std::endl;
    }
    else {
        std::cerr << "Failed to save key bindings for client '" << clientId << "'. Error: " << sqlite3_errmsg(db) << std::endl;
    }

    return success;
}
