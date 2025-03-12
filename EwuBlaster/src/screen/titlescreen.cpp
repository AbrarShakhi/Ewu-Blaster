#include "screens/titlescreen.h"


TitleScreen::TitleScreen(Game *game)
    : Screen(game, ScreenType::SPLASH_SCREEN) {}

bool TitleScreen::handleEvents() { return true; }

bool TitleScreen::updateLogics() {
	callbackGame->screenTypeNo = ScreenType::GAMEPLAY;
	return true;
}

void TitleScreen::renderFrame() {}
