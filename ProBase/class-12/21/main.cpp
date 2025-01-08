#include"Human.h"

int main() {
	// インスタンスの生成
	Human taro("太郎", 100);
	Human hanako("花子", 70);
	Human shin("任意の名前", 50);

	// 名前の表示
	printf("僕の名前は%sです\n", taro.get_name());
	printf("私の名前は%sです\n", hanako.get_name());
	printf("僕の名前は%sです\n", shin.get_name());

	// 体力の表示
	taro.print_life_gauge();
	hanako.print_life_gauge();
	shin.print_life_gauge();

	// 歩く
	taro.walk(50);
	hanako.walk(50);
	shin.walk(30);

	// 体力の表示
	taro.print_life_gauge();
	hanako.print_life_gauge();
	shin.print_life_gauge();

	// 食べる
	taro.eat(100);
	hanako.eat(40);
	shin.eat(50);

	// 体力の表示
	taro.print_life_gauge();
	hanako.print_life_gauge();
	shin.print_life_gauge();

	return 0;
}
