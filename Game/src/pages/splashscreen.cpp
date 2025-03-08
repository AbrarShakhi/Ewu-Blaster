#include "pages/splashscreen.h"


SplashScreen::SplashScreen(EwuBlaster *game)
    : Page(game, PageType::SPLASH_SCREEN) {
	text = "EWU BLASTER";
	pos = {0, 0};
	col = {255U, 255U, 255U, 0U};
	alphaChannel = 0;
	displaytime = 3;
}

bool SplashScreen::handleEvents() { return true; }

bool SplashScreen::updateLogics() {
	alphaChannel += 50 * deltaTime;
	if (int(alphaChannel) < 256) {
		col.a = uint8_t(int(alphaChannel));
	} else {
		col.a = 255U;
		displaytime -= deltaTime;
	}

	if (displaytime < 1)
		return false;
	return true;
}

void SplashScreen::renderFrame() { callbackGame->DrawString(pos, text, col); }
