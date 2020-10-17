#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>
#include <SDL2/SDL.h>
#include "snake.h"

SDL_Window* window;
SDL_Renderer* renderer;

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return -1;

	window = SDL_CreateWindow( "Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 960, 544, SDL_WINDOW_SHOWN );
	
	if ( window == nullptr)
		return -1;

	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_PRESENTVSYNC );

	if (renderer == nullptr)
		return -1;
	
	sceCtrlSetSamplingMode( SCE_CTRL_MODE_DIGITAL );
	SceCtrlData control;
	
	Snake snake (20, 20);

	bool run = true;
	while (run)
	{
		SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
		SDL_RenderClear( renderer );
		
		SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
		snake.draw( *renderer );

		SDL_RenderPresent( renderer );
	}
	
	SDL_DestroyWindow( window );
	SDL_DestroyRenderer( renderer );
	
	SDL_Quit();
	sceKernelExitProcess(0);

	return 0;
}
