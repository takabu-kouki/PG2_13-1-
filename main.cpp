#include <Novice.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <corecrt_math.h>

bool isBulletColliding(Bullet& bullet, Enemy& enemy) {
	int dx = bullet.bulletGetPosX() - enemy.getX();
	int dy = bullet.bulletGetPosY() - enemy.getY();
	int distance = (int)sqrt(dx * dx + dy * dy);

	return distance < 50;
}

const char kWindowTitle[] = "GC1D_07_タカブ_コウキ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	const int kWindowWidth = 1280; // ウィンドウの横幅
	const int kWindowHeight = 720; // ウィンドウの縦幅

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	Player* player = new Player;
	Enemy* enemy = new Enemy;
	Bullet* bullet = new Bullet;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->move(keys);
		enemy->move();
		bullet->shot(keys, preKeys, player->playerGetPosX(), player->playerGetPosY());

		if (isBulletColliding(*bullet, *enemy)) {
			enemy->FlagChange();
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから

		player->Drow();
		enemy->Drow();
		bullet->Drow();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete bullet;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
