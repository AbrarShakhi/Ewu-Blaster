#pragma once

#include <functional>

#include "olcPixelGameEngine.h"
#include "pages/page.h"

class EwuBlaster : public olc::PixelGameEngine {
   public:
	olc::rcode gameStatus;
	PageType pageTypeNo;
	std::array<Page*, NUM_OF_PAGES> pages;

   public:
	EwuBlaster();
	~EwuBlaster();

   private:
	bool OnUserCreate() override;
	bool OnUserUpdate(float deltaTime) override;
	bool OnUserDestroy() override;

	void initPages();
};
