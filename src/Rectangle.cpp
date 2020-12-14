#include "Rectangle.h"

Rectangle::Rectangle (void):
	position_(glm::ivec2(0, 0)),
	width_(0),
	height_(0),
	color_(Color::make(0, 255, 0, 255))
{}

Rectangle::~Rectangle (void) {}
		
void Rectangle::setPosition (int x, int y)
{
	position_ = glm::ivec2(0, 0);
}

void Rectangle::setPositionX (int x)
{
	position_.x = x;
}

void Rectangle::setPositionY (int y)
{
	position_.y = y;
}

glm::ivec2 Rectangle::getPosition (void) const
{
	return position_;
}

int Rectangle::getPositionX (void) const
{
	return position_.x;
}

int Rectangle::getPositionY (void) const
{
	return position_.y;
}

void Rectangle::setSize (int w, int h)
{
	Rectangle::setWidth(w);
	Rectangle::setHeight(h);
}
		
void Rectangle::setWidth (int w)
{
	width_ = w;
}

void Rectangle::setHeight (int h)
{
	height_ = h;
}

glm::ivec2 Rectangle::getSize (void) const
{
	return glm::ivec2(width_, height_);
}

int Rectangle::getWidth (void) const
{
	return width_;
}

int Rectangle::getHeight (void) const
{
	return height_;
}

void Rectangle::setColor (Color color)
{
	color_ = color;
}

Color Rectangle::getColor (void) const
{
	return color_;
}

void Rectangle::draw (void)
{
	GameRenderer::draw(position_.x, position_.y, width_, height_, color_);	
}
