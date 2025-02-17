#pragma once

#ifndef SPACE_BLASTER_H
#define SPACE_BLASTER_H

#include "olcPixelGameEngine.h"


class SpaceBlaster : public olc::PixelGameEngine {
   public:
	SpaceBlaster();
	~SpaceBlaster() = default;

   private:
	struct sSpaceObject {
		float x = 0.0f;
		float y = 0.0f;
		float vx = 0.0f;
		float vy = 0.0f;
		float angle = 0.0f;
		bool bDead = false;
	};

	std::list<sSpaceObject> listProjectiles;
	std::list<sSpaceObject> listEnemies;
	sSpaceObject player;
	float fPlayerThrust = 100.0f;
	float fPlayerAngle = 0.0f;
	float fPlayerAngularSpeed = 5.0f;
	int nScore = 0;


   public:
	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;
};

#endif  // !SPACE_BLASTER_H