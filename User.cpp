#include "User.h"

void User::loadUsers() {
    std::ifstream infile(usersFile);
    if (!infile.is_open()) return;

    std::string username, password;
    while (infile >> username >> password) {
        users[username] = password;
    }
    infile.close();
}

void User::saveUsers() {
    std::ofstream outfile(usersFile);
    for (const auto& pair : users) {
        outfile << pair.first << " " << pair.second << "\n";
    }
    outfile.close();
}

bool User::registerUser(const std::string& username, const std::string& password) {
    if (users.find(username) != users.end()) {
        std::cout << "Пользователь уже существует!" << std::endl;
        return false;
    }
    users[username] = password;
    std::cout << "Регистрация прошла успешно!" << std::endl;
    return true;
}

bool User::loginUser(const std::string& username, const std::string& password) {
    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        std::cout << "Авторизация успешна!" << std::endl;
        return true;
    }
    else {
        std::cout << "Неверное имя пользователя или пароль!" << std::endl;
        return false;
    }
}
