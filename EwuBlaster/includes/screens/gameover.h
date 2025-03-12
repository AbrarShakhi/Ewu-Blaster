#pragma once

#include "game.h"
#include "screens/screen.h"

class GameOver : public Screen {
public:
private:
	std::string scoreText;
	olc::vf2d scoreTextPos;
	olc::vf2d scoreTextScale;

	std::string scoreInfoText;
	olc::vf2d scoreInfoTextPos;

	std::string titleText;
	olc::vf2d titleTextPos;
	olc::vf2d titleTextScale;

	std::string pressKeyText;
	olc::vf2d pressKeyTextPos;

public:
	GameOver(Game *p_game);
	~GameOver() = default;

private:
	bool handleEvents() override;
	bool updateLogics() override;
	void renderFrame() override;
};