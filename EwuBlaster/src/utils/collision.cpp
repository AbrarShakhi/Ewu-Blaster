
#include "utils/collision.h"

bool Collision::RectAndPoint(olc::vf2d p_rect_pos_topleft, olc::vf2d p_rect_size, olc::vf2d p_point) {
	if (p_point.x < p_rect_pos_topleft.x || p_point.y < p_rect_pos_topleft.y) {
		return false;
	} else if (p_point.x > (p_rect_pos_topleft.x + p_rect_size.x) ||
	           p_point.y > (p_rect_pos_topleft.y + p_rect_size.y)) {
		return false;
	}
	return true;
}