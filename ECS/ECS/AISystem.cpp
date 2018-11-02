#include "AiSystem.h"

/// <summary>
/// Adds entites to the system
/// </summary>
/// <param name="en"></param>
void AiSystem::addEntity(Entity en)
{
	m_entities.push_back(en);
}

/// <summary>
/// Moves entites upwards and resets them.
/// </summary>
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

		y -= speed;

		checkBoundary();
		std::pair<float, float> m_pos = { x, y };
		positionComp->setPosition(x,y);
	}
}

/// <summary>
/// simple boundary checking.
/// </summary>
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
