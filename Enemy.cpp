#include "Enemy.h"

Enemy::Enemy(float posX, float posY, float speed, float radius) {

	pos_ = { posX ,posY };
	speed_ = { speed };
	radius_ = { radius };
}

void Enemy::Move() {

	pos_.x += speed_;

	if (pos_.x >= 1280.0f - radius_ || pos_.x <= 0.0f + radius_) {

		speed_ *= -1;
	}
}

void Enemy::Draw() {

	if (isAlive_) {

		Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_),
			0.0f, WHITE, kFillModeSolid);
	}
}