#pragma once

#include <array>

#include "olcPixelGameEngine.h"
#include "screens/screen.h"


class Game : public olc::PixelGameEngine {
public:
	olc::rcode gameStatus;
	ScreenType activeScreenType;
	std::array<Screen*, NUM_OF_SCREENS> screens;

private:
public:
	Game();
	~Game();

	uint64_t getGameScore() const;

private:
	bool OnUserCreate() override;
	bool OnUserUpdate(float p_delta_time) override;
	bool OnUserDestroy() override;

	void initScreens();
};
