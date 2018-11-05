#include "Entity.h"

class AiSystem {
public:
	void addEntity(Entity en);
	void update();

private:
	vector<Entity> m_entities;
	PositionComponent* positionComp;
	
	float x = 0;
	float y = 0;
	float speed = 10;

	void checkBoundary();
	int screenWidth = 1200;
	int screenHeight = 700;

	int direction = 0;
	bool move = false;

};

