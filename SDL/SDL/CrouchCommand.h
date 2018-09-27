#pragma once

#include "Command.h"
#include <iostream>

class CrouchCommand : public Command
{
public:
	virtual void execute() { std::cout << "crouch" << std::endl; }
};
