#pragma once

#include "game.h"
#include "screens/screen.h"

class GamePlay : public Screen {
   public:
   private:
   public:
	GamePlay(Game *game);
	~GamePlay() = default;

   private:
	bool handleEvents() override;
	bool updateLogics() override;
	void renderFrame() override;
};
