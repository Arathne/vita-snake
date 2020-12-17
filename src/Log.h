#ifndef LOG_H
#define LOG_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>

#include "Text.h"

class Log
{
	public:
		static void render (SDL_Renderer & renderer, int length);
		static void add (const int number);
		static void add (const std::string message);
		static void destroy (void);

		static void draw (void);

	private:
		static void update (void);
		static void checkLength (void);

		static int render_;
		static std::vector<std::string> log_;
		static Text* text_;
};

#endif
