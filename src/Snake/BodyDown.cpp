#include "BodyDown.h"

BodyDown::BodyDown (void) {}

BodyDown::BodyDown (const Rectangle & rect):
	Rectangle(rect)
{}

BodyDown::~BodyDown (void) {}

void BodyDown::forward (Rectangle & tracker, float speed) 
{
	tracker.moveY(speed);
	Rectangle::addHeight(speed);
}

void BodyDown::backward (Rectangle & tracker, float speed)
{

}

void BodyDown::draw (void)
{
	Rectangle::draw();
}

void BodyDown::setColor (int r, int g, int b)
{
	Rectangle::setColor(r, g, b);
}