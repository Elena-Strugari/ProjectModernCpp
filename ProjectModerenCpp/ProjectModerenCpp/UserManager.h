#pragma once
#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <set>

class UserManager {
public:
    UserManager();
    void PromptLoginOrRegister();

private:
    std::set<std::string> users;
    bool Register(const std::string& username);
    bool Login(const std::string& username);
};

#endif // USERMANAGER_H
