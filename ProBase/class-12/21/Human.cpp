#include"Human.h"

// コンストラクタ(名前と体力の初期化)
Human::Human(const char* name_, int life_):name(name_), life(life_)
{}

// 食べる
void Human::eat(int amount) {
	life += amount;
	printf("%sは%dのエネルギーを食べました\n", name, amount);
}

// 歩く
void Human::walk(int distance) {
	life -= distance;
	printf("%sは%dkm歩きました\n", name, distance);
}

// 名前を取得する
const char* Human::get_name() {
	return name;
}

// 体力を表示する
void Human::print_life_gauge() {
	printf("%sの体力は%dです\n", name, life);
}
