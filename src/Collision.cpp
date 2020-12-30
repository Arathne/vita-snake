#include "Collision.h"

Collision::Collision (Food & food, Snake & snake):
	food_(&food),
	snake_(&snake)
{}

Collision::Collision (void) {}

Collision::~Collision (void) {}

void Collision::check (void)
{
	bool foodEaten = false;

	while ( snake_->collided( food_->getRectangle() )) 
	{
		food_-> respawn();
		foodEaten = true;
	}

	if (foodEaten)
	{
		snake_ -> grow();
	}		
}
