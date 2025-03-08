#include "ewublaster.h"

#include "pages/page.h"
#include "pages/splashscreen.h"
#include "utils/helper.h"

EwuBlaster::EwuBlaster()
    : gameStatus(olc::OK), pageTypeNo(PageType::SPLASH_SCREEN) {
	olc::vi2d size = getMonitorSize();

	initPages();

	sAppName = "Ewu Blaster";
	gameStatus = Construct(size.x, size.y, 4, 4, false, true);
}

EwuBlaster::~EwuBlaster() {
	for (const auto &pg : pages) {
		delete pg;
	}
}

void EwuBlaster::initPages() {
	pages[int(PageType::SPLASH_SCREEN)] = new SplashScreen(this);
	pages[int(PageType::TITLE_SCREEN)] = nullptr;
	pages[int(PageType::GAMEPLAY)] = nullptr;
	pages[int(PageType::GAMEOVER)] = nullptr;
	pages[int(PageType::SETTINGS)] = nullptr;
}

bool EwuBlaster::OnUserCreate() { return true; }
bool EwuBlaster::OnUserDestroy() { return true; }

bool EwuBlaster::OnUserUpdate(float deltaTime) {
	if (pages[int(pageTypeNo)]) {
		return pages[int(pageTypeNo)]->loopFrame(deltaTime);
	}
	return false;
}
