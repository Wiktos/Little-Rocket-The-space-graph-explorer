#pragma once
#include <iostream>
#include "user_interface.h"

class ConsoleUI final : public UserInterface
{
public:
	
	ConsoleUI() = default;

	ApplicationParameters start() const override;
};