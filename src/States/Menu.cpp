#include "Menu.h"

#define SPACING 50
#define STARTX ((960/2)-(title_.getWidth()/2)

Menu::Menu (void):
	title_(Text("SNAKE", "app0:/assets/joystix.ttf", 100, GameRenderer::getRenderer())),
	play_(Text("PLAY", "app0:/assets/joystix.ttf", 30, GameRenderer::getRenderer())),
	options_(Text("OPTIONS", "app0:/assets/joystix.ttf", 30, GameRenderer::getRenderer())),
	highscores_(Text("HIGHSCORES", "app0:/assets/joystix.ttf", 30, GameRenderer::getRenderer()))
{
	title_.setPosition( (960/2)-(title_.getWidth()/2), SPACING );
	play_.setPosition( (960/2)-(play_.getWidth()/2), title_.getPositionY() + title_.getHeight() + SPACING );
	options_.setPosition( (960/2)-(options_.getWidth()/2), play_.getPositionY() + play_.getHeight() + SPACING );
	highscores_.setPosition( (960/2)-(highscores_.getWidth()/2), options_.getPositionY() + options_.getHeight() + SPACING );
	
	play_.setColor(255, 0, 0, 255);

	Log::add("state :: menu");
}

Menu::~Menu (void) {}

Node* Menu::process (void)
{
	Node* nextState = this;
	
	Menu::input();

	GameRenderer::clear();
	
	title_.draw();
	play_.draw();
	options_.draw();
	highscores_.draw();
	Log::draw();

	GameRenderer::present();

	return nextState;
}

void Menu::input (void)
{
	
}
