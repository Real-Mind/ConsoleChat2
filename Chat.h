#pragma once
#include <iostream>
#include <map>
#include <ctime>
#include "Message.h"
#include "User.h"

class Chat
{
public:
	void addMessage(int id, const Message& message);
	void displayMessages() const;

private:
	std::map<int, Message> messages;
};