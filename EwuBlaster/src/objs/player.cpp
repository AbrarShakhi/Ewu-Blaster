#include "objs/player.h"

#include "game.h"

Player::Player(const char *p_filepath, const olc::vf2d p_pos) : Entity(p_filepath, p_pos, {1, 1}, {0, 0}, {0, 0}) {
	setEntityState(INACTIVE);
}
Player::~Player() {
	// Destructor
}

void Player::draw(Game *p_game) {
	p_game->DrawDecal(topLeft(), &decal, scale);
}

void Player::move(float p_delta_time, Game *p_game) {
	olc::vf2d pos = topLeft();
	olc::vf2d speed = {100.0f, 100.0f};

	if (p_game->GetKey(olc::W).bHeld || p_game->GetKey(olc::UP).bHeld) {
		pos.y -= speed.y * p_delta_time;
	}
	if (p_game->GetKey(olc::S).bHeld || p_game->GetKey(olc::DOWN).bHeld) {
		pos.y += speed.y * p_delta_time;
	}
	if (p_game->GetKey(olc::A).bHeld || p_game->GetKey(olc::LEFT).bHeld) {
		pos.x -= speed.x * p_delta_time;
	}
	if (p_game->GetKey(olc::D).bHeld || p_game->GetKey(olc::RIGHT).bHeld) {
		pos.x += speed.x * p_delta_time;
	}

	if (pos.x < 0) {
		pos.x = 0;
	}
	if (pos.x > p_game->ScreenWidth() - width()) {
		pos.x = p_game->ScreenWidth() - width();
	}
	if (pos.y < 0) {
		pos.y = 0;
	}
	if (pos.y > p_game->ScreenHeight() - height()) {
		pos.y = p_game->ScreenHeight() - height();
	}

	setTopLeft(pos);
}
