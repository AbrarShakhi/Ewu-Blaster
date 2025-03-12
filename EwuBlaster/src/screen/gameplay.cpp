#include "screens/gameplay.h"

GamePlay::GamePlay(Game* game) : Screen(game, ScreenType::SPLASH_SCREEN) {}

bool GamePlay::handleEvents() { return true; }

bool GamePlay::updateLogics() { return true; }

void GamePlay::renderFrame() {}
