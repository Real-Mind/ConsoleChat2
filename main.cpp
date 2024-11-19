#include "Chat.h"
#include <vector>

std::string getFormattedTime(std::time_t rawTime);

int main() {
    setlocale(LC_ALL, "rus");
    User userManager;
    std::vector<Message> messages;

    std::string username, password;
    std::cout << "Регистрация нового пользователя:\n";
    std::cout << "Введите имя: ";
    std::cin >> username;
    std::cout << "Введите пароль: ";
    std::cin >> password;

    if (userManager.registerUser(username, password)) {
        std::cout << "Регистрация прошла успешно!\n";
    }

    std::cout << "\nАвторизация:\n";
    std::cout << "Введите имя: ";
    std::cin >> username;
    std::cout << "Введите пароль: ";
    std::cin >> password;

    if (userManager.loginUser(username, password)) {
        std::cout << "Успешная авторизация!\n";

        std::string messageText;
        std::cout << "Введите сообщение: ";
        std::cin.ignore();  // Игнорируем оставшийся переход на новую строку
        std::getline(std::cin, messageText);

        // Создание и добавление сообщения
        std::time_t now = std::time(nullptr);
        messages.emplace_back(username, messageText, now);

        std::cout << "Сообщение добавлено:\n";
        for (const auto& message : messages) {
            std::cout << "От: " << message.sender << "\nСообщение: " << message.text
                << "\nВремя: " << getFormattedTime(message.timestamp) << "\n\n";
        }
    }

    return 0;
}

// Функция для безопасного получения даты и времени в виде строки
std::string getFormattedTime(std::time_t rawTime) {
    char buffer[26];
    errno_t err = ctime_s(buffer, sizeof(buffer), &rawTime);
    if (err != 0) {
        // Обработка ошибки, если необходимо
        return "Error converting time";
    }
    return std::string(buffer);
}
