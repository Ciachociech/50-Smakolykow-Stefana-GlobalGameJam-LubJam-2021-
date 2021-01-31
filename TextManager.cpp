#include "TextManager.h"

TextManager::TextManager() : texts(), overand() {}

TextManager::~TextManager() { texts.~vector(); }

void TextManager::initalize(TTF_Font* font, SDL_Renderer* renderer)
{
	SDL_Color color1 = overand.randomColor(), color2 = overand.randomColor(), color3 = overand.randomColor();
	
	texts.push_back(std::make_unique<Text>());
	texts.back()->loadFromText("Poziom:", color1, renderer, font);
	texts.back()->setXY(36, 200);
	texts.push_back(std::make_unique<Text>());
	texts.back()->loadFromText("Motywacja:", color2, renderer, font);
	texts.back()->setXY(36, 300);
	texts.push_back(std::make_unique<Text>());
	texts.back()->loadFromText("Kafelki do odkrycia:", color3, renderer, font);
	texts.back()->setXY(36, 400);
	texts.push_back(std::make_unique<Text>());
	texts.back()->loadFromText("0", color1, renderer, font);
	texts.back()->setXY(336, 200);
	texts.push_back(std::make_unique<Text>());
	texts.back()->loadFromText("-1:", color2, renderer, font);
	texts.back()->setXY(336, 300);
	texts.push_back(std::make_unique<Text>());
	texts.back()->loadFromText("-1", color3, renderer, font);
	texts.back()->setXY(336, 400);
}

void TextManager::update(std::string newValue, int index, TTF_Font* font, SDL_Renderer* renderer)
{
	if (index > 2 && index < texts.size())
	{
		texts[index]->loadFromText(newValue, texts[index]->getColor(), renderer, font);
	}
}

void TextManager::render(SDL_Renderer* renderer) 
{
	for (int i = 0; i < texts.size(); i++) { texts[i]->render(renderer); }
}

void TextManager::exterminate()
{
	texts.clear();
}
