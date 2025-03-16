#include "screens/gameplay.h"

GamePlay::GamePlay(Game* p_game) : Screen(p_game, ScreenType::GAMEPLAY) {
}

bool GamePlay::handleEvents() {
	return true;
}

bool GamePlay::updateLogics() {
	return true;
}

void GamePlay::renderFrame() {
}
