#include"UserManager.h"
#include<iostream>

UserManager::UserManager() = default;

void UserManager::PromptLoginOrRegister() {
    while (true) {
        std::cout << "Bine ai venit! Alege o optiune:\n";
        std::cout << "1. Login\n";
        std::cout << "2. Register\n";
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
    }
}