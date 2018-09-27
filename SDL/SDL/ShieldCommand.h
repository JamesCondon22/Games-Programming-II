#pragma once

#include "Command.h"
#include <iostream>

class ShieldCommand : public Command
{
public:
	virtual void execute() { std::cout << "shield" << std::endl; }
};