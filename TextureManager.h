#pragma once
#include "Game.h"

using namespace std;

class TextureManager {

public:
	static SDL_Texture* LoadText(const char* fileName);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
	
};