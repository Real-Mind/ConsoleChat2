#include "Chat.h"

void Chat::addMessage(int id, const Message& message) {
	messages[id] = message;
}

void Chat::displayMessages() const {
    for (const auto& pair : messages) {
        // Безопасная обработка времени
        char buffer[26]; // Для хранения форматированного времени
        errno_t err = ctime_s(buffer, sizeof(buffer), &pair.second.timestamp);
        if (err != 0) {
            std::cerr << "Ошибка при преобразовании времени" << std::endl;
        }
        else {
            std::cout << pair.second.sender << ": "
                << pair.second.text
                << " (" << buffer << ")"
                << std::endl;
        }
    }
}

