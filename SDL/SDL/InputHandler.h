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
	Command * button1_;
	Command * button2_;
	Command * button3_;
	Command * button4_;
	Command * button5_;
	MacroCommand * macro;
	
}; 