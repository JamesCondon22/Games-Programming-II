#include "ControlSystem.h"


void ControlSystem::addEntity(Entity en)
{
	m_entities.push_back(en);
}

void ControlSystem::control(SDL_Keycode in)
{
	for (Entity& entity : m_entities) {
		for (Component* comp : entity.getComponents()) {

			if (comp->id == 3) {
				controlComp = dynamic_cast<ControlComponent*>(comp);
				switch (in) {
				case SDLK_UP:
					controlComp->changeState(controlComp->Up);
					break;
				case SDLK_DOWN:
					controlComp->changeState(controlComp->Down);
					break;
				case SDLK_LEFT:
					controlComp->changeState(controlComp->Left);
					break;
				case SDLK_RIGHT:
					controlComp->changeState(controlComp->Right);
					break;
				default:
					controlComp->changeState(controlComp->Idle);
					break;
				}
			}
		}
	}
}

void ControlSystem::update()
{
	for (Entity& entity : m_entities) {

		for (Component* comp : entity.getComponents()) {
			if (comp->id == 2) {

				positionComp = dynamic_cast<PositionComponent*>(comp);
			}
			else if (comp->id == 3)
			{
				controlComp = dynamic_cast<ControlComponent*>(comp);

			}
		}

		x = positionComp->getXpos();
		y = positionComp->getYPos();


		if (controlComp->m_currentGameState == controlComp->Up) {
			y -= speed;
		}

		if (controlComp->m_currentGameState == controlComp->Down) {
			y += speed;
		}

		if (controlComp->m_currentGameState == controlComp->Right) {
			x += speed;
		}

		if (controlComp->m_currentGameState == controlComp->Left) {
			x -= speed;
		}

		bounderies();
		positionComp->setPosition(x,y);
	}
}


void ControlSystem::bounderies()
{
	if (x > screenWidth)
	{
		x = 0 ;
	}
	else if (x < 0)
	{
		x = screenWidth;
	}

	if (y > screenHeight)
	{
		y = 0;
	}
	else if (y< 0)
	{
		y = screenHeight;
	}
}
