#include "game.h"

#include "screens/gameover.h"
#include "screens/gameplay.h"
#include "screens/screen.h"
#include "screens/splashscreen.h"
#include "screens/titlescreen.h"
#include "utils/helper.h"

Game::Game() : gameStatus(olc::OK), activeScreenType(ScreenType::SPLASH_SCREEN) {
	olc::vi2d size = getMonitorSize();

	initScreens();

	gameScore = 0;
	sAppName = "Ewu Blaster";
	gameStatus = Construct(size.x, size.y, 4, 4, false, true);
}

Game::~Game() {
	for (const auto &sc : screens) {
		delete sc;
	}
}

void Game::initScreens() {
	screens[int(ScreenType::SPLASH_SCREEN)] = new SplashScreen(this);
	screens[int(ScreenType::TITLE_SCREEN)] = new TitleScreen(this);
	screens[int(ScreenType::GAMEPLAY)] = new GamePlay(this);
	screens[int(ScreenType::GAMEOVER)] = new GameOver(this);
	screens[int(ScreenType::SETTINGS)] = nullptr;
}

bool Game::OnUserCreate() {
	return true;
}
bool Game::OnUserDestroy() {
	return true;
}

bool Game::OnUserUpdate(float p_delta_time) {
	if (screens[int(activeScreenType)]) {
		return screens[int(activeScreenType)]->loopFrame(p_delta_time);
	}
	return false;
}
