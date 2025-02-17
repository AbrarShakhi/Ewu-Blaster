#include "spaceblaster.h"

#include <cmath>
#include <list>

SpaceBlaster::SpaceBlaster() { sAppName = "Space Blaster"; }

bool SpaceBlaster::OnUserCreate() {
	player.x = ScreenWidth() / 2.0f;
	player.y = ScreenHeight() / 2.0f;

	return true;
}

bool SpaceBlaster::OnUserUpdate(float fElapsedTime) {
	Clear(olc::BLACK);


	if (GetKey(olc::Key::LEFT).bHeld)
		fPlayerAngle -= fPlayerAngularSpeed * fElapsedTime;
	if (GetKey(olc::Key::RIGHT).bHeld)
		fPlayerAngle += fPlayerAngularSpeed * fElapsedTime;

	if (GetKey(olc::Key::UP).bHeld) {
		player.vx += cos(fPlayerAngle) * fPlayerThrust * fElapsedTime;
		player.vy += sin(fPlayerAngle) * fPlayerThrust * fElapsedTime;
	}

	player.vx *= 0.99f;
	player.vy *= 0.99f;

	player.x += player.vx * fElapsedTime;
	player.y += player.vy * fElapsedTime;

	if (player.x < 0)
		player.x = ScreenWidth();
	if (player.x >= ScreenWidth())
		player.x = 0;
	if (player.y < 0)
		player.y = ScreenHeight();
	if (player.y >= ScreenHeight())
		player.y = 0;


	if (GetKey(olc::Key::SPACE).bPressed) {
		sSpaceObject projectile;
		projectile.x = player.x;
		projectile.y = player.y;
		projectile.vx = cos(fPlayerAngle) * 200.0f + player.vx;
		projectile.vy = sin(fPlayerAngle) * 200.0f + player.vy;
		listProjectiles.push_back(projectile);
	}

	int nSize = 10;
	for (int i = 0; i < 4; i++) {
		float angle = fPlayerAngle + float(i) / 4.0f * 2.0f * 3.14159f;
		float x = player.x + cos(angle) * nSize;
		float y = player.y + sin(angle) * nSize;
		Draw(x, y, olc::YELLOW);
	}

	for (auto &p : listProjectiles) {
		p.x += p.vx * fElapsedTime;
		p.y += p.vy * fElapsedTime;

		Draw(p.x, p.y, olc::WHITE);

		if (p.x < 0 || p.x >= ScreenWidth() || p.y < 0 || p.y >= ScreenHeight())
			p.bDead = true;
	}

	listProjectiles.remove_if([](const sSpaceObject &p) { return p.bDead; });


	if (rand() % 100 == 0) {
		sSpaceObject enemy;
		enemy.x = (float)(rand() % ScreenWidth());
		enemy.y = 0;
		enemy.vx = 0;
		enemy.vy = (float)(rand() % 50 + 20);
		listEnemies.push_back(enemy);
	}

	for (auto &e : listEnemies) {
		e.x += e.vx * fElapsedTime;
		e.y += e.vy * fElapsedTime;

		Draw(e.x, e.y, olc::RED);

		if (e.x < 0 || e.x >= ScreenWidth() || e.y < 0 || e.y >= ScreenHeight())
			e.bDead = true;
	}

	listEnemies.remove_if([](const sSpaceObject &e) { return e.bDead; });

	for (auto &p : listProjectiles) {
		for (auto &e : listEnemies) {
			if (fabs(p.x - e.x) < 5 && fabs(p.y - e.y) < 5) {
				p.bDead = true;
				e.bDead = true;
				nScore += 10;
			}
		}
	}


	DrawString(10, 10, "Score: " + std::to_string(nScore), olc::WHITE);

	return true;
}