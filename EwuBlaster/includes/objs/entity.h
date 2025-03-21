#pragma once

#include "objs/positionrect.h"
#include "olcPixelGameEngine.h"

class Game;


class Entity : public PositionRect {
public:
	enum State { INACTIVE = -1, DEAD, ALIVE };

protected:
	olc::Sprite sprite;
	olc::Decal decal;

	State state;
	olc::vf2d scale;
	olc::vf2d velocity;
	olc::vf2d acceleration;

public:
	Entity(const char *p_filepath);
	Entity(const char *p_filepath, olc::vf2d p_pos);
	Entity(const char *p_filepath, olc::vf2d p_pos, olc::vf2d p_scale);
	Entity(const char *p_filepath, olc::vf2d p_pos, olc::vf2d p_scale, olc::vf2d p_init_velocity);
	Entity(const char *p_filepath, olc::vf2d p_pos, olc::vf2d p_scale, olc::vf2d p_init_velocity,
	       olc::vf2d p_init_accelation);
	~Entity() = default;

	virtual void draw(Game *p_game) const = 0;

	void move(float p_delta_time);

	float height() const override;
	float width() const override;
	void setHeight(float p_height);
	void setWidth(float p_width);
	void setScaling(olc::vf2d p_new_scale);

	void setEntityState(State p_state);
	State getEntityState() const;

	olc::vf2d getVelocity() const;
	void setVelocity(olc::vf2d p_vel);
	olc::vf2d getAcceleration() const;
	void setAcceleration(olc::vf2d p_accel);
};
