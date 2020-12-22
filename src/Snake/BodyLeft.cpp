#include "BodyLeft.h"

BodyLeft::BodyLeft (void) {}
		
BodyLeft::BodyLeft (const Rectangle & rect):
	Rectangle(rect)
{}

BodyLeft::~BodyLeft (void) {}

void BodyLeft::forward (Rectangle & tracker, float speed) 
{
	tracker.moveX(-speed);
	Rectangle::moveX(-speed);
	Rectangle::addWidth(speed);
}

void BodyLeft::backward (Rectangle & tracker, float speed)
{

}

void BodyLeft::draw (void)
{
	Rectangle::draw();
}

void BodyLeft::setColor (int r, int g, int b)
{
	Rectangle::setColor(r, g, b);
}
