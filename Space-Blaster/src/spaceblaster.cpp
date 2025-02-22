#include "spaceblaster.h"

#include <stdio.h>
#include <stdlib.h>

#include <ctime>
#include <random>

SpaceBlaster::SpaceBlaster() {
	sAppName = "Space Blaster";

	srand(time(nullptr));
}
SpaceBlaster::~SpaceBlaster() {
	for (size_t i = 0; i < bgStars.size(); i++) {
		delete bgStars[i];
	}
	delete playerShipSprite;
	delete playerShip;
}

bool SpaceBlaster::OnUserCreate() {
	playerShipSprite = new olc::Sprite("Space-Blaster/res/ship.png");
	playerShip = new olc::Decal(playerShipSprite);

	for (size_t i = 0; i < bgStars.size(); i++) {
		bgStars[i] = new olc::vi2d(rand() % GetScreenSize().x,
		                           rand() % GetScreenSize().y);
	}

	playerPos =
	    new olc::vf2d(GetScreenSize().x / 2.0f, GetScreenSize().y / 2.0f);
	return true;
}

bool SpaceBlaster::HandleUserEvent() {
	if (GetKey(olc::RIGHT).bHeld) {
		if (playerPos->x <= GetScreenSize().x) {
			playerPos->x = playerPos->x + 0.03f;
		}
	}
	if (GetKey(olc::LEFT).bHeld) {
		if (playerPos->x >= 0) {
			playerPos->x = playerPos->x - 0.03f;
		}
	}
	if (GetKey(olc::UP).bHeld) {
		if (playerPos->y >= 0) {
			playerPos->y = playerPos->y - 0.03f;
		}
	}
	if (GetKey(olc::DOWN).bHeld) {
		if (playerPos->y <= GetScreenSize().y) {
			playerPos->y = playerPos->y + 0.03f;
		}
	}
	return true;
}


bool SpaceBlaster::OnUserUpdate(float fElapsedTime) {
	if (!HandleUserEvent()) {
		return false;
	}

	Clear(olc::BLACK);
	for (size_t i = 0; i < bgStars.size(); i++) {
		Draw(*bgStars[i], olc::WHITE);
	}


	olc::vf2d scale({.2F, .2F});
	DrawDecal(*playerPos, playerShip, scale);

	return true;
}