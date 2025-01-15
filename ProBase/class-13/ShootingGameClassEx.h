#include<Windows.h>
#include"shooting_game_def.h"
#include"OwnFighter.h"
#include"EnemyFighter.h"
#include"OwnBullet.h"
#include"EnemyBullet.h"

#ifndef __SHOOTING_GAME_CLASS_EX_H__
#define __SHOOTING_GAME_CLASS_EX_H__

#define N 5

class ShootingGameEx {
private:
	OwnFighter own_fighter;
	EnemyFighter enemy_fighter;
	OwnBullet own_bullet;
	EnemyBullet enemy_bullet[N]; // N個の配列
	InputKey input_key;

	int eb_cnt = 0; // 敵弾丸の番号
	int win = 0; // 自機が勝ったとき1, 敵機が勝ったとき2
public:
	// コンストラクタ
	ShootingGameEx(OwnFighter& of_, EnemyFighter& ef_)
		: own_fighter(of_), enemy_fighter(ef_) {
		printf("\x1b[?25l"); // カーソル消去
	}

	// デストラクタ
	~ShootingGameEx() {
		printf("\x1b[%d;%dH", HEIGHT, 1); // カーソルを最終行へ移動
		printf("\x1b[?25h"); // カーソル表示
	}

	// 実行
	void run() {
		while (1) {
			update();
			draw();
			if (check_hit()) break;
			Sleep(50);
		}
	}

	// 各種アップデート
	void update() {
		// 戦闘機の位置計算
		input_key.update();
		own_fighter.update(input_key);
		enemy_fighter.update();

		// 弾丸の発射
		own_fighter.shoot(input_key, own_bullet);
		if (enemy_fighter.shoot(enemy_bullet[eb_cnt]) == true) eb_cnt = (++eb_cnt) % N;

		// 弾丸の位置計算
		own_bullet.update();
		for (int i = 0; i < N; i++) enemy_bullet[i].update();
	}

	// 描画
	void draw() {
		printf("\x1b[2J");
		own_fighter.draw(); // Fighterクラスのdraw()を呼び出す
		enemy_fighter.draw(); // Fighterクラスのdraw()を呼び出し
		own_bullet.draw(); // Bulletクラスのdraw()を呼び出す
		for (int i = 0; i < N; i++) enemy_bullet[i].draw(); // Bulletクラスのdraw()
	}

	// 当たり判定
	bool check_hit() {
		// 敵機が自弾丸に当たっていたら
		if (enemy_fighter.check_hit(own_bullet) == true) {
			win = 1;
			return true;
		}
		for (int i = 0; i < N; i++) {
			// 自機が敵弾丸に当たっていたら
			if (own_fighter.check_hit(enemy_bullet[i]) == true) {
				win = 2;
				return true;
			}
		}
		return false;
	}

	// エンディング画面の表示
	void ending() {
		printf("\x1b[2J"); // 画面クリア
		// 自機の勝ち
		if (win == 1) {
			printf("\x1b[%d;%dH", HEIGHT / 2, WIDTH / 2 - 3); // 画面中央に表示
			printf("YOU WIN");
		}
		else if (win == 2) {
			printf("\x1b[%d;%dH", HEIGHT / 2, WIDTH / 2 - 2); // 画面中央に表示
			printf("E N D");
		}
		// ESCが押されるまで待機
		while (input_key.check_key(KeyName::ESCAPE) == false) {
			input_key.update();
			Sleep(50);
		}
	}
};

#endif
