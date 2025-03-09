#pragma once

#include <functional>

#include "olcPixelGameEngine.h"
#include "pages/page.h"

class EwuBlaster : public olc::PixelGameEngine {
   public:
	olc::rcode gameStatus;
	PageType pageTypeNo;
	std::array<Page*, NUM_OF_PAGES> pages;

   private:
	uint64_t gameScore;

   public:
	EwuBlaster();
	~EwuBlaster();

	inline uint64_t getGameScore() { return gameScore; }

   private:
	bool OnUserCreate() override;
	bool OnUserUpdate(float deltaTime) override;
	bool OnUserDestroy() override;

	void initPages();

	inline void setGameScore(uint64_t score) { gameScore = score; }
};
