#include "BodyUp.h"

BodyUp::BodyUp (void) {}

BodyUp::BodyUp (const Rectangle & rect):
	Rectangle(rect)
{}

BodyUp::~BodyUp (void) {}

void BodyUp::forward (Rectangle & tracker, float speed) 
{
	tracker.moveY(-speed);
	Rectangle::moveY(-speed);
	Rectangle::addHeight(speed);
}

void BodyUp::backward (Rectangle & tracker, float speed)
{
	tracker.moveY(speed);
	Rectangle::moveY(speed);
	Rectangle::addHeight(-speed);
}

void BodyUp::draw (void)
{
	Rectangle::draw();
}

void BodyUp::setColor (int r, int g, int b)
{
	Rectangle::setColor(r, g, b);
}
