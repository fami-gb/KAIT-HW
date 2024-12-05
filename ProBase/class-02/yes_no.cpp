#include<stdio.h>
#include<Windows.h>

int main() {
	int signal;
	int life;
	char ch;
	int x;

	//例題
	printf("信号は何色ですか？（青：0, 黄：1, 赤：2）");
	(void)scanf("%d", &signal); // 戻り値に問題があるため明示的にvoidにしておく
	rewind(stdin); // キーバッファに溜まったものを消す
	if (signal == 0) {
		printf("青なので発信します\n");
	} else {
		printf("青ではないので停止します\n");
	}

	//練習1
	printf("ショートケーキは売っていますか？(y/n)");
	(void)scanf("%c", &ch);
	rewind(stdin);
	if (ch == 'y') {
		printf("ショートケーキを買って帰ります\n");
	} else {
		printf("諦めて帰ります...\n");
	}

	//練習2
	printf("ショートケーキは売っていますか？(y/n)");
	(void)scanf("%c", &ch);
	rewind(stdin);
	if (ch == 'y') {
		printf("何個買いますか？");
		(void)scanf("%d", &x);
		rewind(stdin);
		printf("ショートケーキを%d個買って帰ります\n", x);
	} else {
		printf("諦めて帰ります...\n");
	}

	//練習3
	printf("右左どっち？（右：0, 左：1）");
	(void)scanf("%d", &life);
	rewind(stdin);
	if (life == 0) {
		printf("右翼です");
	} else {
		printf("左翼です");
	}
	return 0;
}
