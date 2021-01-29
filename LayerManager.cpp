#include "LayerManager.h"

LayerManager::LayerManager() : layers() {}

LayerManager::~LayerManager() {}

void LayerManager::addLayer(SDL_Renderer* renderer)
{
	layers.push_back(std::make_unique<GraphLayer>());
	layers.back()->loadFromFile(400, 400, 1.f, 1.f, "stefan.bmp", renderer);
}

void LayerManager::render(int x, int y, SDL_Renderer* renderer)
{
	for (int i = 0; i < layers.size(); i++)
	{
		layers[i]->render(x, y, renderer);
	}
}
