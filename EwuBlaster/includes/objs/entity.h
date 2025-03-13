#pragma once

#include "olcPixelGameEngine.h"


class Entity {
	enum State { INACTIVE = -1, DEAD, ALIVE };

public:
	olc::vf2d postion;
	olc::vf2d scale;

	State state;

private:
	olc::Sprite *sprite;
	olc::Decal *decal;

public:
	Entity(const char *p_filepath);
	~Entity();

	float height() const;
	float width() const;

	olc::vf2d topLeft() const;
	olc::vf2d topCenter() const;
	olc::vf2d topRight() const;
	olc::vf2d bottomLeft() const;
	olc::vf2d bottomCenter() const;
	olc::vf2d bottomRight() const;
	olc::vf2d leftCenter() const;
	olc::vf2d rightCenter() const;
	olc::vf2d center() const;

private:
};
