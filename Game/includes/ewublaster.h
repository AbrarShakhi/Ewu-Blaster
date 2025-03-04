#pragma once

#include <array>
#include <list>

#include "entity.h"
#include "olcPixelGameEngine.h"


class EwuBlaster : public olc::PixelGameEngine {
   private:

   public:
	EwuBlaster();
	~EwuBlaster() = default;
private:
	bool OnUserCreate() override;
	bool OnUserUpdate(float deltaTime) override;
	bool OnUserDestroy() override;

	bool HandleUserEvent(float deltaTime);
	bool UpdateGameLogic(float deltaTime);
	void RenderScreen();
};
