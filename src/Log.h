#ifndef LOG_H
#define LOG_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>

#include "Text.h"

class Log
{
	public:
		~Log (void);

		static void add (const int number);
		static void add (const std::string message);
		static void setRenderer (SDL_Renderer & renderer);
		static void draw (void);

	private:
		Log (void);
		
		void setTextRenderer (SDL_Renderer & renderer);
		void addText (const std::string message);
		void drawText (void);
		void update (void);
		void checkLength (void);
		
		static Log instance_;
		int render_;
		std::vector<std::string> log_;
		Text* text_;
};

#endif
