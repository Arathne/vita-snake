#include "vector.h"

#define DEFAULT 0

Vector2d::Vector2d (void):
	x (DEFAULT),
	y (DEFAULT)
{}

Vector2d::Vector2d (int newX, int newY): 
	x (newX),
	y (newY)
{}

Vector2d::Vector2d (const Vector2d & rhs):
	x (rhs.x),
	y (rhs.y)
{}

Vector2d::~Vector2d (void) {}


const Vector2d & Vector2d::operator = (const Vector2d & rhs)
{
	if ( &rhs != &(*this) )
	{
		x = rhs.x;
		y = rhs.y;
	}

	return *this;
}

const Vector2d & Vector2d::operator + (const Vector2d & rhs)
{
	x += rhs.x;
	y += rhs.y;

	return *this;
}

const Vector2d & Vector2d::operator - (const Vector2d & rhs)
{
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

const Vector2d & Vector2d::operator += (const Vector2d & rhs)
{
	return *this + rhs;
}

const Vector2d & Vector2d::operator -= (const Vector2d & rhs)
{
	return *this - rhs;
}

const Vector2d & Vector2d::operator * (const int & rhs)
{
	x *= rhs;
	y *= rhs;

	return *this;
}

const Vector2d & Vector2d::operator *= (const int & rhs)
{
	return *this * rhs;
}
