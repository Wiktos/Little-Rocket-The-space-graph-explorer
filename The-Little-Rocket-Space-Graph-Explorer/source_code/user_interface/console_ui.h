#pragma once
#include <iostream>
#include <string>
#include "user_interface.h"

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