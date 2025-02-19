#pragma once

#ifndef SPACE_BLASTER_H
#define SPACE_BLASTER_H

#include <array>

#include "olcPixelGameEngine.h"

class SpaceBlaster : public olc::PixelGameEngine {
   private:
	olc::Sprite* playerShipSprite = nullptr;
	olc::Decal* playerShip = nullptr;

	std::array<olc::vi2d*, 100> bgStars = {nullptr};

	olc::vf2d* playerPos = nullptr;

   public:
	SpaceBlaster();
	~SpaceBlaster();
	bool OnUserCreate() override;
	bool HandleUserEvent();

	bool OnUserUpdate(float fElapsedTime) override;
};

#endif  // !SPACE_BLASTER_H