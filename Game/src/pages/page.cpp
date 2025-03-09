
#include "pages/page.h"

#include "ewublaster.h"


Page::Page(EwuBlaster *game, PageType pageName) : pageTypeName(pageName) {
	callbackGame = game;
}

bool Page::loopFrame(float deltaTime) {
	this->deltaTime = deltaTime;

	callbackGame->Clear(olc::BLACK);

	bool stat = handleEvents() && updateLogics();
	renderFrame();
	return stat;
}
