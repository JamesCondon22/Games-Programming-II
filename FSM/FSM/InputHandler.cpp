#include "InputHandler.h"

InputHandler::InputHandler()
{
	fsm = new Animation();

}

InputHandler::~InputHandler()
{

}

void InputHandler::handleInput(SDL_Event & event)
{

	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:
			fsm->jumping();
			break;
		case SDLK_RIGHT:
			fsm->climbing();
			break;
		case SDLK_UP:
			fsm->idle();
			break;
	
		}

	}
	
}