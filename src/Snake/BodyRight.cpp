#include "BodyRight.h"

BodyRight::BodyRight (void) {}

BodyRight::BodyRight (const Rectangle & rect):
	Rectangle(rect)
{}

BodyRight::~BodyRight (void) {}

void BodyRight::forward (Rectangle & tracker, float speed) 
{
	tracker.moveX(speed);
	Rectangle::addWidth(speed);
}

void BodyRight::backward (Rectangle & tracker, float speed)
{
	tracker.moveX(-speed);
	Rectangle::addWidth(-speed);
}

void BodyRight::draw (void)
{
	Rectangle::draw();
}

void BodyRight::setColor (int r, int g, int b)
{
	Rectangle::setColor(r, g, b);
}

void BodyRight::reduce (float speed)
{
	Rectangle::moveX(speed);
	Rectangle::addWidth(-speed);
}

float BodyRight::getLength (void)
{
	return Rectangle::getWidth();
}
