#pragma once

#ifndef SPACE_BLASTER_H
#define SPACE_BLASTER_H

#include <array>
#include <list>

#include "entity.h"
#include "olcPixelGameEngine.h"


class SpaceBlaster : public olc::PixelGameEngine {
   private:
	std::array<olc::vi2d *, 100> bgStars = {nullptr};
	Entity *player = nullptr;
	std::list<Entity *> enemies;
	float tick;

   public:
	SpaceBlaster();
	~SpaceBlaster();
	bool OnUserCreate() override;
	bool HandleUserEvent(float deltaTime);

	bool OnUserUpdate(float deltaTime) override;
};

#endif  // !SPACE_BLASTER_H