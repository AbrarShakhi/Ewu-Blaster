
#include "objs/entity.h"

#include "entity.h"
#include "game.h"

Entity::Entity(const char *p_filepath) : Entity(p_filepath, {0, 0}, {1, 1}, {0, 0}, {0, 0}) {
}

Entity::Entity(const char *p_filepath, olc::vf2d p_pos) : Entity(p_filepath, p_pos, {1, 1}, {0, 0}, {0, 0}) {
}

Entity::Entity(const char *p_filepath, olc::vf2d p_pos, olc::vf2d p_scale)
    : Entity(p_filepath, p_pos, p_scale, {0, 0}, {0, 0}) {
}

Entity::Entity(const char *p_filepath, olc::vf2d p_pos, olc::vf2d p_scale, olc::vf2d p_init_velocity)
    : Entity(p_filepath, p_pos, p_scale, p_init_velocity, {0, 0}) {
}

Entity::Entity(const char *p_filepath, olc::vf2d p_pos, olc::vf2d p_scale, olc::vf2d p_init_velocity,
               olc::vf2d p_init_accelation)
    : PositionRect(p_pos),
      sprite(p_filepath),
      decal(&sprite),
      scale(p_scale),
      velocity(p_init_velocity),
      acceleration(p_init_accelation) {
	state = State::INACTIVE;
}

void Entity::move(float p_delta_time) {
	velocity += acceleration * p_delta_time * 0.5f;
	position += velocity.norm() * velocity.mag() * p_delta_time;
	velocity += acceleration * p_delta_time * 0.5f;
}

float Entity::height() const {
	return (decal.sprite->height) * scale.y;
}
float Entity::width() const {
	return (decal.sprite->width) * scale.x;
}

void Entity::setHeight(float p_height) {
	scale.y = p_height / (decal.sprite->height);
}
void Entity::setWidth(float p_width) {
	scale.x = p_width / (decal.sprite->width);
}
void Entity::setScaling(olc::vf2d p_new_scale) {
	scale = p_new_scale;
}

void Entity::setEntityState(State p_state) {
	state = p_state;
}
Entity::State Entity::getEntityState() const {
	return state;
}

olc::vf2d Entity::getVelocity() const {
	return velocity;
}
void Entity::setVelocity(olc::vf2d p_vel) {
	velocity = p_vel;
}
olc::vf2d Entity::getAcceleration() const {
	return acceleration;
}
void Entity::setAcceleration(olc::vf2d p_accel) {
	acceleration = p_accel;
}
