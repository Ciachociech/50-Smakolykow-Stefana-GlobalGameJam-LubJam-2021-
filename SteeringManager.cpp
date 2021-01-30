#include "SteeringManager.h"

SteeringManager::SteeringManager() {}

SteeringManager::~SteeringManager() {}

void SteeringManager::keyboardMovement(int& x, int& y, SDL_Keycode keycode)
{
    if (keycode == SDLK_UP || keycode == SDLK_w) { y = -2; }
    else if (keycode == SDLK_DOWN || keycode == SDLK_s) { y = 2; }
    if (keycode == SDLK_LEFT || keycode == SDLK_a) { x = -2; }
    else if (keycode == SDLK_RIGHT || keycode == SDLK_d) { x = 2; }
}

