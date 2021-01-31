#include "Text.h"

Text::Text() : Graph(), txt(std::string()), txtColor() {}

Text::Text(int x, int y) : Graph(), txt(std::string()), txtColor() {}

Text::~Text() {}

bool Text::loadFromText(std::string textureText, SDL_Color textColor, SDL_Renderer* renderer, TTF_Font* font)
{
	txt = textureText;
	txtColor = textColor;
	return Graph::loadFromText(textureText, textColor, renderer, font);
}

void Text::setText(std::string newTxt) { this->txt = newTxt; }

std::string& Text::getText() { return this->txt; }

SDL_Color Text::getColor() { return txtColor; }
