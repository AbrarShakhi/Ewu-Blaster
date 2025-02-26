#pragma once
#include "olcPixelGameEngine.h"

class Entity {
   public:
	olc::vf2d position;
	olc::vf2d scale;
	olc::vf2d valocity;

   private:
	const char *imageFile = nullptr;
	olc::Sprite sprite;
	olc::Decal decal;

   public:
	Entity(const char *p_imageFile);
	~Entity() = default;

	float getWidth() const;
	float getHeight() const;

	void draw(olc::PixelGameEngine *game);
	bool collidesWith(const Entity &other) const;

   private:
};
