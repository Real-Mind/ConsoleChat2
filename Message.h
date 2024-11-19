#pragma once
#include <string>
#include <ctime>

struct Message {
    std::string sender;
    std::string text;
    std::time_t timestamp;

    //  онструктор без параметров, чтобы избежать ошибок
    Message() : sender(""), text(""), timestamp(0) {}

    // ќсновной конструктор
    Message(const std::string& sender, const std::string& text, std::time_t timestamp)
        : sender(sender), text(text), timestamp(timestamp) {}
};