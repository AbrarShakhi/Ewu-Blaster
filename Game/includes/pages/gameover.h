#pragma once

#include "ewublaster.h"
#include "pages/page.h"

class GameOver : public Page {
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
	GameOver(EwuBlaster *game);
	~GameOver() = default;

   private:
	bool handleEvents() override;
	bool updateLogics() override;
	void renderFrame() override;
};