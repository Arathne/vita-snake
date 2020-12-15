#include "Game.h"

Game::Game (void)
{
	Log::add("STATE :: GAME");
}

Game::~Game (void) {}

Node* Game::process (void) 
{
	GameRenderer::clear();
	
	snake_.draw();
	Log::draw();

	GameRenderer::present();
	
	Game::input();

	return this;
}

void Game::input (void)
{	
	if (Input::active(SCE_CTRL_UP))
		snake_.update(UP);
	else if (Input::active(SCE_CTRL_DOWN))
		snake_.update(DOWN);
	else if (Input::active(SCE_CTRL_LEFT))
		snake_.update(LEFT);
	else if (Input::active(SCE_CTRL_RIGHT))
		snake_.update(RIGHT);
}
