#pragma once

#include "olcPixelGameEngine.h"

class PositionRect {
public:
protected:
	olc::vf2d position;

public:
	PositionRect();
	PositionRect(olc::vf2d p_pos);
	~PositionRect() = default;

	virtual float height() const = 0;
	virtual float width() const = 0;

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

private:
};