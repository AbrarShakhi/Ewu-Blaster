#include "screens/gameplay.h"

GamePlay::GamePlay(Game* p_game) : Screen(p_game, ScreenType::SPLASH_SCREEN) {
}

bool GamePlay::handleEvents() {
	return true;
}

bool GamePlay::updateLogics() {
	return true;
}

void GamePlay::renderFrame() {
}
