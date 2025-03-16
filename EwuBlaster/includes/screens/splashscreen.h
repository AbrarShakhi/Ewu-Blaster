#include "game.h"
#include "screens/screen.h"
#include "utils/timer.h"

class SplashScreen : public Screen {
public:
private:
	std::string text;
	olc::vf2d pos;
	olc::Pixel col;
	float alphaChannel;
	Timer t;


public:
	SplashScreen(Game* p_game);
	~SplashScreen() = default;

private:
	bool handleEvents() override;
	bool updateLogics() override;
	void renderFrame() override;
};
