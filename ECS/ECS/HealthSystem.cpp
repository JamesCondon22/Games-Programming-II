#include "HealthSystem.h"
#include <iostream>

HealthSystem::HealthSystem() {

}

void HealthSystem::addEntity(Entity e) {
	m_entities.push_back(e);
}

void HealthSystem::update(SDL_Keycode in)
{
	for (Entity & entity : m_entities) {
		
		for (Component * comp : entity.getComponents()) {
			if (comp->id == 1)
			{	
				auto health = dynamic_cast<HealthComponent*>(comp)->getHealth() - .00001;
				dynamic_cast<HealthComponent*>(comp)->setHealth(health);
				
				if (health > 0)
				{
					std::cout << "Changing health component of entity " << entity.getId() << ": " << health << std::endl;
				}
				else
				{
					std::cout << "Entity " << entity.getId() << " is dead" << std::endl;
				}
			}		
		}
		
	}
	std::cout << endl;
	
}

void HealthSystem::checkCollision() 
{
	/*

	if (A.X + A.WIDTH >= B.X && A.X <= B.X + B.WIDTH && 
		A.Y + A.HEIGHT >= B.Y && A.Y <= B.Y + B.HEIGHT)
	*/
	
}