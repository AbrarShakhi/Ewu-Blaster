#pragma once

#include <cstdint>

class Game;

const static inline int8_t NUM_OF_SCREENS = 5;

enum class ScreenType { SPLASH_SCREEN, TITLE_SCREEN, GAMEPLAY, GAMEOVER, SETTINGS };

class Screen {
public:
	const ScreenType screenType;

protected:
	float deltaTime = 1;
	Game *callbackGame = nullptr;

public:
	Screen(Game *p_game, ScreenType p_screen_type);

	bool loopFrame(float p_delta_time);

public:
	virtual bool handleEvents() = 0;
	virtual bool updateLogics() = 0;
	virtual void renderFrame() = 0;
};
