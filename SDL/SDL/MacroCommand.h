#pragma once

#include "Command.h"
#include <iostream>
#include <list>

class MacroCommand : public Command {
public:
	MacroCommand();
	virtual ~MacroCommand();
	virtual void add(Command* command);
	virtual void remove(Command* command);
	virtual void execute();
	virtual void undo();
private:
	std::list<Command*> commands;
	
};
