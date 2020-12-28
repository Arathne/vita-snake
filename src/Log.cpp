#include "Log.h"

#define FONT_SIZE 14
#define LOG_SIZE 10

/* STATIC */

Log Log::instance;

void Log::add (const int number)
{
	Log::add(std::to_string(number));
}

void Log::add (const std::string message)
{
	instance.log_.push_back(message);
	instance.checkLength();
	instance.update();
}

void Log::setRenderer (SDL_Renderer & renderer)
{
	int y = 0;
	
	for (int i = 0; i < instance.render_; i++)
	{
		Text* current = &(instance.text_[i]);
		current -> setPositionY(y);
		current -> setRenderer(renderer);
		current -> setFont("app0:/assets/joystix.ttf", FONT_SIZE);
		y += current -> getHeight();
	}
}

void Log::draw (void)
{
	for (int i = 0; i < instance.render_; i++)
	{
		instance.text_[i].draw();
	}
}

/* INSTANCE */

Log::Log (void):
	render_(LOG_SIZE),
	text_(new Text[render_])
{}

Log::~Log (void) 
{
	delete[] text_; 
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
