#include "Player.h"

Player::Player(float posX, float posY, float speed, float radius) {

	pos_ = { posX ,posY };
	speed_ = { speed };
	radius_ = { radius };

	bullet_ = new Bullet(0.0f, 0.0f, 10.0f, 8.0f);
}

Player::~Player() { delete bullet_; }

void Player::Move(char* keys, char* preKeys) {

	if (keys[DIK_A]) {

		pos_.x -= speed_;
	}

	if (keys[DIK_D]) {

		pos_.x += speed_;
	}

	if (keys[DIK_W]) {

		pos_.y -= speed_;
	}

	if (keys[DIK_S]) {

		pos_.y += speed_;
	}

	if (!bullet_->isShot_) {
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

			bullet_->pos_.x = pos_.x;
			bullet_->pos_.y = pos_.y;
			bullet_->isShot_ = true;
		}
	}

	bullet_->Update();
}

void Player::Draw() {

	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_),
		0.0f, WHITE, kFillModeSolid);

	bullet_->Draw();

	Novice::ScreenPrintf(10, 10, "%d", bullet_->isShot_);
}

