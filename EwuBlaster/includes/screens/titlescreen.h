#pragma once

#include "game.h"
#include "screens/screen.h"

class TitleScreen : public Screen {
   public:
   private:
   public:
	TitleScreen(Game *game);
	~TitleScreen() = default;

   private:
	bool handleEvents() override;
	bool updateLogics() override;
	void renderFrame() override;
};