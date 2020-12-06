#include "Menu.h"

Menu::Menu (void):
	text_(new Text(20, 20, "hello world", "app0:/assets/texterius.ttf", 30, GameRenderer::getRenderer()))
{}

Menu::~Menu (void) 
{
	delete text_;
}

Node* Menu::process (void)
{
	Node* nextState = this;
	
	Color blue(0, 0, 255, 255);
	
	GameRenderer::clear();
	GameRenderer::drawRect(50, 50, 100, 100, blue);
	GameRenderer::drawText(*text_);
	GameRenderer::present();

	return nextState;
}
