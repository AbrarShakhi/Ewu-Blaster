#pragma once

#include <array>

#include "game.h"
#include "objs/buttons.h"
#include "screens/screen.h"


enum BUTTON_NO { PLAY = 0, EXIT };

class TitleScreen : public Screen {
public:
	const static int8_t NUMBER_OF_BUTTONS = 2;

private:
	std::array<Buttons, NUMBER_OF_BUTTONS> btns;
	olc::Sprite bgSprite;
	olc::Decal bgDecal;
	olc::vf2d bgScale;

public:
	TitleScreen(Game* p_game);
	~TitleScreen();

private:
	bool handleEvents() override;
	bool updateLogics() override;
	void renderFrame() override;
};