#include "ewublaster.h"

#include "random.h"

EwuBlaster::EwuBlaster() {
	sAppName = "Ewu Blaster";
}

bool EwuBlaster::OnUserCreate() {
	return true;
}
bool EwuBlaster::OnUserDestroy() {
	return true;
}


bool EwuBlaster::OnUserUpdate(float deltaTime) {
	if (!HandleUserEvent(deltaTime)) {
		return false;
	}
	if (!UpdateGameLogic(deltaTime)) {
		return false;
	}

	RenderScreen();
	return true;
}


bool EwuBlaster::HandleUserEvent(float deltaTime) {
	if (GetKey(olc::SPACE).bHeld || GetKey(olc::W).bHeld) {
		return false;
	}
	return true;
}

bool EwuBlaster::UpdateGameLogic(float deltaTime) {
	return true;
}

void EwuBlaster::RenderScreen() {
	Clear(olc::BLACK);
	DrawString({0, 0}, "HELLo tHERE");
}
