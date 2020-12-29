#include "Rectangle.h"

Rectangle::Rectangle (void):
	position_(glm::vec2(0.0, 0.0)),
	width_(0),
	height_(0),
	color_(Color::make(0, 255, 0, 255))
{}

Rectangle::Rectangle (float x, float y, int w, int h):
	position_(glm::vec2(x, y)),
	width_(w),
	height_(h),
	color_(Color::make(0, 255, 0, 255))
{}

Rectangle::Rectangle (const Rectangle & rhs)
{
	position_ = rhs.position_;
	width_ = rhs.width_;
	height_ = rhs.height_;
	color_ = rhs.color_;
}

Rectangle::~Rectangle (void) {}
		
void Rectangle::setPosition (float x, float y)
{
	position_.x = x;
	position_.y = y;
}

void Rectangle::setPositionX (float x)
{
	position_.x = x;
}

void Rectangle::setPositionY (float y)
{
	position_.y = y;
}

void Rectangle::addPositionX (float x)
{
	position_.x += x;
}

void Rectangle::addPositionY (float y)
{
	position_.y += y;
}

glm::vec2 Rectangle::getPosition (void) const
{
	return position_;
}

float Rectangle::getPositionX (void) const
{
	return position_.x;
}

float Rectangle::getPositionY (void) const
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

glm::vec2 Rectangle::getSize (void) const
{
	return glm::vec2(width_, height_);
}

int Rectangle::getWidth (void) const
{
	return width_;
}

int Rectangle::getHeight (void) const
{
	return height_;
}

void Rectangle::addWidth (int w)
{
	width_ += w;
}

void Rectangle::addHeight (int h)
{
	height_ += h;
}

void Rectangle::setColor (Color color)
{
	color_ = color;
}

void Rectangle::setColor (int red, int green, int blue)
{
	color_ = Color::make(red, green, blue, 255);
}

Color Rectangle::getColor (void) const
{
	return color_;
}

void Rectangle::move (float x, float y)
{
	Rectangle::moveX(x);
	Rectangle::moveY(y);
}

void Rectangle::moveX (float x)
{
	position_.x = position_.x + x;
}

void Rectangle::moveY (float y)
{
	position_.y = position_.y + y;
}

void Rectangle::draw (void)
{
	GameRenderer::draw(position_.x, position_.y, width_, height_, color_);	
}

const Rectangle & Rectangle::operator = (const Rectangle & rhs)
{
	if (&rhs != &(*this))
	{
		position_ = rhs.position_;
		width_ = rhs.width_;
		height_ = rhs.height_;
		color_ = rhs.color_;
	}

	return *this;
}
