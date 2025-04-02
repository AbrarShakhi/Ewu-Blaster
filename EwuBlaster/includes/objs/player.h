#pragma once

#include "objs/entity.h"

class Player : public Entity {
public:
	Player(const char *p_filepath, const olc::vf2d p_pos);
	~Player();

	void draw(Game *p_game) override;
	void move(float p_delta_time, Game *p_game);
};