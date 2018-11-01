#include "HealthSystem.h"

HealthSystem::HealthSystem() {

}

void HealthSystem::addEntity(Entity e) {
	m_entities.push_back(e);
}

void HealthSystem::update()
{
	for (Entity & entity : m_entities) {
		
		for (Component * comp : entity.getComponents()) {
			if (comp->id == 1)
			{
				int health = dynamic_cast<HealthComponent*>(comp)->getHealth() - 1;
				dynamic_cast<HealthComponent*>(comp)->setHealth(health);
			}
		}
	}
}