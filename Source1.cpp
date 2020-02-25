#include "TextureManager.h"


SDL_Texture* TextureManager::LoadText(const char* texture, SDL_Renderer* ren)
{
	SDL_Surface* tmpSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tex;
}