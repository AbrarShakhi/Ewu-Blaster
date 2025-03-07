#include "ewublaster.h"
#include "page.h"

SplashScreen::SplashScreen(EwuBlaster *game)
    : Page(game, PageType::SPLASH_SCREEN) {}

bool SplashScreen::handleEvents() { return true; }

bool SplashScreen::updateLogics() { return true; }

void SplashScreen::renderFrame() {
	this->callbackGame->DrawString({1, 1}, "EWU BLASTER");
}
