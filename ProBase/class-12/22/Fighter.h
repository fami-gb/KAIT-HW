#include<stdio.h>

#include"shooting_game_def.h"
#include"Bullet.h"

#ifndef __FIGHTER_CLASS__
#define __FIGHTER_CLASS__

class Fighter {
private:
	const char* shape; // 戦闘機の形状
	int size;			// 戦闘機の大きさ
	int xpos;			// 戦闘機の左端のX座標
	int ypos;			// 戦闘機の右端のY座標
	int move_dir = 0;	// 移動方向
public:
	Fighter() = delete;
	Fighter(int y, int x, const char* shape, int size);

	void update_pos(int dir); // 描画位置を更新する。引数は移動方向と移動量
	void shoot(Bullet& blt); // 弾丸を発射する
	bool check_hit(Bullet blt); // 弾丸に当たっているかをチェックする
	void draw();				// 戦闘機を描画する

	int get_y();				// 戦闘機のY座標
	int get_left_x();			// 戦闘機の左端のX座標
	int get_right_x();			// 戦闘機の右端のX座標
	int get_center_x();			// 戦闘機の中心のX座標
	int get_size();				// 戦闘機の大きさ
};

#endif
