#include "SteeringManager.h"

SteeringManager::SteeringManager() : combo(0) {}

SteeringManager::~SteeringManager() {}

keyAction SteeringManager::keyboardMovement(int& x, int& y, SDL_Keycode keycode)
{
    checkMischievousCombo(keycode);
    checkAnotherEvilCombo(keycode);

    if (keycode == SDLK_w || keycode == SDLK_UP) { y = -2; return keyAction::moving; }
    else if (keycode == SDLK_s || keycode == SDLK_DOWN) { y = 2; return keyAction::moving; }
    if (keycode == SDLK_a || keycode == SDLK_LEFT) 
    { 
        if (combo == 10) { return keyAction::mischievous; }
        else { x = -2; return keyAction::moving; }
    }
    else if (keycode == SDLK_d || keycode == SDLK_RIGHT) { x = 2; return keyAction::moving; }

    if (keycode == SDLK_l) { return keyAction::digging; }
    if (keycode == SDLK_p) { return keyAction::steeringHelp; }
    if (keycode == SDLK_n) { return keyAction::anotherEvil; }

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

void SteeringManager::checkAnotherEvilCombo(SDL_Keycode keycode)
{
    if (combo == 0 && keycode == SDLK_s) { combo++; return; }
    else if (combo == 1 && keycode == SDLK_t) { combo++; return; }
    else if (combo == 2 && keycode == SDLK_e) { combo++; return; }
    else if (combo == 3 && keycode == SDLK_f) { combo++; return; }
    else if (combo == 4 && keycode == SDLK_a) { combo++; return; }
    else if (combo == 5 && keycode == SDLK_n) { combo++; return; }
}
