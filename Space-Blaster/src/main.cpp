#include "spaceblaster.h"

class SpaceBlaster : public olc::PixelGameEngine {
   public:
	SpaceBlaster() { sAppName = "Space Blaster"; }

   public:
	bool OnUserCreate() override {
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
		// called once per frame
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y,
				     olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
		return true;
	}
};


int main() {
	SpaceBlaster game;
	if (game.Construct(256, 240, 4, 4))
		game.Start();

	return 0;
}