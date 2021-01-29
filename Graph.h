#pragma once

#include "external_dependencies.h"

class Graph
{
public:
	Graph();
	Graph(int x, int y);
	virtual ~Graph();

	bool loadFromFile(float scaleX, float scaleY, std::string filepath, SDL_Renderer* renderer);
	void free();
	virtual void render(int x, int y, SDL_Renderer* renderer);
	virtual void render(SDL_Renderer* renderer);

	int X();
	int Y();

	void setXY(int x, int y);
private:
	SDL_Texture* texture;
	
	int x, y;
	int w, h;
	float scaleX, scaleY;
};

