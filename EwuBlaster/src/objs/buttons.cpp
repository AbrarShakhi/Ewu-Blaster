
#include "objs/buttons.h"

#include "game.h"
#include "utils/collision.h"


Buttons::Buttons(const char *p_text) : Buttons(p_text, {0, 0}) {
}

Buttons::Buttons(const char *p_text, olc::vf2d p_pos) : PositionRect(p_pos), text(p_text) {
	highlight = false;
	selected = false;
	scale = {1, 1};
}

void Buttons::fitTextSize(Game *game) {
	textSize = game->GetTextSize(text);
}

bool Buttons::isSelected() const {
	return selected;
}

float Buttons::height() const {
	return (textSize.y * scale.y);
}

float Buttons::width() const {
	return (textSize.x * scale.x);
}

void Buttons::setHeight(float p_height) {
	scale.y = (p_height) / textSize.y;
}

void Buttons::setWidth(float p_width) {
	scale.x = (p_width) / textSize.x;
}

void Buttons::setScaling(olc::vf2d p_new_scale) {
	scale = p_new_scale;
}

void Buttons::draw(Game *p_game) const {
	olc::vf2d offset(5.0f, 5.0f);
	olc::vf2d width_heigh(width(), height());
	olc::Pixel tint = olc::BLACK;
	tint.a /= 3;
	p_game->FillRectDecal(position - offset, width_heigh + (offset * 2.0f), tint);

	if (highlight) {
		p_game->DrawStringDecal(position, text, olc::YELLOW, (scale * olc::vf2d(1.1f, 1.1f)));
	} else {
		p_game->DrawStringDecal(position, text, olc::YELLOW, scale);
	}
}


void Buttons::handle(Game *p_game) {
	highlight = false;
	selected = false;
	if (Collision::RectAndPoint(position, {width(), height()}, p_game->GetMousePos())) {
		highlight = true;
		if (p_game->GetMouse(0).bPressed || p_game->GetKey(olc::ENTER).bPressed ||
		    p_game->GetKey(olc::SPACE).bPressed) {
			selected = true;
		}
	}
}