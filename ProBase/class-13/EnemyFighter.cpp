#include"EnemyFighter.h"

EnemyFighter::EnemyFighter(int y_, int x_, const char* shape_)
	: Fighter(y_, x_, shape_, strlen(shape_)) {

	srand((unsigned int)time(NULL));
}

// 位置の更新
void EnemyFighter::update() {
	if (get_left_x() <= 1 || get_right_x() >= WIDTH) move_ef = -move_ef;
	update_pos(move_ef);
}

// 弾丸の発射
bool EnemyFighter::shoot(Bullet& blt) {
	if (rand() % 100 < 5) {
		Fighter::shoot(blt);
		return true;
	}
	return false;
}
