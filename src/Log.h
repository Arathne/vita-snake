#ifndef LOG_H
#define LOG_H

#include <SDL2/SDL.h>
#include <vector>

#include "Text.h"

class Log
{
	public:
		static void render (SDL_Renderer & renderer, int length);
		static void add (const char* message);
		static void destroy (void);
		
		static void draw (void);

	private:
		static void update (void);
		
		static int render_;
		static std::vector<const char*> log_;
		static Text* text_;
};

#endif
