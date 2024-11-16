#include "UserManager.h"
#include <iostream>

UserManager::UserManager() = default;

void UserManager::PromptLoginOrRegister() {
    while (true) {
        std::cout << "Bine ai venit! Alege o optiune:\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 3) {
            std::cout << "Program inchis.\n";
            break;
        }

        std::cout << "Introduceti numele de utilizator: ";
        std::string username;
        std::getline(std::cin, username);

        if (choice == 1) {
            Register(username);
        }
        else if (choice == 2) {
            Login(username);
        }
        else {
            std::cout << "Optiune invalida.\n";
        }
    }
}

bool UserManager::Register(const std::string& username) {
    if (!ValidateUsername(username)) {
        std::cout << "Numele de utilizator trebuie sa contina cel putin o litera mare.\n";
        return false;
    }

    if (users.find(username) != users.end()) {
        std::cout << "Numele de utilizator este deja folosit. Alegeti alt nume.\n";
        return false;
    }

    users.insert(username);
    std::cout << "Inregistrare reusita!\n";
    return true;
}

bool UserManager::Login(const std::string& username) {
    if (users.find(username) != users.end()) {
        std::cout << "Login reusit! Bine ai venit, " << username << "!\n";
        return true;
    }
    else {
        std::cout << "Numele de utilizator nu exista. Inregistreaza-te mai intai.\n";
        return false;
    }
}

bool UserManager::ValidateUsername(const std::string& username) {
    // Regex: cel puțin o literă mare
    std::regex username_regex("^(?=.*[A-Z]).*$");
    return std::regex_match(username, username_regex);
}
