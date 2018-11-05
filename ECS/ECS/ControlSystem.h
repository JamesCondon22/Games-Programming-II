#include "Entity.h"

class ControlSystem {
public:
	void addEntity(Entity en);
	void control(SDL_Keycode in);
	void update();

private:
	vector<Entity> m_entities;

	PositionComponent* positionComp;
	ControlComponent* controlComp;
	
	float x = 0;
	float y = 0;
	float speed = 2;

	void bounderies();
	int screenWidth = 1200;
	int screenHeight = 700;

};
