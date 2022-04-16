#include <SDL2/SDL.h>

#include <string>

class Renderer
{
public:
	Renderer(std::string const& title, int w, int h);
	~Renderer();

	bool initialize();
	void render();

private:
	SDL_Window* _window;
	SDL_Surface* _surface;
	SDL_Renderer* _renderer;
	std::string _title;
	int _width;
	int _height;
};
