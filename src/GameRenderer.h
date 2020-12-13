#ifndef GAME_RENDERER_H
#define GAME_RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Color.h"

class GameRenderer
{
	public:
		static void init (void);
		static void destroy (void);
		static void clear (void);
		static void present (void);
		
		static void draw (int x, int y, int w, int h, Color color);
		static void draw (int x, int y, int w, int h, Color color, SDL_Texture & texture );

		static SDL_Renderer & getRenderer (void);
		
	private:
		static SDL_Window* window_;
		static SDL_Renderer* renderer_;
};

#endif
