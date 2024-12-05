#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int i, j;

	srand((unsigned int)time(NULL));

	/*for (i = 0; i < 10; i++) {
		int rnd = rand();
		printf("%d回目 %d\n", i + 1, rand);
	}*/

	for (i = 0; i < 10; i++) {
		int dice = rand() % 6 + 1;
		printf("%d回目 %d\n", i + 1, dice);
	}

	// 練習1
	for (i = 0; i < 10; i++) {
		int roulette = rand() % 10 + 1;
		printf("%d回目 %d\n", i + 1, roulette);
	}

	// 練習2
	for (i = 0; i < 10; i++) {
		printf("%d回目", i + 1);
		for (j = 0; j < 3; j++) {
			int slot = rand() % 10;
			printf("%d",slot);
		}
		printf("\n");
	}

	// 練習3・4
	for (i = 0; i < 10; i++) {
		int card = rand() % 4;
		int num = rand() % 13 + 1;
		printf("%d回目", i+1);
		switch (card) {
		case 0:
			printf("スペードの");
			break;
		case 1:
			printf("ハートの");
			break;
		case 2:
			printf("クローバーの");
			break;
		case 3:
			printf("ダイヤの");
			break;
		}
		printf("%d\n", num);
	}
}
