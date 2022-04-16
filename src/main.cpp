#include <SDL2/SDL.h>
#include <iostream>

#include <Renderer.hpp>
#include <InputHandler.hpp>

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL init failed: " << SDL_GetError() << std::endl;
		return false;
	}

	Renderer renderer("SDL window", 1024, 768);
	if (!renderer.initialize())
	{
		std::cout << "Init error" << std::endl;
		return 1;
	}
	InputHandler inputHandler;

	int i = 0;
	while (true)
	{
		if (inputHandler.handle() == false)
			break;
		renderer.render();

		if (++i >= 500)
		{
			i = 0;
			std::cout << "Tick" << std::endl;
		}
	}
}
