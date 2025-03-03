#include "spaceblaster.h"

#include "random.h"

SpaceBlaster::SpaceBlaster() {
	sAppName = "Ewu Blaster";
	score = 0;
}

bool SpaceBlaster::OnUserCreate() {
	enemiesRate = 0;
	fireRate = 0;

	for (size_t i = 0; i < bgStars.size(); i++) {
		bgStars[i] = new olc::vi2d(randfloat(0, GetScreenSize().x),
		                           randint(0, GetScreenSize().y));
	}

	player = new Entity("Game/res/ship.png");
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
	std::cout << "Score is: " << score << '\n';
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
	enemiesRate += 50 * deltaTime;
	if (enemiesRate > 10 || enemiesRate <= 0) {
		Entity* astero = new Entity("Game/res/asteroid1.png");
		astero->scale = {0.2, 0.2};
		astero->valocity = {0, 25};
		astero->position = {
		    randfloat(0, (GetScreenSize().x - astero->getHeight())),
		    -astero->getHeight()};
		enemies.emplace_back(astero);
		enemiesRate = 0;
	}

	while (!enemies.empty() &&
	       enemies.front()->position.y > GetScreenSize().y) {
		Entity* astero = enemies.front();
		enemies.pop_front();
		delete astero;
	}

	for (const auto& enemy : enemies) {
		if (enemy->visiable && enemy->collidesWith(*player)) {
			return false;
		}
		enemy->moveByValocity(deltaTime);
	}

	fireRate += 50 * deltaTime;
	if (fireRate > 10 || fireRate <= 0) {
		Entity* bullet = new Entity("Game/res/asteroid1.png");
		bullet->scale = {0.03, 0.03};
		bullet->valocity = {0, -200};

		bullet->position = {player->position.x + (player->getWidth() / 2) -
		                        (bullet->getWidth() / 2),
		                    player->position.y};

		bullets.emplace_back(bullet);
		fireRate = 0;
	}

	while (!bullets.empty() &&
	       bullets.front()->position.y + bullets.front()->getHeight() <= 0) {
		Entity* b = bullets.front();
		bullets.pop_front();
		delete b;
	}
	for (auto&& bullet : bullets) {
		for (auto&& enemy : enemies) {
			if (bullet->visiable && enemy->visiable &&
			    bullet->collidesWith(*enemy)) {
				bullet->visiable = false;
				enemy->visiable = false;
				score++;
				break;
			}
		}
		bullet->moveByValocity(deltaTime);
	}

	return true;
}

void SpaceBlaster::RenderScreen() {
	Clear(olc::BLACK);
	for (size_t i = 0; i < bgStars.size(); i++) {
		Draw(*bgStars[i], olc::WHITE);
	}

	for (const auto& enemy : enemies) {
		if (enemy->visiable) {
			enemy->draw(this);
		}
	}
	for (const auto& bullet : bullets) {
		if (bullet->visiable) {
			bullet->draw(this);
		}
	}
	player->draw(this);
	std::stringstream strScore;
	strScore << score;
	DrawString({0, 0}, strScore.str());
}
