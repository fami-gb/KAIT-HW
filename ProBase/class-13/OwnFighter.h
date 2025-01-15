#include"Fighter.h"
#include"Bullet.h"
#include"InputKey.h"
#include<string>

#ifndef __OWN_FIGHTR_H__
#define __OWN_FIGHTR_H__

class OwnFighter : public Fighter {
public:
	OwnFighter(int y_, int x_, const char* shape_);
	void update(InputKey input_key);
	bool shoot(InputKey input_key, Bullet& blt);
};

#endif
