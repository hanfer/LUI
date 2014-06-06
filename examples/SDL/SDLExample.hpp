#pragma once

#include <SDL.h>

class SDLExample
{
public:
	SDLExample();
	SDLExample(const SDLExample &rval) = delete;
	~SDLExample();

	SDLExample& operator=(const SDLExample &rval) = delete;

	int run();

private:
	void eventLoop();
	bool init();

	bool stop;

	SDL_Window *window;
	SDL_GLContext ctx;
};