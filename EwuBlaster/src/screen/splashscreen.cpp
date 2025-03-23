#include "screens/splashscreen.h"


SplashScreen::SplashScreen(Game *p_game) : Screen(p_game, ScreenType::SPLASH_SCREEN) {
	text = "ABRAR STUDIO";

	olc::vf2d win_size = callbackGame->GetScreenSize();
	olc::vf2d text_size = callbackGame->GetTextSize(text);

	pos = win_size / 2.0f - (text_size / 2.0f);

	col = {255U, 0U, 0U, 0U};
	alphaChannel = 0.0f;
	greenChannel = 255.0f;
	blueChannel = 255.0f;
}

bool SplashScreen::handleEvents() {
	return true;
}

bool SplashScreen::updateLogics() {
	greenChannel -= 40 * deltaTime;
	col.g = (int(greenChannel) > 0) ? int(greenChannel) : 0U;

	blueChannel -= 40 * deltaTime;
	col.b = (int(blueChannel) > 0) ? int(blueChannel) : 0U;

	alphaChannel += 50 * deltaTime;
	if (int(alphaChannel) < 256) {
		col.a = uint8_t(int(alphaChannel));
		t.reset();
	} else {
		col.a = 255U;
		if (t.elapsed() >= 1) {
			callbackGame->activeScreenType = ScreenType::TITLE_SCREEN;
		}
	}

	return true;
}

void SplashScreen::renderFrame() {
	callbackGame->DrawStringDecal(pos, text, col);
}
