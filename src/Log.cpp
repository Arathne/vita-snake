#include "Log.h"

#define FONT_SIZE 14

int Log::render_ = 0;
std::vector<std::string> Log::log_;
Text* Log::text_;

void Log::render (SDL_Renderer & renderer, int length)
{
	render_ = length;
	text_ = new Text[render_];
	
	int y = 0;

	for (int i = 0; i < render_; i++)
	{
		Text* current = &(text_[i]);
		current -> setPositionY(y);
		current -> setRenderer(renderer);
		current -> setFont("app0:/assets/joystix.ttf", FONT_SIZE);
		y += current -> getHeight();
	}
}

void Log::destroy (void)
{
	delete[] text_;
}

void Log::add (const int number)
{
	Log::add(std::to_string(number));
}

void Log::add (const std::string message)
{
	log_.push_back(message);
	Log::checkLength();
	Log::update();
}

void Log::update (void)
{
	int i = 0;
	for (auto it = log_.rbegin(); it != log_.rend() && i < render_; it++, i++)
	{
		text_[render_-i-1].setContent((*it).c_str());
	}
}

void Log::checkLength (void)
{
	if (log_.size() > render_)
	{
		log_.erase(log_.begin());
	}
}

void Log::draw (void)
{
	for (int i = 0; i < render_; i++)
	{
		text_[i].draw();
	}
}
