#ifndef GAME
#define GAME

#include <SDL.h>
#include <SDL_timer.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <iostream>
#include "Entity.h"
#include "HealthSystem.h"
#include "RenderSystem.h"
#include "ControlSystem.h"
#include "AiSystem.h"

using namespace std;

class Game {

public:
	Game();
	~Game();

	void run();

private:

	void processEvents();
	void update();
	void render();
	void initialiseEntitys();
	void initialiseComponents();
	void initialiseSystems();

	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Event event;
	bool m_exitGame;

	Entity* m_player;
	Entity* m_cat;
	Entity* m_alien;
	Entity* m_dog;

	HealthComponent* m_healthComponent;
	ControlComponent* m_controlComponent;
	PositionComponent* m_positionComponent;
	
	HealthSystem m_healthSystem;
	RenderSystem m_renderSystem;
	ControlSystem m_controlSystem;
	AiSystem m_aiSystem;

};



#endif // !GAME