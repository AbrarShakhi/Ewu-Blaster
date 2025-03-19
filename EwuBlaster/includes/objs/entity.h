#pragma once

#include "objs/positionrect.h"
#include "olcPixelGameEngine.h"

class Game;

class Entity : public PositionRect {
	enum State { INACTIVE = -1, DEAD, ALIVE };

public:
private:
	olc::Sprite *sprite;
	olc::Decal *decal;
	State state;

	olc::vf2d scale;

	olc::vf2d velocity;
	olc::vf2d acceleration;

public:
	Entity(const char *p_filepath);
	~Entity();

	float height() const override;
	float width() const override;
	void setHeight(float p_height);
	void setWidth(float p_width);
	void setScaling(olc::vf2d p_new_scale);

	void draw(Game *p_game) const;
	void move(float p_delta_time);

private:
};
