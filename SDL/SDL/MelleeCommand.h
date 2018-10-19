#pragma once

#include "Command.h"
#include <iostream>

class MelleeCommand : public Command
{
public:
	virtual void execute() { std::cout << "mellee" << std::endl; }
	virtual void undo()
	{
		std::cout << "Undo Mellee" << std::endl;
	};
	virtual void redo()
	{
		std::cout << "Redo Mellee" << std::endl;
	};
};