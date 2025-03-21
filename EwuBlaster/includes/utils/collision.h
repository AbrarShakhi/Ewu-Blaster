#pragma once

#include "olcPixelGameEngine.h"

class Collision {
private:
public:
	static bool RectAndPoint(olc::vf2d p_rect_pos_topleft, olc::vf2d p_rect_size, olc::vf2d p_point);
};
