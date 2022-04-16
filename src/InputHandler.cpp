#include <InputHandler.hpp>

InputHandler::InputHandler()
{}

InputHandler::~InputHandler()
{}

/*
	Returns false if the user requested to close the window.
*/
bool InputHandler::handle()
{
	while( SDL_PollEvent( &_event ) != 0 )
	{
		//User requests quit
		if( _event.type == SDL_QUIT )
		{
			return false;
		}

		//User presses a key
		else if( _event.type == SDL_KEYDOWN )
		{
			//Select surfaces based on key press
			switch( _event.key.keysym.sym )
			{
				// case SDLK_UP:
				// gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
				// break;
			}
		}
	}
	return true;
}
