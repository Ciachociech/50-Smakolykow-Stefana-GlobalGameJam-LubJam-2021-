#include "SteeringManager.h"

SteeringManager::SteeringManager() : combo(0) {}

SteeringManager::~SteeringManager() {}

keyAction SteeringManager::keyboardMovement(int& x, int& y, SDL_Keycode keycode)
{
    checkMischievousCombo(keycode);
    printf("Combo: %i\n", combo);

    if (keycode == SDLK_w || keycode == SDLK_UP) { y = -2; return keyAction::moving; }
    else if (keycode == SDLK_s || keycode == SDLK_DOWN) { y = 2; return keyAction::moving; }
    if (keycode == SDLK_a || keycode == SDLK_LEFT) 
    { 
        if (combo == 10) { return keyAction::mischievous; }
        else { x = -2; return keyAction::moving; }
    }
    else if (keycode == SDLK_d || keycode == SDLK_RIGHT) { x = 2; return keyAction::moving; }

    if (keycode == SDLK_z) { return keyAction::digging; }

    return keyAction::none;
}

void SteeringManager::checkMischievousCombo(SDL_Keycode keycode)
{
    if (combo < 2 && (keycode == SDLK_w || keycode == SDLK_UP)) { combo++; return; }
    else if (combo < 4 && (keycode == SDLK_s || keycode == SDLK_DOWN)) { combo++; return; }
    else if ((combo == 4 || combo == 6) && (keycode == SDLK_a || keycode == SDLK_LEFT)) { combo++; return; }
    else if ((combo == 5 || combo == 7) && (keycode == SDLK_d || keycode == SDLK_RIGHT)) { combo++; return; }
    else if (combo == 8 && keycode == SDLK_b) { combo++; return; }
    else if (combo == 9 && keycode == SDLK_a) { combo++; return; }

    combo = 0;
}