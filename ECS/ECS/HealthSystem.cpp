#include "HealthSystem.h"
#include <iostream>

HealthSystem::HealthSystem() {

}

void HealthSystem::addEntity(Entity e) {
	m_entities.push_back(e);
}

void HealthSystem::update()
{
	int index = 0;
	for (Entity & entity : m_entities) {
		
		for (Component * comp : entity.getComponents()) {
			if (comp->id == 1)
			{
				int health = dynamic_cast<HealthComponent*>(comp)->getHealth() - 1;
				dynamic_cast<HealthComponent*>(comp)->setHealth(health);
				std::cout << "Changing health component of entity " << index << ": " << health << std::endl;
			}
			index++;
		}
		
	}
	std::cout << endl;
	std::cout << endl;
}