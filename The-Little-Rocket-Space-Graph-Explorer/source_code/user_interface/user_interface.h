#pragma once
#include "app_params.h"

/*
	UserInterface class provides an interface to make it easy to switch UI for a new one.

	by Wiktor £azarski
*/
class UserInterface
{
public:
	
	UserInterface() = default;

	virtual ApplicationParameters start() const = 0;

	virtual ~UserInterface() = default;
};