#pragma once
#include "Game.h"
class GameObjectEnemy{

public:
	GameObjectEnemy(const char* texturesheet, int x, int y);
	~GameObjectEnemy();

	void Update();
	void Render();
	SDL_Rect Rectangle();
private:
	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};