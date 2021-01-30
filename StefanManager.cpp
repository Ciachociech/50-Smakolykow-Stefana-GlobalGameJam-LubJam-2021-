#include "StefanManager.h"

StefanManager::StefanManager() : isMoving(false), destX(0), destY(0) {}

StefanManager::~StefanManager()
{
	stefan.~Stefan();
}

void StefanManager::setStefan(SDL_Renderer* renderer)
{
	stefan = Stefan(584 + 32 * 10, 24 + 32 * 10);
	stefan.loadFromFile(1.f, 1.f, "stefan.bmp", renderer);
}

void StefanManager::moveStefan(int tileX, int tileY)
{
	if (!isMoving)
	{
		destX = stefan.X() + 32 * tileX;
		destY = stefan.Y() + 32 * tileY;
		isMoving = true;
	}

	if (stefan.X() == 584 && destX == 520) { destX = 584 + 32; }
	else if (stefan.X() == 584 && destX == 552) { destX = 584; }
	else if (stefan.X() == 1224 && destX == 1288) { destX = 1224 - 32; }
	else if (stefan.X() == 1224 && destX == 1256) { destX = 1224; }
	if (stefan.Y() == 24 && destY == -40) { destY = 24 + 32; }
	else if (stefan.Y() == 24 && destY == -8) { destY = 24; }
	else if (stefan.Y() == 664 && destY == 728) { destY = 664 - 32; }
	else if (stefan.Y() == 664 && destY == 696) { destY = 664; }

	if (stefan.X() > destX) { stefan.setXY(stefan.X() - 4, stefan.Y()); }
	else if (stefan.X() < destX) { stefan.setXY(stefan.X() + 4, stefan.Y()); }
	if (stefan.Y() > destY) { stefan.setXY(stefan.X(), stefan.Y() - 4); }
	else if (stefan.Y() < destY) { stefan.setXY(stefan.X(), stefan.Y() + 4); }

	if (stefan.X() == destX && stefan.Y() == destY) { isMoving = false; }
}

void StefanManager::render(SDL_Renderer* renderer)
{
	stefan.render(renderer);
}
