#include "Game.h"

Game::Game (void)
{
	Log::add("STATE :: GAME");
}

Game::~Game (void) {}

Node* Game::process (void) 
{
	Game::input();
	snake_.update();

	GameRenderer::clear();
	snake_.draw();
	Log::draw();
	GameRenderer::present();
	
	return this;
}

void Game::input (void)
{	
	if (Input::active(SCE_CTRL_UP))
		snake_.direction(UP);
	else if (Input::active(SCE_CTRL_DOWN))
		snake_.direction(DOWN);
	else if (Input::active(SCE_CTRL_LEFT))
		snake_.direction(LEFT);
	else if (Input::active(SCE_CTRL_RIGHT))
		snake_.direction(RIGHT);
}
