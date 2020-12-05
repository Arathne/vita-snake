#ifndef GAME_RENDERER_H
#define GAME_RENDERER_H

#include <SDL2/SDL.h>

class GameRenderer
{
	public:
		static void init (void);
		static void destroy (void);

		static void clear (void);
		static void present (void);
		static void drawRect (int x, int y, int w, int h);
	
	private:
		static SDL_Window* window_;
		static SDL_Renderer* renderer_;
};

#endif
