#pragma once

#include <functional>

#include "objs/positionrect.h"

class Game;

class Buttons : public PositionRect {
private:
	const char *text;
	bool highlight;
	bool selected;
	olc::vf2d scale;
	olc::vf2d textSize;

public:
	Buttons(const char *p_text);
	Buttons(const char *p_text, olc::vf2d p_pos);
	~Buttons() = default;
	void fitTextSize(Game *game);

	bool isSelected() const;

	float height() const override;
	float width() const override;
	void setHeight(float p_height);
	void setWidth(float p_width);
	void setScaling(olc::vf2d p_new_scale);

	void draw(Game *p_game) const;
	void handle(Game *p_game);
};
