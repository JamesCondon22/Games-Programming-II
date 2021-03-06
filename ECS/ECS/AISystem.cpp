#include "AiSystem.h"

void AiSystem::addEntity(Entity en)
{
	m_entities.push_back(en);
}


void AiSystem::update()
{
	for (Entity& entity : m_entities) {

		for (Component* comp : entity.getComponents()) {
			if (comp->id == 2) {

				positionComp = dynamic_cast<PositionComponent*>(comp);
			}
		}

		x = positionComp->getXpos();
		y = positionComp->getYPos();
		
		y += speed;
		
		checkBoundary();
		positionComp->setPosition(x,y);
	}
}

void AiSystem::checkBoundary()
{
	if (x > screenWidth)
	{
		x = 0;
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
