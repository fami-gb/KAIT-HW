#include"shooting_game_func.h"
#include"shooting_game_def.h"
#include"Fighter.h"
#include"Bullet.h"
#include"InputKey.h"

int main() {
	// 敵機の移動方向と移動量
	int move_ef = 1;

	// インスタンスの生成
	// 練習1 (自機、敵機、自弾丸、敵弾丸の形状と大きさを変更)
	// 練習2 敵機を右端から移動し始めるようにする
	Fighter own_fighter(HEIGHT - 1, WIDTH / 2, "~~~", 3); // 初期位置(y, x), 形状, サイズ
	Fighter enemy_fighter(1, WIDTH, "#|#", 3); // 初期位置(y, x), 形状, サイズ
	Bullet own_bullet(-1, "*", 1); // 移動方向, 形状, サイズ
	Bullet enemy_bullet(1, "+", 1); // 移動方向, 形状, サイズ
	InputKey input_key; // キー入力

	init_screen(WIDTH, HEIGHT);
	srand((unsigned int)time(NULL));
	printf("\x1b[?25l");

	while (1) {
		// キー入力を確認
		input_key.update();

		// 自機の位置を計算
		if (input_key.check_key(KeyName::LEFT) == true)
			own_fighter.update_pos(-1); // 左へ移動
		else if (input_key.check_key(KeyName::RIGHT) == true)
			own_fighter.update_pos(1); // 右へ移動

		// 敵機の位置を計算
		if (enemy_fighter.get_left_x() <= 1 || enemy_fighter.get_right_x() >= WIDTH)
			move_ef = -move_ef;
		enemy_fighter.update_pos(move_ef);

		// 自弾丸の発射・初期位置を設定
		if (input_key.check_key(KeyName::SPACE) == true)
			own_fighter.shoot(own_bullet);
		own_bullet.update_pos();

		// 敵弾丸の発射・初期位置を設定
		// 練習3 確率を40%にあげる
		if (rand() % 100 < 40)
			enemy_fighter.shoot(enemy_bullet);
		enemy_bullet.update_pos();

		// 描画
		printf("\x1b[2J");
		own_fighter.draw();
		enemy_fighter.draw();
		own_bullet.draw();
		enemy_bullet.draw();

		// 当たり判定(描画前に当たり判定をすると、当たる直前の描画で止まるため)
		if (own_fighter.check_hit(enemy_bullet) == true) break;
		if (enemy_fighter.check_hit(own_bullet) == true) break;

		Sleep(50);
	}

	printf("\x1b[?25h");

	return 0;
}
