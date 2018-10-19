#include "MacroCommand.h"

MacroCommand::MacroCommand()
{

}

MacroCommand::~MacroCommand()
{
	std::cout << "deconstructing" << std::endl;
}

void MacroCommand::add(Command* command)
{
	commands.push_back(command);
}

void MacroCommand::remove(Command* command)
{
	commands.remove(command);
}

void MacroCommand::undo()
{
	
	if (commands.size() > 0) {
		(*commands.rbegin())->undo();
		redoCommands.push_back(*commands.rbegin());
		commands.pop_back();
	}
	else
	{
		std::cout << "List is Empty" << std::endl;
	}
}

void MacroCommand::redo()
{
	if (redoCommands.size() > 0) {

		(*redoCommands.rbegin())->redo();
		commands.push_back(*redoCommands.rbegin());
		redoCommands.pop_back();
	}
	else {
		std::cout << "List is empty" << std::endl;
	}
}

void MacroCommand::execute()
{
	std::list<Command*>::iterator iter;

	for (iter = commands.begin(); iter != commands.end(); ++iter)
	{
		(*iter)->execute();
	}

	std::cout << "executed" << std::endl;
}
