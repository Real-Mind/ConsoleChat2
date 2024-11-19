#include "Chat.h"
#include <vector>

std::string getFormattedTime(std::time_t rawTime);

int main() {
    setlocale(LC_ALL, "rus");
    User userManager;
    std::vector<Message> messages;

    std::string username, password;
    std::cout << "����������� ������ ������������:\n";
    std::cout << "������� ���: ";
    std::cin >> username;
    std::cout << "������� ������: ";
    std::cin >> password;

    if (userManager.registerUser(username, password)) {
        std::cout << "����������� ������ �������!\n";
    }

    std::cout << "\n�����������:\n";
    std::cout << "������� ���: ";
    std::cin >> username;
    std::cout << "������� ������: ";
    std::cin >> password;

    if (userManager.loginUser(username, password)) {
        std::cout << "�������� �����������!\n";

        std::string messageText;
        std::cout << "������� ���������: ";
        std::cin.ignore();  // ���������� ���������� ������� �� ����� ������
        std::getline(std::cin, messageText);

        // �������� � ���������� ���������
        std::time_t now = std::time(nullptr);
        messages.emplace_back(username, messageText, now);

        std::cout << "��������� ���������:\n";
        for (const auto& message : messages) {
            std::cout << "��: " << message.sender << "\n���������: " << message.text
                << "\n�����: " << getFormattedTime(message.timestamp) << "\n\n";
        }
    }

    return 0;
}

// ������� ��� ����������� ��������� ���� � ������� � ���� ������
std::string getFormattedTime(std::time_t rawTime) {
    char buffer[26];
    errno_t err = ctime_s(buffer, sizeof(buffer), &rawTime);
    if (err != 0) {
        // ��������� ������, ���� ����������
        return "Error converting time";
    }
    return std::string(buffer);
}
