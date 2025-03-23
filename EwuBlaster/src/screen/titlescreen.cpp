#include "screens/titlescreen.h"


TitleScreen::TitleScreen(Game *p_game)
    : Screen(p_game, ScreenType::TITLE_SCREEN),
      btns({("PLAY"), ("EXIT")}),
      bgSprite("Assets/pbgEwu.png"),
      bgDecal(&bgSprite) {

	for (auto &&b : btns) {
		b.fitTextSize(p_game);
	}
	
	olc::vf2d win_size = callbackGame->GetScreenSize();
	olc::vf2d btn_pos = (win_size / 2.0f);
	olc::vf2d offset = {0, 5};
	btns[int(BUTTON_NO::PLAY)].setBottomCenter(btn_pos - offset);
	btns[int(BUTTON_NO::EXIT)].setTopCenter(btn_pos + offset);

	bgScale.x = win_size.x / (bgDecal.sprite->width);
	bgScale.y = win_size.y / (bgDecal.sprite->height);
}

TitleScreen::~TitleScreen() {
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
	callbackGame->DrawDecal({0, 0}, &bgDecal, bgScale);
	for (auto &&b : btns) {
		b.draw(callbackGame);
	}
}
