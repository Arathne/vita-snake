#include "Menu.h"

Menu::Menu (void) {}

Menu::~Menu (void) {}

Node* Menu::process (void)
{
	Node* nextState = this;
	
	GameRenderer::clear();
	GameRenderer::drawRect(50, 50, 100, 100);
	GameRenderer::present();

	return nextState;
}
