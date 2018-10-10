///*This source code copyrighted by Lazy Foo' Productions (2004-2015)
//and may not be redistributed without written permission.*/
//
////Using SDL and standard IO
//#include <SDL.h>
//#include <stdio.h>
//#include "InputHandler.h"
//#include <SDL_image.h>
//#include "Animation.h"
//#include <iostream>
//#include <thread>
//
////Screen dimension constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
////Loads individual image as texture 
//SDL_Texture* loadTexture( std::string path ); 
//bool success;
////The window we'll be rendering to 
//SDL_Window* gWindow = NULL; 
////The window renderer 
//SDL_Renderer* gRenderer = NULL; 
////Current displayed texture 
//SDL_Texture* gTexture = NULL;
//
//int main( int argc, char* args[] )
//{
//	
//	int i = 0;
//	int quit = 0;
//	SDL_Event event;
//	InputHandler * handler = new InputHandler();
//	loadMedia();
//	//close();
//	
//	//The surface contained by the window
//	SDL_Surface* screenSurface = NULL;
//
//	//Initialize SDL
//	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
//	{
//		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
//	}
//	else
//	{
//		//Create window
//		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
//		if(gWindow == NULL )
//		{
//			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
//			success = false;
//		}
//		else
//		{
//			//Create renderer for window
//			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
//			if( gRenderer == NULL ) 
//			{ 
//				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() ); 
//				success = false; 
//			} 
//			else 
//			{ //Initialize renderer color 
//				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF ); 
//				//Initialize PNG loading 
//				int imgFlags = IMG_INIT_PNG; if( !( IMG_Init( imgFlags ) & imgFlags ) ) 
//				{ 
//					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() ); 
//					success = false; 
//				} 
//			}
//			//Get window surface
//			screenSurface = SDL_GetWindowSurface(gWindow);
//
//			//Fill the surface white
//			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
//			
//			//Update the surface
//			SDL_UpdateWindowSurface(gWindow);
//
//			//Wait two seconds
//			SDL_Delay( 2000 );
//		}
//	}
//
//	while (!quit)
//	{
//		while (SDL_PollEvent(&event))
//		{
//			handler->handleInput(event);
//			
//			if (event.type == SDL_QUIT)
//			{
//				quit = true;
//			}
//		}
//		//Clear screen 
//		SDL_RenderClear( gRenderer ); 
//		//Render texture to screen 
//		SDL_RenderCopy( gRenderer, gTexture, NULL, NULL ); 
//		//Update screen 
//		SDL_RenderPresent( gRenderer );
//	}
//
//
//	//Destroy window
//	SDL_DestroyWindow( gWindow );
//
//	//Quit SDL subsystems
//	SDL_Quit();
//
//	return 0;
//}
//
//SDL_Texture* loadTexture(std::string path) 
//{ 
//	//The final texture 
//	SDL_Texture* newTexture = NULL; 
//	//Load image at specified path 
//	SDL_Surface* loadedSurface = IMG_Load( path.c_str() ); 
//	if( loadedSurface == NULL ) 
//	{ 
//		printf( "Unable to load image %s! SDL_image Error: %s\n", 
//			path.c_str(), IMG_GetError() ); 
//	}
//	else 
//	{ 
//		//Create texture from surface pixels
//		newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface ); 
//		if( newTexture == NULL ) 
//		{ printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() ); } 
//		//Get rid of old loaded surface 
//		SDL_FreeSurface( loadedSurface ); 
//	} 
//	return newTexture; 
//}
//
//bool loadMedia() 
//{ 
//	//Loading success flag
//	success = true; 
//	//Load PNG texture 
//	gTexture = loadTexture( "07_texture_loading_and_rendering/texture.png" ); 
//	if( gTexture == NULL ) 
//	{ 
//		printf( "Failed to load texture image!\n" ); 
//		success = false; } return success; 
//} 
//
//void close() 
//{ //Free loaded image 
//	SDL_DestroyTexture( gTexture );
//	gTexture = NULL; 
//	//Destroy window 
//	SDL_DestroyRenderer( gRenderer ); 
//	SDL_DestroyWindow( gWindow ); 
//	gWindow = NULL; 
//	gRenderer = NULL; 
//	//Quit SDL subsystems 
//	IMG_Quit(); 
//	SDL_Quit(); 
//}

/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed PNG image
SDL_Surface* gPNGSurface = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG surface
	gPNGSurface = loadSurface("grid.png");
	if (gPNGSurface == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded image
	SDL_FreeSurface(gPNGSurface);
	gPNGSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				//Apply the PNG image
				SDL_BlitSurface(gPNGSurface, NULL, gScreenSurface, NULL);

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}