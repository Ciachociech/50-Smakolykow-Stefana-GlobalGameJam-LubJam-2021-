#include "TreasureManager.h"

TreasureManager::TreasureManager() : overand(), treasures(), count(0) {}

TreasureManager::~TreasureManager() { treasures.~vector(); }

void TreasureManager::randomizeTreasures(SDL_Renderer* renderer)
{
	this->count = overand.randomNumber(4, 5);

	for (int i = this->count; i != 0; i--) {
		int x, y;
		bool isHere;
		do
		{
			x = 0, y = 0;
			isHere = false;

			overand.randomCoordsTreasure(x, y);

			for (int j = 0; j < treasures.size(); j++)
			{
				if (((x + 96) > (treasures[j]->X() - 32)) && ((treasures[j]->X() + 96) > (x - 32)) && ((y + 96) > (treasures[j]->Y() - 32)) && ((treasures[j]->Y() + 96) > (y - 32))) { isHere = true; }
			}

		} while (isHere);
		
		treasures.push_back(std::make_unique<Treasure>(randomizeType()));
		treasures.back()->loadFromFile(1.f, 1.f, treasures.back()->getAssetPath(), renderer);
		treasures.back()->setXY(x, y);
	}
}

void TreasureManager::render(SDL_Renderer* renderer)
{
	for (int i = 0; i < treasures.size(); i++)
	{
		treasures[i]->render(renderer);
	}
}

int TreasureManager::getCount() { return count; }

treasureType TreasureManager::randomizeType()
{
	switch (overand.randomNumber(1, 3))
	{
	case 1: { return treasureType::carrots; break; }
	case 2: { return treasureType::mniszek; break; }
	case 3: { return treasureType::salad; break; }
	default: { return treasureType::none; break; }
	}
}
