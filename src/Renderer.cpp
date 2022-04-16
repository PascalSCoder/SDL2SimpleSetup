#include <Renderer.hpp>

#include <iostream>

Renderer::Renderer(std::string const& title, int w, int h) : _title(title), _width(w), _height(h)
{
	_window = nullptr;
	_surface = nullptr;
	_renderer = nullptr;
}

Renderer::~Renderer()
{
	if (_renderer != nullptr)
		SDL_DestroyRenderer(_renderer);
	if (_window != nullptr)
		SDL_DestroyWindow(_window);
	SDL_Quit();
	std::cout << "Renderer destroyed" << std::endl;
}

bool Renderer::initialize()
{
	_window = SDL_CreateWindow("Fluidsss", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_SHOWN);
	if (_window == NULL)
	{
		std::cout << "Create window failed: " << SDL_GetError() << std::endl;
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED );
	if(_renderer == NULL)
	{
		printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
	_surface = SDL_GetWindowSurface(_window);
	if (_surface == NULL)
		return false;

	return true;
}

void Renderer::render()
{
	SDL_Rect rect = { 0, 0, _width, _height };
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(_renderer, &rect);
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for (int i = 0; i < _height; i++)
	{
		SDL_RenderDrawPoint(_renderer, _width / 2, i);
	}
	SDL_RenderPresent(_renderer);
}
