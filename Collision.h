#pragma once
#include "Vector2.h"
#include "Player.h"
#include "Enemy.h"
#define _USE_MATH_DFINES
#include "math.h"

class Collision {

public:

	bool isHit(Vector2 posA_, float RadiusA_, Vector2 posB_, float RadiusB);
};

