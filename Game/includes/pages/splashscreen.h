#include "ewublaster.h"
#include "pages/page.h"

class SplashScreen : public Page {
   public:
   private:
	std::string text;
	olc::vf2d pos;
	olc::Pixel col;
	float alphaChannel;
	float displaytime;

   public:
	SplashScreen(EwuBlaster *game);
	~SplashScreen() = default;

   private:
	bool handleEvents() override;
	bool updateLogics() override;
	void renderFrame() override;
};
