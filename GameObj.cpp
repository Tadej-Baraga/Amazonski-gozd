#include "GameObj.h"
#include "TextureManager.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;
 

GameObject::GameObject(const char* texturesheet,int x, int y)
{
	objTexture = TextureManager::LoadText(texturesheet);
	xpos = 40*x;
	ypos = 40*y;
}
void GameObject::Update()
{	
	srcRect.x = xpos;
	srcRect.y = ypos;
	srcRect.w = 40;
	srcRect.h = 40;

	if (Game::event.type == SDL_KEYDOWN)
	{

		if (Game::event.key.keysym.sym == SDLK_w)
			ypos -= 10;
		if (Game::event.key.keysym.sym == SDLK_s)
			ypos += 10;
		if (Game::event.key.keysym.sym == SDLK_a)
			xpos -= 10;
		if (Game::event.key.keysym.sym == SDLK_d)
			xpos += 10;

	}
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
void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}
SDL_Rect GameObject::Rectangle()
{
	return destRect;

}