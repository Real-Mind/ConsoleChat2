#include "Chat.h"

void Chat::addMessage(int id, const Message& message) {
	messages[id] = message;
}

void Chat::displayMessages() const {
    for (const auto& pair : messages) {
        // ���������� ��������� �������
        char buffer[26]; // ��� �������� ���������������� �������
        errno_t err = ctime_s(buffer, sizeof(buffer), &pair.second.timestamp);
        if (err != 0) {
            std::cerr << "������ ��� �������������� �������" << std::endl;
        }
        else {
            std::cout << pair.second.sender << ": "
                << pair.second.text
                << " (" << buffer << ")"
                << std::endl;
        }
    }
}

