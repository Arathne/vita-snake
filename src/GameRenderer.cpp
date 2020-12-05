#include "GameRenderer.h"

SDL_Window* GameRenderer::window_ = nullptr;
SDL_Renderer* GameRenderer::renderer_ = nullptr;

void GameRenderer::init (void)
{
	SDL_Init(SDL_INIT_VIDEO);
	window_ = SDL_CreateWindow( "Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 544, SDL_WINDOW_SHOWN );
	renderer_ = SDL_CreateRenderer( window_, -1, SDL_RENDERER_PRESENTVSYNC );
}

void GameRenderer::destroy (void)
{
	if (renderer_ != nullptr)
		SDL_DestroyRenderer(renderer_);

	if (window_ != nullptr)
		SDL_DestroyWindow(window_);
}

void GameRenderer::drawRect (int x, int y, int w, int h)
{
	SDL_Rect rectangle;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;

	SDL_SetRenderDrawColor( renderer_, 0, 255, 0, 255 );
	SDL_RenderFillRect( renderer_, &rectangle );
}

void GameRenderer::present (void)
{
	SDL_RenderPresent( renderer_ );
}

void GameRenderer::clear (void)
{
	SDL_SetRenderDrawColor( renderer_, 0, 0, 0, 255 );
	SDL_RenderClear( renderer_ );
}
