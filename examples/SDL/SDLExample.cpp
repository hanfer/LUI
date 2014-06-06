#include "SDLExample.hpp"

#include <iostream>

SDLExample::SDLExample()
	: stop(false)
	, window(nullptr)
{

}

SDLExample::~SDLExample()
{
	SDL_GL_DeleteContext(ctx);

	if(window) 
		SDL_DestroyWindow(window);

	SDL_Quit();
}

bool SDLExample::init()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	if((window = SDL_CreateWindow("LUI SDL OpenGL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)) == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}

	ctx = SDL_GL_CreateContext(window);

	return true;
}

int SDLExample::run()
{
	if(!init())
		return -1;

	eventLoop();
	return 0;
}

void SDLExample::eventLoop()
{
	SDL_Event ev;

	while(!stop && SDL_WaitEvent(&ev))
	{
		switch(ev.type)
		{
		case SDL_KEYDOWN:
			if(ev.key.keysym.sym != SDLK_ESCAPE)
				break;

		case SDL_QUIT:
			stop = true;
			break;

		default:
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	SDLExample example;
	return example.run();
}