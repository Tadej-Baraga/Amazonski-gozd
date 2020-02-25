#pragma once
#if Game_h
#endif Game_h
#define Game_h
#include <stdio.h>
#include "SDL.h"
class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height , bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; }
	static SDL_Renderer* renderer;
	static SDL_Event event;

private:
	int i = 1;
	bool isRunning;
	SDL_Window* window;
};

