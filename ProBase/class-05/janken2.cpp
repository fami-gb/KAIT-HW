#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int main() {
	int com, player;
	int win_c = 0, win_p = 0;
	int aiko = 0;
	
	const char* janken[] = { "グー", "チョキ", "パー" };
	const char* shout1[] = { "ジャンケン", "あいこで" };
	const char* shout2[] = { "ポン！", "ショ！" };

	srand((unsigned int)time(NULL));

	while (1) {
		// 0, 1, 2以外が入力された時の例外処理
		while (1) {
			printf("%s", shout1[aiko]);
			com = rand() % 3;
			player = getch() - 0x30;
			if (0 <= player && player <= 2) break;
			printf("0, 1, 2のいずれかの数字を入力してください");
		}
		printf("%s\n", shout2[aiko]);
		aiko = 0;

		printf("あなた %s わたし %s\n", janken[player], janken[com]);


		int result = (com - player + 3) % 3;

		if (result == 1) {
			printf("つよいな...あなたの勝ち\n\n");
			win_p += 1;
		}
		else if (result == 2) {
			printf("わーい！！ぼくの勝ち\n\n");
			win_c += 1;
		}
		else {
			printf("あいこだ！\n\n");
			aiko = 1;
			continue;
		}

		printf("あなた %d勝 ぼく %d勝\n\n", win_p, win_c);

		if (win_c == 2) {
			printf("この勝負！ぼくの勝ち！\n");
			break;
		}
		else if (win_p == 2) {
			printf("この勝負、あなたの勝ち...\n");
			break;
		}
	}
}
