#include"OwnFighter.h"

// コンストラクタ
OwnFighter::OwnFighter(int y_, int x_, const char* shape_)
	: Fighter(y_, x_, shape_, strlen(shape_)) {}

// 一の更新
void OwnFighter::update(InputKey input_key) {
	if (input_key.check_key(KeyName::LEFT) == true) update_pos(-1);
	else if (input_key.check_key(KeyName::RIGHT) == true) update_pos(1);
}

// 弾丸の発射
bool OwnFighter::shoot(InputKey input_key, Bullet& blt) {
	if (input_key.check_key(KeyName::SPACE) == true) {
		Fighter::shoot(blt);
		return true;
	}
	return false;
}
