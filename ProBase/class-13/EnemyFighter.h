#include"Fighter.h"
#include"Bullet.h"
#include<stdlib.h>
#include<time.h>
#include<string>

#ifndef  __ENEMY_FIGHTER_H__
#define __ENEMY_FIGHTER_H__

class EnemyFighter : public Fighter {
private:
	int move_ef = 1;
public:
	EnemyFighter(int y_, int x_, const char* shape_);
	void update();
	bool shoot(Bullet& blt);
};

#endif
