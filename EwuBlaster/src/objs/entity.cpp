
#include "objs/entity.h"

#include "game.h"


Entity::Entity(const char *p_filepath) : PositionRect({0, 0}) {
	sprite = new olc::Sprite(p_filepath);
	decal = new olc::Decal(sprite);

	state = State::INACTIVE;

	scale = {1, 1};

	velocity = {0, 0};
	acceleration = {0, 0};
}

Entity::~Entity() {
	if (sprite)
		delete sprite;
	if (decal)
		delete decal;
}

float Entity::height() const {
	return (decal->sprite->height) * scale.y;
}
float Entity::width() const {
	return (decal->sprite->width) * scale.x;
}

void Entity::setHeight(float p_height) {
	scale.y = p_height / (decal->sprite->height);
}
void Entity::setWidth(float p_width) {
	scale.x = p_width / (decal->sprite->width);
}
void Entity::setScaling(olc::vf2d p_new_scale) {
	scale = p_new_scale;
}

void Entity::draw(Game *p_game) const {
	p_game->DrawDecal(position, decal, scale);
}


void Entity::move(float p_delta_time) {
	velocity += acceleration * p_delta_time * 0.5f;
	position += velocity.norm() * velocity.mag() * p_delta_time;
	velocity += acceleration * p_delta_time * 0.5f;
}
