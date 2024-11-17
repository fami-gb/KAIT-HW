#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h> // getch()のため

int main() {
	int com, player;
	int win_c = 0, win_p = 0;

	srand((unsigned int)time(NULL));

	while (1) {
		printf("ジャンケン");
		com = rand() % 3; // 練習1
		player = getch() - 0x30; // 数字の文字コードは連番だから、0x30を引けば0, 1, 2と取得できる。
		printf("ポン！\n");
		
		// 練習6
		if (player == 0) {
			printf("あなた グー ");
			if (com == 0) {
				printf("わたし グー\n");
			}
			else if (com == 1) {
				printf("わたし チョキ\n");
			}
			else if (com == 2) {
				printf("わたし パー\n");
			}
		}
		else if (player == 1) {
			printf("あなた チョキ ");
			if (com == 0) {
				printf("わたし グー\n");
			}
			else if (com == 1) {
				printf("わたし チョキ\n");
			}
			else if (com == 2) {
				printf("わたし パー\n");
			}
		}
		else if (player == 2) {
			printf("あなた パー ");
			if (com == 0) {
				printf("わたし グー\n");
			}
			else if (com == 1) {
				printf("わたし チョキ\n");
			}
			else if (com == 2) {
				printf("わたし パー\n");
			}
		}

		// グーで勝つ時
		bool isWinRock_p = com == 1 && player == 0;
		// チョキで勝つ時
		bool isWinScis_p = com == 2 && player == 1;
		// パーで勝つ時
		bool isWinPapr_p = com == 0 && player == 2;

		if (player == com) {
			printf("あいこだ！\n\n");
			continue;
		}
		else if (isWinRock_p || isWinScis_p || isWinPapr_p) {
			printf("つよいな...あなたの勝ち\n\n");
			win_p += 1;
		}
		else {
			printf("わーい！ぼくの勝ち\n\n");
			win_c += 1;
		}

		//// グーで勝つ時
		//bool isWinRock_c = com == 0 && player == 1;
		//bool isWinRock_p = com == 1 && player == 0;
		//// チョキで勝つ時
		//bool isWinScis_p = com == 1 && player == 2;
		//bool isWinScis_p = com == 2 && player == 1;
		//// パーで勝つ時
		//bool isWinPapr_c = com == 2 && player == 0;
		//bool isWinPapr_p = com == 0 && player == 2;
		// 
		//if (isWinRock_c || isWinScis_c || isWinPapr_c) {
		//	printf("わーい！ぼくの勝ち\n\n");
		//	win_c += 1; // 練習3
		//}
		//else if (isWinRock_p || isWinScis_p || isWinPapr_p) {
		//	printf("つよいな...あなたの勝ち\n\n");
		//	win_p += 1; // 練習3
		//}
		//else {
		//	printf("あいこだ！\n\n");
		//	continue; // 練習4
		//}

		printf("あなた %d勝 ぼく %d勝\n\n", win_p, win_c);

		if (win_c == 2) {
			printf("この勝負！ぼくの勝ち！\n");
			break; // 練習5
		}
		else if (win_p == 2) {
			printf("この勝負、あなたの勝ち...\n");
			break; // 練習5
		}
	}
}
