#include "Menu.h"

#define SPACING 50

Menu::Menu (void):
	selected_(0),
	title_(Text("SNAKE", "app0:/assets/joystix.ttf", 100, GameRenderer::getRenderer())),
	play_(Text("PLAY", "app0:/assets/joystix.ttf", 30, GameRenderer::getRenderer())),
	options_(Text("OPTIONS", "app0:/assets/joystix.ttf", 30, GameRenderer::getRenderer())),
	highscores_(Text("HIGHSCORES", "app0:/assets/joystix.ttf", 30, GameRenderer::getRenderer()))
{
	title_.setPosition( (960/2)-(title_.getWidth()/2), SPACING );
	play_.setPosition( (960/2)-(play_.getWidth()/2), title_.getPositionY() + title_.getHeight() + SPACING );
	options_.setPosition( (960/2)-(options_.getWidth()/2), play_.getPositionY() + play_.getHeight() + SPACING );
	highscores_.setPosition( (960/2)-(highscores_.getWidth()/2), options_.getPositionY() + options_.getHeight() + SPACING );
	
	Log::add("STATE :: MENU");
}

Menu::~Menu (void) {}

Node* Menu::process (void)
{
	Node* nextState = this;
	
	Menu::input();

	GameRenderer::clear();
	
	title_.draw();
	Menu::drawOptions();
	Log::draw();

	GameRenderer::present();
	
	if (Input::began(SCE_CTRL_CROSS)) 
	{
		if (selected_ == 0)
			nextState = new Game();
	}

	return nextState;
}

void Menu::input (void)
{
	if (Input::began(SCE_CTRL_UP) && selected_ > 0)
		selected_--;
	else if (Input::began(SCE_CTRL_DOWN) && selected_ < 2)
		selected_++;
}

void Menu::drawOptions (void)
{
	play_.setColor(255, 255, 255, 255);
	options_.setColor(255, 255, 255, 255);
	highscores_.setColor(255, 255, 255, 255);
	
	if (selected_ == 0)
		play_.setColor(255, 0, 0, 255);
	else if (selected_ == 1)
		options_.setColor(255, 0, 0, 255);
	else if (selected_ == 2)
		highscores_.setColor(255, 0, 0, 255);
	
	play_.draw();
	options_.draw();
	highscores_.draw();
}
