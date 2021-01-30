#include "OverworldRandomizer.h"

OverworldRandomizer::OverworldRandomizer()
{
    gen.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
}

OverworldRandomizer::~OverworldRandomizer() {}

SDL_Color OverworldRandomizer::randomColor()
{
    std::uniform_int_distribution<int> dist7(0, 128);
    std::uniform_real_distribution<float> distF(-4.f, 4.f);

    SDL_Color clr;
    clr.r = dist7(gen);
    clr.g = dist7(gen);
    clr.b = dist7(gen);
    clr.a = 0xC0;
    return clr;
}
int OverworldRandomizer::randomNumber(int min, int max)
{
    std::uniform_int_distribution<int> distI(min, max);
    return distI(gen);
}