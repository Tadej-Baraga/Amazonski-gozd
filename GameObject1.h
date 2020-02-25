#pragma once
#include "Game.h"
class GameObject1 {

public:
	GameObject1(const char* texturesheet, int x, int y);
	~GameObject1();

	void Update();
	void Render();
	SDL_Rect Rectangle();
private:
	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};