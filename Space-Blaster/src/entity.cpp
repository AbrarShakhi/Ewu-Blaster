
#include "entity.h"

Entity::Entity(const char* p_imageFile)
    : imageFile(p_imageFile),
      position(0, 0),
      scale(1, 1),
      sprite(p_imageFile),
      decal(&sprite) {}

float Entity::getWidth() const { return sprite.width * scale.x; }
float Entity::getHeight() const { return sprite.height * scale.y; }


void Entity::draw(olc::PixelGameEngine* game) {
	game->DrawDecal(position, &decal, scale);
}

bool Entity::collidesWith(const Entity& other) const {
	if (this->position.x + this->getWidth() <= other.position.x) {
		return false;
	}
	if (other.position.x + other.getWidth() <= this->position.x) {
		return false;
	}
	if (other.position.y + other.getHeight() <= this->position.y) {
		return false;
	}
	if (this->position.y + this->getHeight() <= other.position.y) {
		return false;
	}

	return true;
}
