#pragma once

#include "external_dependencies.h"

#include "OverworldRandomizer.h"
#include "Treasure.h"

typedef std::vector<std::unique_ptr<Treasure>> VecTreasures;

class TreasureManager
{
public:
	TreasureManager();
	~TreasureManager();

	void randomizeTreasures(SDL_Renderer* renderer);
	void render(SDL_Renderer* renderer);

	int getCount();
private:
	VecTreasures treasures;
	int count;
	OverworldRandomizer overand;

	treasureType randomizeType();
};

