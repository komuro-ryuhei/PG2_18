#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet(float posX, float posY, float speed, float radius) {

	pos_ = { posX ,posY };
	speed_ = { speed };
	radius_ = { radius };
	isShot_ = false;
}

Bullet::~Bullet() {}

void Bullet::Update() {

	if (isShot_) {

		pos_.y -= speed_;
		if (pos_.y <= 0.0f - radius_) {

			isShot_ = false;
		}
	}
}

void Bullet::Draw() {

	if (isShot_) {

		Novice::DrawEllipse(int(pos_.x), int(pos_.y),
			int(radius_), int(radius_), 0.0f, RED, kFillModeSolid);
	}
}
