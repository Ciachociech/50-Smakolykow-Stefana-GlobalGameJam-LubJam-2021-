//To not making mess in includes
#include "external_dependencies.h"

#include "LayerManager.h"
#include "StefanManager.h"
#include "SteeringManager.h"
#include "TreasureManager.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

//Global SDL values
SDL_Window* window = NULL;
SDL_Surface* windowSurface = NULL;
SDL_Renderer* windowRenderer = NULL;

//Other constants
const int FPS = 60;

bool init();
bool loadMedia();
void close();
bool loop();

int main(int argc, char* args[])
{
	if (!init()) { printf("Failed to initialize!\n"); }
	else
	{
		if (!loadMedia()) { printf("Failed to load media!\n"); }
		else { loop(); }
	}
	close();
	return 0;
}

bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		window = SDL_CreateWindow(u8"50 Smako³yków Stefana", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		//window = SDL_CreateWindow(u8"50 Smakolykow Stefana", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN); //uncomment at the end
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (windowRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				windowSurface = SDL_GetWindowSurface(window);
			}
		}
	}

	return success;
}

bool loadMedia()
{
	return true;
}

void close()
{
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}

bool loop()
{
	bool quit = false;
	SDL_Event event;

	LayerManager lm = LayerManager();
	lm.addLayer(0, windowRenderer);
	lm.addLayer(1, windowRenderer);

	StefanManager sm = StefanManager();
	sm.setStefan(windowRenderer);

	SteeringManager sterman = SteeringManager();

	TreasureManager tm = TreasureManager();
	tm.randomizeTreasures(windowRenderer);
	printf("Sa %i smakolyki na %i kratkach\n", tm.getCount(), tm.getFramesLeft());

	int tileX = 0, tileY = 0;
	Uint32 frameTime;
	keyAction actualAction;

	SDL_SetRenderDrawColor(windowRenderer, 32, 32, 32, 0xFF);

	while (!quit)
	{
		tileX = 0, tileY = 0;
		frameTime = SDL_GetTicks();
		actualAction = keyAction::none;
		
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
				case SDL_QUIT: { quit = true; break; }
				case SDL_KEYDOWN: { actualAction = sterman.keyboardMovement(tileX, tileY, event.key.keysym.sym); break; }
				default: { break; }
			}
		}

		sm.moveStefan(tileX, tileY);
		if (actualAction == keyAction::digging) 
		{
			bool dug = lm.disableTile(sm.getStefan().X(), sm.getStefan().Y());
			if (dug) { sm.reduceMotivation(); }
			if (tm.checkTile(sm.getStefan().X(), sm.getStefan().Y())) { tm.getFramesLeft()); }
		}
		if (actualAction == keyAction::mischievous) 
		{
			bool loop = true;
			SDL_Event event;
			while (loop)
			{
				while (SDL_PollEvent(&event) != 0)
				{
					switch (event.type)
					{
					case SDL_QUIT: case SDL_KEYDOWN: { loop = false; break; }
					}
				}
				SDL_RenderClear(windowRenderer);
				lm.render(-1, windowRenderer);
				SDL_RenderPresent(windowRenderer);
			}

		}

		SDL_RenderClear(windowRenderer);

		lm.render(0, 0, 0, windowRenderer);
		tm.render(windowRenderer);
		lm.render(0, 0, 1, windowRenderer);
		sm.render(windowRenderer);

		//SDL_UpdateWindowSurface(window);
		SDL_RenderPresent(windowRenderer);

		if((SDL_GetTicks() - frameTime) < (1000.f / FPS))
		SDL_Delay((1000.f / FPS) - (SDL_GetTicks() - frameTime));
	}

	return true;
}

