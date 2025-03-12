#pragma once

#include <functional>

#include "olcPixelGameEngine.h"
#include "screens/screen.h"


class Game : public olc::PixelGameEngine {
   public:
	olc::rcode gameStatus;
	ScreenType screenTypeNo;
	std::array<Screen*, NUM_OF_SCREENS> screens;

   private:
	uint64_t gameScore;

   public:
	Game();
	~Game();

	inline uint64_t getGameScore() { return gameScore; }

   private:
	bool OnUserCreate() override;
	bool OnUserUpdate(float deltaTime) override;
	bool OnUserDestroy() override;

	void initScreens();

	inline void setGameScore(uint64_t score) { gameScore = score; }
};
