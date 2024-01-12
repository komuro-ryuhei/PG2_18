#pragma once
#include "Vector2.h"
#include "Novice.h"

class Enemy {

public:

	//コンストラクタ
	Enemy(float posX, float posY, float speed, float radius);

	static int isAlive_;

	void Move();
	void Draw();

	Vector2 GetPos() { return pos_; }
	float GetSpeed() { return speed_; }
	float GetRadius() { return radius_; }

private:

	Vector2 pos_;
	float radius_;
	float speed_;

};

