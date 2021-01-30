#pragma once
#include "Stefan.h"

class StefanManager
{
public:
	StefanManager();
	virtual ~StefanManager();

	void setStefan(SDL_Renderer* renderer);
	void moveStefan(int tileX, int tileY);

	void render(SDL_Renderer* renderer);
private:
	Stefan stefan;
	Graph attachedEffect;
	bool isMoving;
	int destX, destY;
	Uint32 effectStart;
};
