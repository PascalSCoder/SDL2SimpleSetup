#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	bool handle();

private:
	SDL_Event _event;

};
