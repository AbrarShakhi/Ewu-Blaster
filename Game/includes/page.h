#pragma once

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
	inline Page(EwuBlaster *game, PageType pageName) : pageTypeName(pageName) {
		callbackGame = game;
	}

	inline bool loopFrame(float deltaTime) {
		this->deltaTime = deltaTime;
		bool stat = handleEvents() && updateLogics();
		renderFrame();
		return stat;
	}

   public:
	virtual bool handleEvents() = 0;
	virtual bool updateLogics() = 0;
	virtual void renderFrame() = 0;
};

class SplashScreen : public Page {
   public:
	SplashScreen(EwuBlaster *game);
	~SplashScreen() = default;

   private:
	bool handleEvents() override;
	bool updateLogics() override;
	void renderFrame() override;
};
