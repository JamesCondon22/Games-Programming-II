#pragma once

#include "Animation.h"

#include <SDL.h>

class InputHandler
{
public: 
	InputHandler();
	~InputHandler();
		

	enum Action
	{
		IDLE,
		JUMP,
		CLIMB
	};
	void handleInput(SDL_Event & event);
	void setCurrent(Action);
	Action getCurrent();
private:


	Animation * fsm;
	Action m_current;
	
}; 