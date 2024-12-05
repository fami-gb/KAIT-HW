#include<stdio.h>

int main() {
	int marked[3][3] = { 0 };
	int turn = 0;
	int gx, gy;
	int x, y;
	int markedCounter = 0; // 引き分け用のカウンター
	int winner = 0;
	char c;

	const char* grid_line[8][8] = {
		{ "　", "　", "１", "　", "２", "　", "３", "　" },
		{ "　", "┌", "─", "┬", "─", "┬", "─", "┐" },
		{ "a",  "│", "　", "│", "　", "│", "　", "│" },
		{ "　", "├", "─", "┼", "─", "┼", "─", "┤" },
		{ "b",  "│", "　", "│", "　", "│", "　", "│" },
		{ "　", "├", "─", "┼", "─", "┼", "─", "┤" },
		{ "c",  "│", "　", "│", "　", "│", "　", "│" },
		{ "　", "└", "─", "┴", "─", "┴", "─", "┘" }
	};

	const char* ox[] = { "", "●", "x" };

	while (1) {
		markedCounter = 0;
		printf("\x1b[2J");

		// 練習1
		for (y = 0; y < 8; y++) {
			// 練習2
			for (x = 0; x < 8; x++) {
				printf("\x1b[%d;%dH", y + 1, 2 * x + 1);
				printf("%s", grid_line[y][x]);
			}
		}

		// 練習3
		for (y = 0; y < 3; y++) {
			// 練習4
			for (x = 0; x < 3; x++) {
				printf("\x1b[%d;%dH", 2 * y + 3, 4 * x + 5);
				// 練習5
				//printf("%d", marked[y][x]);
				printf("%s", ox[marked[y][x]]); // 発展7
				// マス目がすべて埋まっているか確認する
				if (marked[y][x] != 0) markedCounter++;
			}
		}

		// (1, 1) ~ (1, 3)揃う
		if (marked[0][0] == 1 && marked[0][1] == 1 && marked[0][2] == 1) winner = 1;
		else if (marked[0][0] == 2 && marked[0][1] == 2 && marked[0][2] == 2) winner = 2;

		// (2, 1) ~ (2, 3)揃う
		if (marked[1][0] == 1 && marked[1][1] == 1 && marked[1][2] == 1) winner = 1;
		else if (marked[1][0] == 2 && marked[1][1] == 2 && marked[1][2] == 2) winner = 2;

		// (3, 1) ~ (3, 3)揃う
		if (marked[2][0] == 1 && marked[2][1] == 1 && marked[2][2] == 1) winner = 1;
		else if (marked[2][0] == 2 && marked[2][1] == 2 && marked[2][2] == 2) winner = 2;

		// (1, 1) ~ (3, 1)揃う
		if (marked[0][0] == 1 && marked[1][0] == 1 && marked[2][0] == 1) winner = 1;
		else if (marked[0][0] == 2 && marked[1][0] == 2 && marked[2][0] == 2) winner = 2;

		// (1, 2) ~ (3, 2)揃う
		if (marked[0][1] == 1 && marked[1][1] == 1 && marked[2][1] == 1) winner = 1;
		else if (marked[0][1] == 2 && marked[1][1] == 2 && marked[2][1] == 2) winner = 2;

		// (1, 3) ~ (3, 3)揃う
		if (marked[0][2] == 1 && marked[1][2] == 1 && marked[2][2] == 1) winner = 1;
		else if (marked[0][2] == 2 && marked[1][2] == 2 && marked[2][2] == 2) winner = 2;

		// 右斜め下
		if (marked[0][0] == 1 && marked[1][1] == 1 && marked[2][2] == 1) winner = 1;
		else if (marked[0][0] == 2 && marked[1][1] == 2 && marked[2][2] == 2) winner = 2;

		// 左斜め下
		if (marked[0][2] == 1 && marked[1][1] == 1 && marked[2][0] == 1) winner = 1;
		else if (marked[0][2] == 2 && marked[1][1] == 2 && marked[2][0] == 2) winner = 2;
		
		if (winner > 0) {
			printf("\x1b[10;1H");
			printf("%sの勝ち", ox[winner]);
			break;
		}

		// チャレンジ3
		if (markedCounter == 9) {
			printf("\x1b[10;1H");
			printf("引き分けです\n");
			break;
		}

		// 練習6
		if (turn % 2 == 0) {
			printf("\x1b[10;1H");
			printf("●の番です。マス目を指定してください：");
			(void)scanf("%c, %d", &c, &gx);
			rewind(stdin);
			gy = c - 97;
			gx--;
			// チャレンジ1
			if (marked[gy][gx] == 1 || marked[gy][gx] == 2) {
				printf("既に入力されているマスです\n");
				continue;
			}
			// チャレンジ2
			if (!(gx >= 0 && gx <= 2)) {
				printf("0か1か2を入力してください\n");
				continue;
			}
			if (!(gy >= 0 && gy <= 2)) {
				printf("aかbかcを入力してください\n");
				continue;
			}
			marked[gy][gx] = 1;
		}
		else {
			printf("\x1b[10;1H");
			printf("xの番です。マス目を指定してください：");
			(void)scanf("%c, %d", &c, &gx);
			rewind(stdin);
			gy = c - 97;
			gx--;
			// チャレンジ1
			if (marked[gy][gx] == 1 || marked[gy][gx] == 2) {
				printf("既に入力されているマスです\n");
				continue;
			}
			// チャレンジ2
			if (!(gx >= 0 && gx <= 2)) {
				printf("0か1か2を入力してください\n");
				continue;
			}
			if (!(gy >= 0 && gy <= 2)) {
				printf("aかbかcを入力してください\n");
				continue;
			}
			marked[gy][gx] = 2;
		}

		turn++;

	}

	return 0;
}
