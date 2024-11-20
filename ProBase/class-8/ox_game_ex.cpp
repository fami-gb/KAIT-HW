#include<stdio.h>

#define CLS printf("\x1b[2J");
#define pos(y, x) printf("\x1b[%d;%dH", y, x);

void print_grid();
void print_marks(int marked[3][3]);
bool judge(int marked[3][3], int turn);
int input_marks(int marked[3][3], int turn);
// チャレンジ1, 2,3
bool isValid(int gx, int gy, int num);
bool isDraw(int multi[8]);

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

const char* ox[] = { "　", "●", "x" };

int main() {
	int marked[3][3] = { 0 };
	int turn = 0;

	while (1) {
		CLS;

		print_grid();

		print_marks(marked);

		if (judge(marked, turn)) break;

		input_marks(marked, turn);
	}

	return 0;
}

void print_grid() {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			pos(y + 1, 2 * x + 1);
			printf("%s", grid_line[y][x]);
		}
	}
}

void print_marks(int marked[3][3]) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			pos(2 * y + 3, 4 * x + 5);
			printf("%s", ox[marked[y][x]]);
		}
	}
}

bool judge(int marked[3][3], int turn) {
	int multi[8];
	multi[0] = marked[0][0] * marked[0][1] * marked[0][2];
	multi[1] = marked[1][0] * marked[1][1] * marked[1][2];
	multi[2] = marked[2][0] * marked[2][1] * marked[2][2];
	multi[3] = marked[0][0] * marked[1][0] * marked[2][0];
	multi[4] = marked[0][1] * marked[1][1] * marked[1][1];
	multi[5] = marked[0][2] * marked[1][2] * marked[2][2];
	multi[6] = marked[0][0] * marked[1][1] * marked[2][2];
	multi[7] = marked[0][2] * marked[1][2] * marked[2][0];

	int winner = 0;
	for (int i = 0; i < 8; i++) {
		// 練習1
		if (multi[i] == 1) winner = 1;
		// 練習２
		else if (multi[i] == 8) winner = 2;
	}
	if (winner > 0) {
		pos(10, 1);
		// 練習3
		printf("%sの勝ち", ox[winner]);
		return true;
	}
	if (isDraw(multi)) {
		pos(10, 1);
		printf("引き分けです");
		return true;
	}
	return false;
}

// 練習4
int input_marks(int marked[3][3], int turn) {
	int gy, gx;
	char c;

	pos(10, 1);
	printf("\x1b[K");
	printf("%sの番です。マス目を指定してください：", ox[turn % 2 + 1]);
	(void)scanf("%c,%d", &c, &gx);
	rewind(stdin);
	gy = c - 97;
	gx--;
	if (!isValid(gx, gy, marked[gy][gx])) {
		return turn;
	}
	marked[gy][gx] = turn % 2 + 1;
	turn++;
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

bool isDraw(int multi[8]) {
	// マス全てが埋まってない場合は即リターン
	for (int i = 0; i < 8; i++) {
		if (multi[i] == 0) return false;
	}
	return true;
}
