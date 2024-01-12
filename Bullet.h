#pragma once
#include "Vector2.h"

class Bullet {

public:

	Bullet(float posX, float posY, float speed, float radius);
	void Update();
	void Draw();
	~Bullet();

public:

	Vector2 pos_;
	float speed_;
	float radius_;
	int isShot_;
};

