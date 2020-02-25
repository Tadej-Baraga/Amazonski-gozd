#include "Include.h"

using namespace std;

GameObjectEnemy::GameObjectEnemy(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadText(texturesheet);
	xpos = 40 * x;
	ypos = 40 * y;
}
void GameObjectEnemy::Update()
{
	srcRect.x = xpos;
	srcRect.y = ypos;
	srcRect.w = 40;
	srcRect.h = 40;
	int x = rand() % 3 - 1;
	int y = rand() % 3 - 1;
	xpos += x;
	ypos += y;
	if (xpos > 760)
		xpos = 760;
	if (xpos < 0)
		xpos = 0;
	if (ypos > 760)
		ypos = 760;
	if (ypos < 0)
		ypos = 0;
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 40;
	destRect.h = 40;
}
void GameObjectEnemy::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}
SDL_Rect GameObjectEnemy::Rectangle()
{
	return destRect;
}