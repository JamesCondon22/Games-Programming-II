#pragma once

#include "Command.h"
#include "FireCommand.h"
#include "JumpCommand.h"
#include "CrouchCommand.h"
#include "MelleeCommand.h"
#include "MacroCommand.h"
#include "ShieldCommand.h"

#include <SDL.h>

class InputHandler
{
public: 
	InputHandler();
	~InputHandler();
		
	void handleInput(SDL_Event & event);

private:
	Command * buttonX_;
	Command * buttonY_;
	Command * buttonA_;
	Command * buttonB_;
	Command * buttonD_;
	MacroCommand * macro;
	
}; 