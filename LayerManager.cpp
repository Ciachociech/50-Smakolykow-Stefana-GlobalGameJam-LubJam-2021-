#include "LayerManager.h"

LayerManager::LayerManager() : layers(), overand() {}

LayerManager::~LayerManager() {}

void LayerManager::addLayer(int mode, SDL_Renderer* renderer)
{
	layers.push_back(std::make_unique<GraphLayer>());
	modeInterpreter(mode, renderer);
}

void LayerManager::render(int x, int y, SDL_Renderer* renderer)
{
	for (int i = 0; i < layers.size(); i++)
	{
		layers[i]->render(x, y, renderer);
	}
}

void LayerManager::modeInterpreter(int mode, SDL_Renderer* renderer)
{
	switch (mode)
	{
	case 0: 
	{ 
		layers.back()->loadFromFile(0, 0, 1.f, 1.f, "Assets/debug_background.png", renderer); 
		layers.back()->loadFromFile(584, 24, 1.f, 1.f, "Assets/boardV2.png", renderer); 
		break;
	}
	case 1: 
	{ 
		for (int r = 0; r < 21; r++)
		{
			for (int c = 0; c < 21; c++)
			{
				if (((r >= 5 && r <= 7) && (c >= 5 && c <= 7)) || ((r >= 13 && r <= 15) && (c >= 5 && c <= 7)) || ((r >= 5 && r <= 7) && (c >= 13 && c <= 15)) || ((r >= 13 && r <= 15) && (c >= 13 && c <= 15))) {}
				else { layers.back()->loadFromFile(584 + 32 * c, 24 + 32 * r, 1.f, 1.f, "Assets/pellet.png", renderer); }
			}
		}
		break;
	}
	default: { break; }
	}
}
