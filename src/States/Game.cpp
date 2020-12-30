#include "Game.h"

Game::Game (void):
	collision_(Collision(food_, snake_))
{
	std::cout << "STATE :: GAME" << std::endl;
}

Game::~Game (void) {}

Node* Game::process (void) 
{
	Game::input();
	snake_.update();

	GameRenderer::clear();
	food_.draw();
	snake_.draw();
	GameRenderer::present();
	
	collision_.check();

	return this;
}

void Game::input (void)
{	
	if (Input::began(SCE_CTRL_UP))
		snake_.direction(UP);
	else if (Input::began(SCE_CTRL_DOWN))
		snake_.direction(DOWN);
	else if (Input::began(SCE_CTRL_LEFT))
		snake_.direction(LEFT);
	else if (Input::began(SCE_CTRL_RIGHT))
		snake_.direction(RIGHT);
}
