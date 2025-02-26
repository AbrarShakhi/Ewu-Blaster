#include "spaceblaster.h"

#include <cstdlib>
#include <ctime>
#include <random>

SpaceBlaster::SpaceBlaster() {
	sAppName = "Space Blaster";

	srand(time(nullptr));
}

bool SpaceBlaster::OnUserCreate() {
	enemiesRate = 0;
	fireRate = 0;

	for (size_t i = 0; i < bgStars.size(); i++) {
		bgStars[i] = new olc::vi2d(rand() % GetScreenSize().x,
		                           rand() % GetScreenSize().y);
	}

	player = new Entity("Space-Blaster/res/ship.png");
	player->scale = {0.2, 0.2};
	player->valocity = {0, 0};

	float X, Y;
	X = (GetScreenSize().x / 2.0f) - (player->getWidth() / 2.0f);
	Y = (GetScreenSize().y) - (player->getHeight() + 10);

	player->position = {X, Y};

	return true;
}
bool SpaceBlaster::OnUserDestroy() {
	for (size_t i = 0; i < bgStars.size(); i++) {
		delete bgStars[i];
	}
	if (player) {
		delete player;
	}
	return true;
}


bool SpaceBlaster::OnUserUpdate(float deltaTime) {
	if (!HandleUserEvent(deltaTime)) {
		return false;
	}
	if (!UpdateGameLogic(deltaTime)) {
		return false;
	}

	RenderScreen();
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

bool SpaceBlaster::UpdateGameLogic(float deltaTime) {
	enemiesRate += 10 * deltaTime;
	if (enemiesRate > 10 || enemiesRate <= 0) {
		auto astero = new Entity("Space-Blaster/res/asteroid1.png");
		astero->position = {
		    float(rand() % (GetScreenSize().x - int(astero->getHeight()))),
		    -astero->getHeight()};
		astero->scale = {0.2, 0.2};
		astero->valocity = {0, 25};
		enemies.emplace_back(astero);
		enemiesRate = 0;
	}

	fireRate += 25 * deltaTime;
	if (fireRate > 10 || fireRate <= 0) {
		auto bullet = new Entity("Space-Blaster/res/asteroid1.png");
		bullet->position = {float(player->position.x),
		                    float(player->position.y)};
		bullet->scale = {0.05, 0.05};
		bullet->valocity = {0, 50};
		enemies.emplace_back(bullet);
		fireRate = 0;
	}

	while (!enemies.empty() &&
	       enemies.front()->position.y > GetScreenSize().y) {
		auto astero = enemies.front();
		enemies.pop_front();
		delete astero;
	}

	while (!bullets.empty() &&
	       bullets.front()->position.y + bullets.front()->getHeight() <= 0) {
		auto b = bullets.front();
		bullets.pop_front();
		delete b;
	}

	for (auto enemy : enemies) {
		if (player->collidesWith(*enemy)) {
			return false;
		}
		enemy->position.x += enemy->valocity.x * deltaTime;
		enemy->position.y += enemy->valocity.y * deltaTime;
	}

	return true;
}

void SpaceBlaster::RenderScreen() {
	Clear(olc::BLACK);
	for (size_t i = 0; i < bgStars.size(); i++) {
		Draw(*bgStars[i], olc::WHITE);
	}

	for (auto enemy : enemies) {
		enemy->draw(this);
	}
	player->draw(this);
}
