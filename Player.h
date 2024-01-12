#pragma once
#include "Vector2.h"
#include "Bullet.h"
#include "Novice.h"

class Player {
public:

	//コンストラクタ
	Player(float posX, float posY, float speed, float radius);

	void Move(char* keys, char* preKeys);
	void Draw();
	~Player();

	Bullet* bullet_;

	//バレットのゲッター,セッター
	Vector2 BulletGetPos() { return bullet_->pos_; }
	float BulletGetSpeed() { return bullet_->speed_; }
	float BulletGetRadius() { return bullet_->radius_; }

private:

	Vector2 pos_;
	float radius_;
	float speed_;
};

