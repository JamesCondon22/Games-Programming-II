#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "ContolComponent.h"
#include <vector>
#include <SDL.h>

using namespace std;

class Entity {
public:
	int id;
	int width = 50;
	int height = 50;
	SDL_Color m_color;
	
	Entity() {};
	virtual ~Entity() {};

	void addComponent(Component* c) { m_components.push_back(c); }
	void removeComponenet(Component* c) {
	};
	vector<Component*> getComponents() { return m_components; }

	int getWidth() { return width; };
	int getHeight() { return height; };
	SDL_Color getColor() { return m_color; };
private:
	vector<Component*> m_components;
	

};

class Player : public Entity {
public:
	Player() { 
		id = 1; 
		m_color = { 255, 0, 0, 255 }; };
};


class Cat : public Entity {
public:
	Cat() {
		id = 2;
		m_color = { 255, 255, 0, 255 }; };

};


class Alien : public Entity {
public:
	Alien() {
		id = 3; 
		m_color = { 0, 255, 0, 255 };
	};
};

class Dog : public Entity {
public:
	Dog() { 
		id = 4;
		m_color = { 0, 0, 200, 255 }; };
};

#endif // !ENTITY_H

