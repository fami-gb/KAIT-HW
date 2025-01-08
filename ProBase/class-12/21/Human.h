#include<stdio.h>

#ifndef __HUMAN_H__
#define __HUMAN_H__

class Human {
private:
	const char* name;
	int life;
public:
	// deleteはデフォルトコンストラクタを削除する
	Human() = delete;

	Human(const char* name_, int life_);

	void eat(int amount);
	void walk(int distance);
	const char* get_name();
	void print_life_gauge();
};

#endif
