#include "Log.h"

#define FONT_SIZE 14

Log Log::instance_;

Log::Log (void):
	render_(10),
	text_(new Text[render_])
{}

Log::~Log (void) 
{
	delete[] text_; 
}

/* STATIC */

void Log::add (const int number)
{
	instance_.addText(std::to_string(number));
}

void Log::add (const std::string message)
{
	instance_.addText(message);
}

void Log::setRenderer (SDL_Renderer & renderer)
{
	instance_.setTextRenderer(renderer);
}

void Log::draw (void)
{
	instance_.drawText();
}

/* INSTANCE */

void Log::addText (const std::string message)
{
	log_.push_back(message);
	Log::checkLength();
	Log::update();
}

void Log::drawText (void)
{
	for (int i = 0; i < render_; i++)
	{
		text_[i].draw();
	}
}

void Log::setTextRenderer (SDL_Renderer & renderer)
{
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
