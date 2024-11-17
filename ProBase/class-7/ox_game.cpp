#include<stdio.h>

bool isValid(int gx, int gy, int num);
bool isDraw(int marked[3][3]);

int main() {
	int marked[3][3] = { 0 };
	int turn = 0;
	int gx, gy;
	int x, y;
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

		// 勝敗判定の別解
		// 縦または横の値の積が1ならばoの勝ち(1*1*1)
		// 同様に値の積が8ならばxの勝ち(2*2*2)
		// 配列の値に0が含まれてなければ、引き分けの判定も出来そう

		if (winner > 0) {
			printf("\x1b[10;1H");
			printf("%sの勝ち\n", ox[winner]);
			break;
		}

		// チャレンジ3
		if (isDraw(marked)) {
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
			// チャレンジ1, 2
			if (!isValid(gx, gy, marked[gy][gx])) continue;
			marked[gy][gx] = 1;
		}
		else {
			printf("\x1b[10;1H");
			printf("xの番です。マス目を指定してください：");
			(void)scanf("%c, %d", &c, &gx);
			rewind(stdin);
			gy = c - 97;
			gx--;
			// チャレンジ1, 2
			if (!isValid(gx, gy, marked[gy][gx])) continue;
			marked[gy][gx] = 2;
		}

		turn++;

	}

	return 0;
}

bool isValid(int gx, int gy, int num) {
	// return falseでもいいが、それだと三つすべてのバリデートが出来ないためフラグで管理する
	bool result1 = true;
	bool result2 = true;
	bool result3 = true;
	if (!(gx >= 0 && gx <= 2)) {
		printf("0か1か2を入力してください\n");
		result1 = false;
	}
	if (!(gy >= 0 && gy <= 2)) {
		printf("aかbかcを入力してください\n");
		result2 = false;
	}
	// num != 0だとmarkedの範囲外にアクセスした際にも通ってしまう。
	if (num == 1 || num == 2) {
		printf("既に入力されているマスです\n");
		result3 = false;
	}
	return result1 && result2 && result3;
}

bool isDraw(int marked[3][3]) {
	// マス全てが埋まってない場合は即リターン
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (marked[y][x] == 0) {
				return false;
			}
		}
	}
	return true;
}
