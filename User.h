#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>

class User {
    std::map<std::string, std::string> users; // username -> password
    const std::string usersFile = "users.txt"; // файл для хранения пользователей

public:
    User() {
        loadUsers();
    }
    ~User() {
        saveUsers();
    }
    void loadUsers();
    void saveUsers();
    bool registerUser(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
};

