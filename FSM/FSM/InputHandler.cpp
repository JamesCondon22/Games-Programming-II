#include "InputHandler.h"

InputHandler::InputHandler()
{
	fsm = new Animation();
	m_current = IDLE;
}

InputHandler::~InputHandler()
{

}
void InputHandler::setCurrent(Action a) {
	m_current = a;
}

InputHandler::Action InputHandler::getCurrent() {
	return m_current;
}



void InputHandler::handleInput(SDL_Event & event)
{

	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			fsm->jumping();
			if (getCurrent() == IDLE)
			setCurrent(JUMP);
			break;
		case SDLK_RIGHT:
			fsm->climbing();
			if (getCurrent() == IDLE)
			setCurrent(CLIMB);
			break;
		case SDLK_DOWN:
			fsm->idle();
			setCurrent(IDLE);
			break;
	
		}

	}
	
}