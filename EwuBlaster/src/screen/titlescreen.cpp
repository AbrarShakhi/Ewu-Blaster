#include "screens/titlescreen.h"


TitleScreen::TitleScreen(Game *p_game) : Screen(p_game, ScreenType::TITLE_SCREEN) {
}

bool TitleScreen::handleEvents() {
	return true;
}

bool TitleScreen::updateLogics() {
	callbackGame->activeScreenType = ScreenType::GAMEPLAY;
	return true;
}

void TitleScreen::renderFrame() {
}
