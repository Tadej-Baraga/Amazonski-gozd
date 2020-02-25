#pragma once
#include "Game.h"

class Map
{
public:
	Map();
	~Map();

	void LoadMap(int arr[20][20]);
	void DrawMap();
	void CheckGood(const SDL_Rect recB);
	void CheckGood2(const SDL_Rect recB);
	void CheckBad(const SDL_Rect recB);
	static int a, b;
private:
	SDL_Rect src, dest;

	SDL_Texture *Drevesa,*Posekano,*Pozar,*Zazgano;

	int map[20][20];
};