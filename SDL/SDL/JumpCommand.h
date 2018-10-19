#pragma once

#include "Command.h"
#include <iostream>

class JumpCommand : public Command
{
public:
	virtual void execute() { std::cout << "jump" << std::endl; }
	virtual void undo()
	{
		std::cout << "Undo Jump" << std::endl;
	};
	virtual void redo()
	{
		std::cout << "Redo Jump" << std::endl;
	};
};