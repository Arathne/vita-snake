#include "Game.h"

Game::Game (void)
{
	Log::add("STATE :: GAME");
}

Game::~Game (void) {}

Node* Game::process (void) 
{
	GameRenderer::clear();
	
	Log::draw();

	GameRenderer::present();
	
	return nullptr;
}
