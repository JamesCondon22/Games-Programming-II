#include "Game.h"

Game::Game()
{
	m_window = SDL_CreateWindow("Entity Component Systems", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 700, SDL_WINDOW_OPENGL);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;

	if (IMG_Init(imgFlags) != imgFlags)
	{
		cout << "Error: " << IMG_GetError() << endl;
	}
	
	m_player = new Player();
	m_cat = new Cat();
	m_alien = new Alien();
	m_dog = new Dog();

	initialise();
}

Game::~Game()
{
}

void Game::run()
{
	const Uint32 fps = 60;
	const Uint32 minimumFrameTime = 1000 / fps;

	Uint32 frameTime;
	Uint32 lastFrameTime = 0;
	Uint32 deltaTime = 0;

	while (!exit) {

		processEvents();
		frameTime = SDL_GetTicks();

		deltaTime = frameTime - lastFrameTime;
		lastFrameTime = frameTime;

		update();
		render();

		if ((SDL_GetTicks() - frameTime) < minimumFrameTime)
			SDL_Delay(minimumFrameTime - (SDL_GetTicks() - frameTime));
	}

	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Game::processEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			exit = true;
			break;
		case SDL_KEYDOWN:
			m_ctrlSystem.control(event.key.keysym.sym);
			if (event.key.keysym.sym == SDLK_ESCAPE)
				exit = true;
			break;
		}
	}
}

void Game::update()
{
	m_healthSystem.update();
	m_ctrlSystem.update();
	m_aiSystem.update();
}

void Game::render()
{
	if (m_renderer == nullptr)
	{
		SDL_Log("Could not create a renderer: %s", SDL_GetError());
	}

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
	m_renderSystem.render(m_renderer);
	SDL_RenderPresent(m_renderer);

}


void Game::initialise()
{
	m_healthComponent = new HealthComponent();
	m_posComponent = new PositionComponent(600, 0);
	m_ctrlComponent = new ControlComponent();

	m_player->addComponent(m_healthComponent);
	m_player->addComponent(m_posComponent);
	m_player->addComponent(m_ctrlComponent);

	m_posComponent = new PositionComponent(300, 400);

	m_cat->addComponent(m_posComponent);
	m_cat->addComponent(m_healthComponent);

	m_posComponent = new PositionComponent(600, 400);

	m_alien->addComponent(m_posComponent);
	m_alien->addComponent(m_healthComponent);

	m_posComponent = new PositionComponent(900, 400);

	m_dog->addComponent(m_posComponent);
	m_dog->addComponent(m_healthComponent);

	m_renderSystem.addEntity(*m_cat);
	m_renderSystem.addEntity(*m_alien);
	m_renderSystem.addEntity(*m_dog);
	m_renderSystem.addEntity(*m_player);

	m_healthSystem.addEntity(*m_player);

	m_ctrlSystem.addEntity(*m_player);

	m_aiSystem.addEntity(*m_cat);
	m_aiSystem.addEntity(*m_alien);
	m_aiSystem.addEntity(*m_dog);
}

