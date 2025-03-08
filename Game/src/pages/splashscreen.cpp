#include "pages/splashscreen.h"


SplashScreen::SplashScreen(EwuBlaster *game)
    : Page(game, PageType::SPLASH_SCREEN) {
	text = "EWU BLASTER";

	olc::vf2d screen_size = callbackGame->GetScreenSize();
	olc::vf2d text_size = callbackGame->GetTextSize(text);

	pos = screen_size / 2.0f - (text_size / 2.0f);

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

void SplashScreen::renderFrame() {
	callbackGame->DrawStringDecal(pos, text, col);
}
