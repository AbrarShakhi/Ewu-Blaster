#pragma once

#include "olcPixelGameEngine.h"

class Game;

class Entity {
	enum State { INACTIVE = -1, DEAD, ALIVE };

public:
private:
	olc::Sprite *sprite;
	olc::Decal *decal;
	State state;

	olc::vf2d position;
	olc::vf2d scale;

	olc::vf2d velocity;
	olc::vf2d acceleration;

public:
	Entity(const char *p_filepath);
	~Entity();

	float height() const;
	float width() const;

	void setHeight(float p_height);
	void setWidth(float p_width);
	void setScaling(olc::vf2d p_new_scale);

	olc::vf2d topLeft() const;
	olc::vf2d topCenter() const;
	olc::vf2d topRight() const;
	olc::vf2d bottomLeft() const;
	olc::vf2d bottomCenter() const;
	olc::vf2d bottomRight() const;
	olc::vf2d leftCenter() const;
	olc::vf2d rightCenter() const;
	olc::vf2d center() const;

	void setTopLeft(olc::vf2d p_pos);
	void setTopCenter(olc::vf2d p_pos);
	void setTopRight(olc::vf2d p_pos);
	void setBottomLeft(olc::vf2d p_pos);
	void setBottomCenter(olc::vf2d p_pos);
	void setBottomRight(olc::vf2d p_pos);
	void setLeftCenter(olc::vf2d p_pos);
	void setRightCenter(olc::vf2d p_pos);
	void setCenter(olc::vf2d p_pos);

	void draw(Game *p_game) const;
	void move(float p_delta_time);

private:
};
