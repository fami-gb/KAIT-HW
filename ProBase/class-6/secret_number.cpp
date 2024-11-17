#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_TRIES 10

int main() {
	int com;
	int player[MAX_TRIES];
	int tries = 0;

	srand((unsigned int)time(NULL));

	com = rand() % 99 + 1; // 練習1

	printf("====数当てゲーム====\n");
	printf("私が念じた1から99までの数を当ててください\n");

	while (tries < MAX_TRIES) {  // 練習2
		printf("予想した数を入力してください：");
		(void)scanf("%d", &player[tries]);

		if (com > player[tries]) { // 練習3
			printf("もっと大きい数です\n");
		}
		else if (com < player[tries]) { // 練習3
			printf("もっと小さい数です\n");
		}
		else {
			printf("おめでとう！正解です！\n");
			tries++; // 修正点(正解の時にtriesが加算されずにwhileを抜けてしまうため)
			break; // 練習4
		}
		tries++; // 練習5
	}

	if (tries == MAX_TRIES) { // 練習6
		printf("残念でした。正解は %d でした。\n", com);
	}
	printf("予想回数： %d\n", tries);
	printf("予想した数： ");
	for (int i = 0; i < tries; i++) {
		printf("%d ", player[i]);
	}
	printf("\n");

	return 0;
}
