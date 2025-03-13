
#include "objs/entity.h"


Entity::Entity(const char *p_filepath) {
	sprite = new olc::Sprite(p_filepath);
	decal = new olc::Decal(sprite);
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

olc::vf2d Entity::topLeft() const {
	return postion;
}

olc::vf2d Entity::topRight() const {
	return {postion.x + width(), postion.y};
}

olc::vf2d Entity::bottomLeft() const {
	return {postion.x, postion.y + height()};
}

olc::vf2d Entity::bottomRight() const {
	return {postion.x + width(), postion.y + height()};
}

olc::vf2d Entity::topCenter() const {
	return {(postion.x + width()) / 2.0f, postion.y};
}

olc::vf2d Entity::bottomCenter() const {
	return {(postion.x + width()) / 2.0f, postion.y + height()};
}

olc::vf2d Entity::leftCenter() const {
	return {postion.x, (postion.y + height()) / 2.0f};
}

olc::vf2d Entity::rightCenter() const {
	return {postion.x + width(), (postion.y + height()) / 2.0f};
}

olc::vf2d Entity::center() const {
	return {(postion.x + width()) / 2.0f, (postion.y + height()) / 2.0f};
}
