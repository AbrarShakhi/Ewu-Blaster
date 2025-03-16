
#include "screens/gameover.h"

#include <sstream>

GameOver::GameOver(Game *p_game) : Screen(p_game, ScreenType::GAMEOVER) {
	titleText = "Game Over";
	scoreInfoText = "Your Score";
	pressKeyText = "Press Any Key";
}

bool GameOver::handleEvents() {
	if (callbackGame->GetKey(olc::ENTER).bPressed) {
		return false;
	}
	return true;
}

bool GameOver::updateLogics() {
	std::stringstream s;
	s << callbackGame->getGameScore();
	scoreText = s.str();

	scoreTextScale = {2, 2};
	olc::vf2d screen_size = callbackGame->GetScreenSize();
	olc::vf2d text_size = callbackGame->GetTextSize(scoreText) * scoreTextScale;

	scoreTextPos = screen_size / 2.0f - (text_size / 2.0f);

	return true;
}

void GameOver::renderFrame() {
	// callbackGame->DrawStringDecal(titleTextPos, titleText, olc::RED,
	//                               titleTextScale);
	// callbackGame->DrawStringDecal(scoreInfoTextPos, scoreInfoText,
	// olc::WHITE);
	callbackGame->DrawStringDecal(scoreTextPos, scoreText, olc::WHITE, scoreTextScale);
	// callbackGame->DrawStringDecal(pressKeyTextPos, pressKeyText, olc::WHITE);
}
