#include "InputHandler.h"

InputHandler::InputHandler()
{
	buttonX_ = new JumpCommand();
	buttonY_ = new FireCommand();
	buttonA_ = new CrouchCommand();
	buttonB_ = new MelleeCommand();
	buttonD_ = new ShieldCommand();
	macro = new MacroCommand();

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
			buttonX_->execute();
			macro->add(buttonX_);
			break;
		case SDLK_y:
			buttonY_->execute();
			macro->add(buttonY_);
			break;
		case SDLK_a:
			buttonA_->execute();
			macro->add(buttonA_);
			break;
		case SDLK_b:
			buttonB_->execute();
			macro->add(buttonB_);
			break;
		case SDLK_d:
			buttonD_->execute();
			macro->add(buttonD_);
			break;
		case SDLK_z:
			macro->execute();
			break;
		
		
		}

	}
	
}