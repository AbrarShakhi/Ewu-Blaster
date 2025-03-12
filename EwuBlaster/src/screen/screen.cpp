
#include "screens/screen.h"

#include "game.h"


Screen::Screen(Game *game, ScreenType screenType) : screenTypeName(screenType) {
	callbackGame = game;
}

bool Screen::loopFrame(float deltaTime) {
	this->deltaTime = deltaTime;

	callbackGame->Clear(olc::BLACK);

	bool stat = handleEvents() && updateLogics();
	renderFrame();
	return stat;
}
