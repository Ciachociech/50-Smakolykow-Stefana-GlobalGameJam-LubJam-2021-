#include "LayerManager.h"

LayerManager::LayerManager() : layers(), overand() {}

LayerManager::~LayerManager() {}

void LayerManager::addLayer(SDL_Renderer* renderer)
{
	layers.push_back(std::make_unique<GraphLayer>());
	layers.back()->loadFromFile(0, 0, 1.f, 1.f, "Assets/debug_background.bmp", renderer);
	layers.back()->loadFromFile(584, 24, 1.f, 1.f, "Assets/boardV2.bmp", renderer);
}

void LayerManager::render(int x, int y, SDL_Renderer* renderer)
{
	for (int i = 0; i < layers.size(); i++)
	{
		layers[i]->render(x, y, renderer);
	}
}
