#pragma once

#include "game.h"
#include "objs/entity.h"
#include "objs/player.h"
#include "screens/screen.h"

class GamePlay : public Screen {
public:
private:
	Player player;
	bool isGameOver = false;
	bool isGamePaused = false;
	bool isGameWon = false;
	bool isGameStarted = false;
	uint64_t gameScore;


public:
	GamePlay(Game *p_game);
	~GamePlay() = default;

	uint64_t getGameScore() const;

private:
	bool handleEvents() override;
	bool updateLogics() override;
	void renderFrame() override;
};
