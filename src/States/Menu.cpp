#include "Menu.h"

#define SPACING 50

Menu::Menu (void):
	title_(Text("SNAKE", "app0:/assets/joystix.ttf", 100, GameRenderer::getRenderer())),
	play_(Text("PLAY", "app0:/assets/joystix.ttf", 30, GameRenderer::getRenderer())),
	options_(Text("OPTIONS", "app0:/assets/joystix.ttf", 30, GameRenderer::getRenderer())),
	highscores_(Text("HIGHSCORES", "app0:/assets/joystix.ttf", 30, GameRenderer::getRenderer()))
{
	title_.setPosition( (960/2)-(title_.getWidth()/2), SPACING );
	
	Menu::spacing(play_, title_);
	Menu::spacing(options_, play_);
	Menu::spacing(highscores_, options_);
}

Menu::~Menu (void) {}

Node* Menu::process (void)
{
	Node* nextState = this;
	
	Color blue(0, 0, 255, 255);
	
	GameRenderer::clear();
	
	GameRenderer::drawText(title_);
	GameRenderer::drawText(play_);
	GameRenderer::drawText(options_);
	GameRenderer::drawText(highscores_);

	GameRenderer::present();

	return nextState;
}

void Menu::spacing (Text & current, Text & previous)
{
	current.setPosition( (960/2)-(current.getWidth()/2), previous.getPositionY() + previous.getHeight() + SPACING );
}
