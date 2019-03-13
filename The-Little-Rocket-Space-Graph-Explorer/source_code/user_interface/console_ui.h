#pragma once
#include <iostream>
#include <string>
#include "user_interface.h"

/*
	ConsoleUI is a class that provides simple console user interface for application.

	by Wiktor £azarski
*/
class ConsoleUI final : public UserInterface
{
public:
	
	ConsoleUI() = default;

	ApplicationParameters start() const override;

private:

	void printWelcomeMsg() const;
	void getParameter(const std::string& msg, int& param) const;
	void printThanksMsg() const;
};