#pragma once

#include <cstdint>

class Game;

const static inline int8_t NUM_OF_SCREENS = 5;

enum class ScreenType {
	SPLASH_SCREEN,
	TITLE_SCREEN,
	GAMEPLAY,
	GAMEOVER,
	SETTINGS
};

class Screen {
   public:
	const ScreenType screenTypeName;

   protected:
	float deltaTime = 1;
	Game *callbackGame = nullptr;

   public:
	Screen(Game *game, ScreenType screenName);

	bool loopFrame(float deltaTime);

   public:
	virtual bool handleEvents() = 0;
	virtual bool updateLogics() = 0;
	virtual void renderFrame() = 0;
};
