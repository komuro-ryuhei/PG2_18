#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"

const char kWindowTitle[] = "LC1B_13_コムロ_リュウヘイ";

int Enemy::isAlive_ = true;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player(640.0f, 600.0f, 8.0f, 16.0f);

	Enemy* enemyA = new Enemy(640.0f, 200.0f, 4.0f, 16.0f);
	Enemy* enemyB = new Enemy(640.0f, 300.0f, -4.0f, 16.0f);

	Collision* collision = new Collision;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		/***************************************************
								Player
		****************************************************/

		player->Move(keys, preKeys);
		player->Draw();

		/***************************************************
								Enemy
		****************************************************/

		enemyA->Move();
		enemyB->Move();

		enemyA->Draw();
		enemyB->Draw();

		/***************************************************
							Collision
		****************************************************/

		if (collision->isHit(player->BulletGetPos(), player->BulletGetRadius()
			, enemyA->GetPos(), enemyA->GetRadius()) ||
			collision->isHit(player->BulletGetPos(), player->BulletGetRadius(),
				enemyB->GetPos(), enemyB->GetRadius())) {

			Enemy::isAlive_ = false;
		}


		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();

	delete player;
	delete enemyA;
	delete enemyB;
	delete collision;

	return 0;
}
