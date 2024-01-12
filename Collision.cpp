#include "Collision.h"

bool Collision::isHit(Vector2 posA_, float RadiusA_, Vector2 posB_, float RadiusB_) {

	Vector2 length = posA_ - posB_;

	float lengthXY = sqrtf(length.x * length.x + length.y * length.y);

	if (lengthXY <= RadiusA_ + RadiusB_) {

		return true;
	} else {
		return false;
	}
}
