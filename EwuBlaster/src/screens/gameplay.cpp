#include "screens/gameplay.h"

#include "game.h"

GamePlay::GamePlay(Game* p_game) : Screen(p_game, ScreenType::GAMEPLAY), player("Assets/player/1.png", {0, 0}) {
	gameScore = 0;
	isGameOver = false;
	isGamePaused = false;
	isGameWon = false;
	isGameStarted = false;
	player.setCenter({p_game->ScreenWidth() / 2.0f, p_game->ScreenHeight() / 2.0f});
	// player.setScalingLockCenter({})
	player.setEntityState(Entity::ALIVE);
}

bool GamePlay::handleEvents() {
	return true;
}

bool GamePlay::updateLogics() {
	player.move(deltaTime, callbackGame);
	return true;
}

void GamePlay::renderFrame() {
	player.draw(callbackGame);
}

uint64_t GamePlay::getGameScore() const {
	return gameScore;
}