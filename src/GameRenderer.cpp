#include "GameRenderer.h"

SDL_Window* GameRenderer::window_ = nullptr;
SDL_Renderer* GameRenderer::renderer_ = nullptr;

void GameRenderer::init (void)
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	window_ = SDL_CreateWindow( "Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 544, SDL_WINDOW_SHOWN );
	renderer_ = SDL_CreateRenderer( window_, -1, SDL_RENDERER_PRESENTVSYNC );
}

void GameRenderer::destroy (void)
{
	if (renderer_ != nullptr)
		SDL_DestroyRenderer(renderer_);

	if (window_ != nullptr)
		SDL_DestroyWindow(window_);
	
	TTF_Quit();
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

void GameRenderer::draw (int x, int y, int w, int h, Color color)
{
	SDL_Rect rectangle;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;

	SDL_SetRenderDrawColor( renderer_, color.red(), color.green(), color.blue(), color.alpha() );
	SDL_RenderFillRect( renderer_, &rectangle );
}

void GameRenderer::draw (int x, int y, int w, int h, SDL_Texture & texture)
{
	SDL_Rect rectangle;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;
	
	SDL_SetRenderDrawColor( renderer_, 0, 0, 0, 255 );
	SDL_RenderCopy( renderer_, &texture, nullptr, &rectangle );
}

SDL_Renderer & GameRenderer::getRenderer (void)
{
	return *renderer_;
}
