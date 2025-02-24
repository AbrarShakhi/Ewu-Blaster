#include "spaceblaster.h"

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
	if (player)
		delete player;
}

bool SpaceBlaster::OnUserCreate() {
	for (size_t i = 0; i < bgStars.size(); i++) {
		bgStars[i] = new olc::vi2d(rand() % GetScreenSize().x,
		                           rand() % GetScreenSize().y);
	}

	player = new Entity("Space-Blaster/res/ship.png");
	player->scale = {0.2, 0.2};

	float X, Y;
	X = (GetScreenSize().x / 2.0f) - (player->getWidth() / 2.0f);
	Y = (GetScreenSize().y) - (player->getHeight() + 10);

	player->position = {X, Y};

	return true;
}

bool SpaceBlaster::HandleUserEvent(float deltaTime) {
	if (GetKey(olc::RIGHT).bHeld || GetKey(olc::D).bHeld) {
		if (player->position.x < GetScreenSize().x - player->getWidth()) {
			player->position.x += (200 * deltaTime);
		}
	}
	if (GetKey(olc::LEFT).bHeld || GetKey(olc::A).bHeld) {
		if (player->position.x > 0) {
			player->position.x -= (200 * deltaTime);
		}
	}
	if (GetKey(olc::UP).bHeld || GetKey(olc::W).bHeld) {
		if (player->position.y > 0) {
			player->position.y -= (200 * deltaTime);
		}
	}
	if (GetKey(olc::DOWN).bHeld || GetKey(olc::S).bHeld) {
		if (player->position.y < GetScreenSize().y - player->getHeight()) {
			player->position.y += (200 * deltaTime);
		}
	}
	return true;
}


bool SpaceBlaster::OnUserUpdate(float deltaTime) {
	if (!HandleUserEvent(deltaTime)) {
		return false;
	}

	Clear(olc::BLACK);
	for (size_t i = 0; i < bgStars.size(); i++) {
		Draw(*bgStars[i], olc::WHITE);
	}

	player->draw(this);
	return true;
}