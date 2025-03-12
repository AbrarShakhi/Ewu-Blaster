#include "game.h"
#include "screens/screen.h"

class SplashScreen : public Screen {
   public:
   private:
	std::string text;
	olc::vf2d pos;
	olc::Pixel col;
	float alphaChannel;
	float displaytime;

   public:
	SplashScreen(Game *game);
	~SplashScreen() = default;

   private:
	bool handleEvents() override;
	bool updateLogics() override;
	void renderFrame() override;
};
