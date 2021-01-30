#pragma once
#include "external_dependencies.h"

class OverworldRandomizer
{
public:
	OverworldRandomizer();
	virtual ~OverworldRandomizer();
	SDL_Color randomColor();
	int randomNumber(int min, int max);
private:
	std::default_random_engine gen;
}; 

