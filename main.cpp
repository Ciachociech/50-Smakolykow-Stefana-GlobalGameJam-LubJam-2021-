//To not making mess in includes
#include "external_dependencies.h"

#include "LayerManager.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

//Global SDL values
SDL_Window* window = NULL;
SDL_Surface* windowSurface = NULL;
SDL_Renderer* windowRenderer = NULL;

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

	LayerManager lm;
	lm.addLayer(windowRenderer);

	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
				case SDL_QUIT: { quit = true; break; }
			}
		}

		SDL_SetRenderDrawColor(windowRenderer, 192, 192, 192, 0xFF);
		SDL_RenderClear(windowRenderer);

		lm.render(0, 0, windowRenderer);

		SDL_UpdateWindowSurface(window);
		SDL_RenderPresent(windowRenderer);

		SDL_Delay(33);
	}

	return true;
}

