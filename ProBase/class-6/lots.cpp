#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define N 100 // 練習5 10本 -> 100本

int main() {
	int i;
	int num;
	int lots[N];
	const char* result[] = { "大吉", "吉", "中吉", "小吉", "末吉", "凶", "大凶" };

	srand((unsigned int)time(NULL));

	for (i = 0; i < N; i++) { // 練習1
		lots[i] = rand() % 7; // 練習2
	}

	printf("おみくじアプリ\n");
	printf("Enterキーで止めて、くじを引いてください：");
	
	while (kbhit() == 0) {
		num = rand() % N; // 練習3
		printf("%2d\b\b", num);
	}
	(void)scanf("%*c");
	printf("%d番の引き出しを開けます\n", num);

	printf("%sを引きました\n", result[lots[num]]); // 練習4・6

	return 0;
}
