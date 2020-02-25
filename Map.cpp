#include "Map.h"
#include "TextureManager.h"
#include "Include.h"
int lvl1[20][20] = { 
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

Map::Map()
{
	Drevesa = TextureManager::LoadText("Textures/Drevesa.png");
	Posekano = TextureManager::LoadText("Textures/Posekano.png");
	Pozar = TextureManager::LoadText("Textures/Pozar.png");
	Zazgano = TextureManager::LoadText("Textures/Zazgano.png");
	LoadMap(lvl1);
	src.x = src.y = 0;
	src.w = dest.w = 40;
	src.h = dest.h = 40;
	dest.x = dest.y = 0;
}
Map::~Map()
{
	SDL_DestroyTexture(Drevesa);
}
void Map::LoadMap(int arr[20][20])
{
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			map[i][j] = arr[i][j];
		}
	}
	map[rand() % 20 + 1][rand() % 20 + 1] = 1;
	map[rand() % 20 + 1][rand() % 20 + 1] = 1;
	map[rand() % 20 + 1][rand() % 20 + 1] = 1;
	map[rand() % 20 + 1][rand() % 20 + 1] = 1;
}

void Map::DrawMap()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			dest.x = j * 40;
			dest.y = i * 40;
			switch (map[i][j])
			{
			case 0:
				TextureManager::Draw(Drevesa, src, dest);
				break;
			case 1:
				TextureManager::Draw(Pozar, src, dest);
				break;
			case 2:
				TextureManager::Draw(Posekano, src, dest);
				break;
			case 3:
				TextureManager::Draw(Zazgano, src, dest);
				break;
			}
		}
	}
}


void Map::CheckGood(const SDL_Rect recB)
{

	if(map[recB.x / 40][recB.y / 40] == 1)
		map[recB.x / 40][recB.y / 40] = 3;
}
void Map::CheckGood2(const SDL_Rect recB)
{
	srand(time(NULL));
	if (map[recB.x / 40][recB.y / 40] == 1)
		if (rand() % 2)
			map[recB.x / 40][recB.y / 40] = 3;
}
void Map::CheckBad(const SDL_Rect recB)
{
	srand(time(NULL));
	cout << recB.x / 40 << " " << recB.y / 40 << endl;
	if (map[recB.x / 40][recB.y / 40] == 0)
		//if (rand() % 5 == 0)
			map[recB.x / 40][recB.y / 40] = 1;
}
