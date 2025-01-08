#include"Fighter.h"

// コンストラクタ
Fighter::Fighter(int y_, int x_, const char* shape_, int size_)
	:xpos(x_), ypos(y_), shape(shape_), size(size_){}

void Fighter::update_pos(int dir) {
	move_dir = dir;
	xpos += move_dir; // 戦闘機の位置を更新
	if (get_left_x() < 1) xpos = 1; // 戦闘機が左端を超えた時
	if (get_right_x() > WIDTH) xpos = WIDTH - (size - 1); // 戦闘機が右端を超えた時
}

// 弾丸の発射
void Fighter::shoot(Bullet& blt) {
	blt.set_init_pos(get_y(), get_center_x());
}

// 当たり判定
bool Fighter::check_hit(Bullet blt) {
	if (blt.get_y() == get_y()) {
		if (blt.get_right_x() >= get_left_x() && blt.get_left_x() <= get_right_x())
			return true;
	}
	return false;
}

// 描画する
void Fighter::draw() {
	printf("\x1b[%d;%dH%s", ypos, xpos, shape);
}

// 戦闘機のY座標を取得する
int Fighter::get_y() {
	return ypos;
}

// 戦闘機の左端のX座標を取得する
int Fighter::get_left_x() {
	return xpos;
}

// 戦闘機の右端のX座標を取得する
int Fighter::get_right_x() {
	return xpos + size - 1;
}

// 戦闘機の中心のX座標を取得する
int Fighter::get_center_x() {
	if (size % 2 == 0) return xpos + (size / 2) - 1;
	else return xpos + (size / 2);
}

// 戦闘機の大きさを取得する
int Fighter::get_size() {
	return size;
}
