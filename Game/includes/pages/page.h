#pragma once

#include <cstdint>

class EwuBlaster;

const static inline int8_t NUM_OF_PAGES = 5;

enum class PageType {
	SPLASH_SCREEN,
	TITLE_SCREEN,
	GAMEPLAY,
	GAMEOVER,
	SETTINGS
};

class Page {
   public:
	const PageType pageTypeName;

   protected:
	float deltaTime = 1;
	EwuBlaster *callbackGame = nullptr;

   public:
	Page(EwuBlaster *game, PageType pageName);

	bool loopFrame(float deltaTime);

   public:
	virtual bool handleEvents() = 0;
	virtual bool updateLogics() = 0;
	virtual void renderFrame() = 0;
};
