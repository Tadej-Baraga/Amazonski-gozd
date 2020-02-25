#include "Include.h"

using namespace std;

Map* map;

GameObject* Me;
GameObjectEnemy* Enemy1, * Enemy2, * Enemy3;
GameObject1 *Staroselci1, * Staroselci2;

SDL_Renderer* Game::renderer =  NULL;
SDL_Event Game::event;



Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsystems Initialised!..." << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window) {
			cout << "Window created!" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			cout << "Renderer creater!" << endl;
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}	//Èe se SDL ne zazene prav se game shutadown!

	
	Me = new GameObject("Textures/Me.png",0,0);
	Enemy1 = new GameObjectEnemy("Textures/Enemy.png", rand() % 20, rand() % 20);
	Enemy2 = new GameObjectEnemy("Textures/Enemy.png", rand() % 20, rand() % 20);
	Enemy3 = new GameObjectEnemy("Textures/Enemy.png", rand() % 20, rand() % 20);
	Staroselci1 = new GameObject1("Textures/Staroselci.png", rand()%20, rand() % 20);
	Staroselci2 = new GameObject1("Textures/Staroselci.png", rand() % 20, rand() % 20);
	
	map = new Map();


}

void Game::handleEvents()
{

	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	}
}

void Game::update()
{
	SDL_Rect x;

	Me->Update();
	Enemy1->Update();
	Enemy2->Update();
	Enemy3->Update();
	Staroselci1->Update();
	Staroselci2->Update();
	map->CheckGood(Me->Rectangle());
	map->CheckBad(Enemy1->Rectangle());
	map->CheckBad(Enemy2->Rectangle());
	map->CheckBad(Enemy3->Rectangle());
	map->CheckGood2(Staroselci1->Rectangle());
	map->CheckGood2(Staroselci2->Rectangle());
}

void Game::render()
{

	SDL_RenderClear(renderer);	//Koda za renderer
	map->DrawMap();
	Me->Render();
	Enemy1->Render();
	Enemy2->Render();
	Enemy3->Render();
	Staroselci1->Render();
	Staroselci2->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game cleaned!" << endl;
}

