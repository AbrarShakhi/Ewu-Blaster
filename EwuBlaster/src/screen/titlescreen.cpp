#include "screens/titlescreen.h"


TitleScreen::TitleScreen(Game *p_game) : Screen(p_game, ScreenType::TITLE_SCREEN), btns({("PLAY"), ("EXIT")}) {
	for (auto &&b : btns) {
		b.fitTextSize(p_game);
	}
	olc::vf2d win_size = callbackGame->GetScreenSize();
	olc::vf2d btn_center = (win_size / 2.0f);
	olc::vf2d offset = {0, 4};
	btns[int(BUTTON_NO::PLAY)].setBottomCenter(btn_center - offset);
	btns[int(BUTTON_NO::EXIT)].setTopCenter(btn_center + offset);
}

bool TitleScreen::handleEvents() {
	for (auto &&b : btns) {
		b.handle(callbackGame);
	}
	return true;
}

bool TitleScreen::updateLogics() {
	if (btns[int(BUTTON_NO::PLAY)].isSelected()) {
		callbackGame->activeScreenType = ScreenType::GAMEPLAY;
	} else if (btns[int(BUTTON_NO::EXIT)].isSelected()) {
		return false;
	}
	return true;
}

void TitleScreen::renderFrame() {
	for (auto &&b : btns) {
		b.draw(callbackGame);
	}
}
