#pragma once
#include "app_params.h"

class UserInterface
{
public:
	
	UserInterface() = default;

	virtual ApplicationParameters start() const = 0;

	virtual ~UserInterface() = default;
};