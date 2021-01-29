#pragma once

#include "GraphLayer.h"

typedef std::vector<std::unique_ptr<GraphLayer>> VecGraphLayer;

class LayerManager
{
public:
	LayerManager();
	virtual ~LayerManager();

	void addLayer(SDL_Renderer* renderer);
	void render(int x, int y, SDL_Renderer* renderer);
private:
	VecGraphLayer layers;
};

