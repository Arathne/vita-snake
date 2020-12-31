#include "Menu.h"

#define SPACING 60
#define CENTER_X 960/2
#define CENTER_Y 544/2

Menu::Menu (void):
	selected_(0),
	title_(Text(CENTER_X, 40, "SNAKE", "app0:/assets/joystix.ttf", 110, GameRenderer::getRenderer()))
{
	title_.moveX(-(title_.getWidth()/2));
	title_.setColor(0, 255, 0, 255);

	options_.push_back(new Selector(CENTER_X, 250, "PLAY", 40, *((Node*) new Game()) ));
	options_.push_back(new Selector(CENTER_X, 250+SPACING, "OPTIONS", 40, *((Node*) this)));
	options_.at(selected_) -> hover();

	std::cout << "STATE :: MENU" << std::endl;
}

Menu::~Menu (void) 
{
	for (auto it = options_.begin(); it != options_.end(); it++)
	{
		delete *it;
	}
}

Node* Menu::process (void)
{
	Node* nextState = this;
	
	Menu::input();

	GameRenderer::clear();
	Menu::draw();
	GameRenderer::present();
	
	if (Input::began(SCE_CTRL_CROSS)) 
	{
		nextState = &options_.at(selected_) -> select();
	}

	return nextState;
}

void Menu::input (void)
{
	if (Input::began(SCE_CTRL_UP) && selected_ > 0) {
		options_.at(selected_) -> unhover();
		selected_--;
		options_.at(selected_) -> hover();
	}
	else if (Input::began(SCE_CTRL_DOWN) && selected_ < options_.size()-1) {
		options_.at(selected_) -> unhover();
		selected_++;
		options_.at(selected_) -> hover();
	}
}

void Menu::draw (void)
{
	title_.draw();
	
	for (auto it = options_.begin(); it != options_.end(); it++)
	{
		(*it) -> draw();
	}
}
