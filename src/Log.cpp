#include "Log.h"

#define FONT_SIZE 14

int Log::render_ = 0;
std::vector<const char*> Log::log_;
Text* Log::draw_;

void Log::render (SDL_Renderer & renderer, int length)
{
	render_ = length;
	draw_ = new Text[render_];
	
	int y = 0;

	for (int i = 0; i < render_; i++)
	{
		Text* current = &(draw_[i]);
		current -> setPositionY(y);
		current -> setRenderer(renderer);
		current -> setFont("app0:/assets/joystix.ttf", FONT_SIZE);
		y += current -> getHeight();
	}
}

void Log::destroy (void)
{
	delete[] draw_;
}

void Log::add (const char* message)
{
	log_.push_back(message);
	Log::update();
}

void Log::update (void)
{
	int i = 0;
	for (auto it = log_.rbegin(); it != log_.rend() && i < render_; it++, i++)
	{
		draw_[render_-i-1].setContent(*it);
	}
}

void Log::draw (void)
{
	for (int i = 0; i < render_; i++)
	{
		draw_[i].draw();
	}
}
