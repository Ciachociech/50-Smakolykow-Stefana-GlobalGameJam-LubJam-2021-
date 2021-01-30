#pragma once

#include "external_dependencies.h"

class SteeringManager
{
public:
	SteeringManager();
	virtual ~SteeringManager();

	void keyboardMovement(int& x, int& y, SDL_Keycode keycode);
private:

};

