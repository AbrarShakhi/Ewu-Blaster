
#include "objs/entity.h"

#include "game.h"


Entity::Entity(const char *p_filepath) {
	sprite = new olc::Sprite(p_filepath);
	decal = new olc::Decal(sprite);

	state = State::INACTIVE;

	position = {0, 0};
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

olc::vf2d Entity::topLeft() const {
	return position;
}
olc::vf2d Entity::topRight() const {
	return {position.x + width(), position.y};
}
olc::vf2d Entity::bottomLeft() const {
	return {position.x, position.y + height()};
}
olc::vf2d Entity::bottomRight() const {
	return {position.x + width(), position.y + height()};
}
olc::vf2d Entity::topCenter() const {
	return {(position.x + width()) / 2.0f, position.y};
}
olc::vf2d Entity::bottomCenter() const {
	return {(position.x + width()) / 2.0f, position.y + height()};
}
olc::vf2d Entity::leftCenter() const {
	return {position.x, (position.y + height()) / 2.0f};
}
olc::vf2d Entity::rightCenter() const {
	return {position.x + width(), (position.y + height()) / 2.0f};
}
olc::vf2d Entity::center() const {
	return {(position.x + width()) / 2.0f, (position.y + height()) / 2.0f};
}

void Entity::setTopLeft(olc::vf2d p_pos) {
	position = p_pos;
}
void Entity::setTopCenter(olc::vf2d p_pos) {
	position = {p_pos.x - (width() / 2.0f), p_pos.y};
}
void Entity::setTopRight(olc::vf2d p_pos) {
	position = {p_pos.x - width(), p_pos.y};
}
void Entity::setBottomLeft(olc::vf2d p_pos) {
	position = {p_pos.x, p_pos.y - height()};
}
void Entity::setBottomCenter(olc::vf2d p_pos) {
	position = {p_pos.x - (width() / 2.0f), p_pos.y - height()};
}
void Entity::setBottomRight(olc::vf2d p_pos) {
	position = {p_pos.x - width(), p_pos.y - height()};
}
void Entity::setLeftCenter(olc::vf2d p_pos) {
	position = {p_pos.x, p_pos.y - (height() / 2.0f)};
}
void Entity::setRightCenter(olc::vf2d p_pos) {
	position = {p_pos.x - width(), p_pos.y - (height() / 2.0f)};
}
void Entity::setCenter(olc::vf2d p_pos) {
	position = {p_pos.x - (width() / 2.0f), p_pos.y - (height() / 2.0f)};
}

void Entity::draw(Game *p_game) const {
	p_game->DrawDecal(position, decal, scale);
}


void Entity::move(float p_delta_time) {
	velocity += acceleration * p_delta_time * 0.5f;
	position += velocity.norm() * velocity.mag() * p_delta_time;
	velocity += acceleration * p_delta_time * 0.5f;
}
