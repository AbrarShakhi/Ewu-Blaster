
#include "objs/positionrect.h"

PositionRect::PositionRect() : PositionRect({0, 0}) {
}

PositionRect::PositionRect(olc::vf2d p_pos) {
	position = p_pos;
}

olc::vf2d PositionRect::topLeft() const {
	return position;
}
olc::vf2d PositionRect::topRight() const {
	return {position.x + width(), position.y};
}
olc::vf2d PositionRect::bottomLeft() const {
	return {position.x, position.y + height()};
}
olc::vf2d PositionRect::bottomRight() const {
	return {position.x + width(), position.y + height()};
}
olc::vf2d PositionRect::topCenter() const {
	return {(position.x + width()) / 2.0f, position.y};
}
olc::vf2d PositionRect::bottomCenter() const {
	return {(position.x + width()) / 2.0f, position.y + height()};
}
olc::vf2d PositionRect::leftCenter() const {
	return {position.x, (position.y + height()) / 2.0f};
}
olc::vf2d PositionRect::rightCenter() const {
	return {position.x + width(), (position.y + height()) / 2.0f};
}
olc::vf2d PositionRect::center() const {
	return {(position.x + width()) / 2.0f, (position.y + height()) / 2.0f};
}

void PositionRect::setTopLeft(olc::vf2d p_pos) {
	position = p_pos;
}
void PositionRect::setTopCenter(olc::vf2d p_pos) {
	position = {p_pos.x - (width() / 2.0f), p_pos.y};
}
void PositionRect::setTopRight(olc::vf2d p_pos) {
	position = {p_pos.x - width(), p_pos.y};
}
void PositionRect::setBottomLeft(olc::vf2d p_pos) {
	position = {p_pos.x, p_pos.y - height()};
}
void PositionRect::setBottomCenter(olc::vf2d p_pos) {
	position = {p_pos.x - (width() / 2.0f), p_pos.y - height()};
}
void PositionRect::setBottomRight(olc::vf2d p_pos) {
	position = {p_pos.x - width(), p_pos.y - height()};
}
void PositionRect::setLeftCenter(olc::vf2d p_pos) {
	position = {p_pos.x, p_pos.y - (height() / 2.0f)};
}
void PositionRect::setRightCenter(olc::vf2d p_pos) {
	position = {p_pos.x - width(), p_pos.y - (height() / 2.0f)};
}
void PositionRect::setCenter(olc::vf2d p_pos) {
	position = {p_pos.x - (width() / 2.0f), p_pos.y - (height() / 2.0f)};
}