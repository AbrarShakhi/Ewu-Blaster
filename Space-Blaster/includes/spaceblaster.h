#pragma once

#include <array>
#include <list>

#include "entity.h"
#include "olcPixelGameEngine.h"


class SpaceBlaster : public olc::PixelGameEngine {
   private:
	std::array<olc::vi2d *, 100> bgStars = {nullptr};
	Entity *player = nullptr;
	std::list<Entity *> enemies;
	std::list<Entity *> bullets;
	float enemiesRate;
	float fireRate;

	size_t score;

   public:
	SpaceBlaster();
	~SpaceBlaster() = default;
	bool OnUserCreate() override;
	bool OnUserUpdate(float deltaTime) override;
	bool OnUserDestroy() override;

	bool HandleUserEvent(float deltaTime);
	bool UpdateGameLogic(float deltaTime);
	void RenderScreen();
};
