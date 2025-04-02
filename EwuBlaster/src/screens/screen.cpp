
#include "screens/screen.h"

#include "game.h"


Screen::Screen(Game *p_game, ScreenType p_screen_type) : screenType(p_screen_type) {
	callbackGame = p_game;
}

bool Screen::loopFrame(float p_delta_time) {
	this->deltaTime = p_delta_time;

	callbackGame->Clear(olc::BLACK);

	bool stat = handleEvents() && updateLogics();
	renderFrame();
	return stat;
}
