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
		case SDLK_x:
			fsm->jumping();
			break;
		case SDLK_y:
			fsm->climbing();
			break;
		case SDLK_z:
			fsm->idle();
			break;
		case SDLK_b:
			
			break;
		case SDLK_d:
			
			break;
	
		
		
		}

	}
	
}