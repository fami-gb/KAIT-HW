#include<stdio.h>

int main() {
	//printf("\x1b[2j");

	//printf("\x1b[1;H");
	//printf("┌");
	//printf("\x1b[1;3H");
	//printf("─");
	//printf("\x1b[1;5H");
	//printf("┬");
	//printf("\x1b[1;7H");
	//printf("─");
	//printf("\x1b[1;9H");
	//printf("┬");
	//printf("\x1b[1;11H");
	//printf("─");
	//printf("\x1b[1;13H");
	//printf("┐");

	//// 練習1
	//// 二行目
	//printf("\n");

	//printf("\x1b[2;H");
	//printf("│");
	//printf("\x1b[2;3H");
	//printf(" ");
	//printf("\x1b[2;5H");
	//printf("│");
	//printf("\x1b[2;7H");
	//printf(" ");
	//printf("\x1b[2;9H");
	//printf("│");
	//printf("\x1b[2;11H");
	//printf(" ");
	//printf("\x1b[2;13H");
	//printf("│");

	//// 三行目
	//printf("\n");

	//printf("\x1b[3;H");
	//printf("├");
	//printf("\x1b[3;3H");
	//printf("─");
	//printf("\x1b[3;5H");
	//printf("┼");
	//printf("\x1b[3;7H");
	//printf("─");
	//printf("\x1b[3;9H");
	//printf("┼");
	//printf("\x1b[3;11H");
	//printf("─");
	//printf("\x1b[3;13H");
	//printf("┤");

	//// 四行目
	//printf("\n");

	//printf("\x1b[4;H");
	//printf("│");
	//printf("\x1b[4;3H");
	//printf(" ");
	//printf("\x1b[4;5H");
	//printf("│");
	//printf("\x1b[4;7H");
	//printf(" ");
	//printf("\x1b[4;9H");
	//printf("│");
	//printf("\x1b[4;11H");
	//printf(" ");
	//printf("\x1b[4;13H");
	//printf("│");

	//// 五行目
	//printf("\n");

	//printf("\x1b[5;H");
	//printf("├");
	//printf("\x1b[5;3H");
	//printf("─");
	//printf("\x1b[5;5H");
	//printf("┼");
	//printf("\x1b[5;7H");
	//printf("─");
	//printf("\x1b[5;9H");
	//printf("┼");
	//printf("\x1b[5;11H");
	//printf("─");
	//printf("\x1b[5;13H");
	//printf("┤");

	//// 六行目
	//printf("\n");

	//printf("\x1b[6;H");
	//printf("│");
	//printf("\x1b[6;3H");
	//printf(" ");
	//printf("\x1b[6;5H");
	//printf("│");
	//printf("\x1b[6;7H");
	//printf(" ");
	//printf("\x1b[6;9H");
	//printf("│");
	//printf("\x1b[6;11H");
	//printf(" ");
	//printf("\x1b[6;13H");
	//printf("│");

	//// 七行目
	//printf("\n");

	//printf("\x1b[7;H");
	//printf("└");
	//printf("\x1b[7;3H");
	//printf("─");
	//printf("\x1b[7;5H");
	//printf("┴");
	//printf("\x1b[7;7H");
	//printf("─");
	//printf("\x1b[7;9H");
	//printf("┴");
	//printf("\x1b[7;11H");
	//printf("─");
	//printf("\x1b[7;13H");
	//printf("┘");

// 練習2
	const char* grid_line[7][7] = {
		{ "┌", "─", "┬", "─", "┬", "─", "┐" },
		{ "│", "　", "│", "　", "│", "　", "│" },
		{ "├", "─", "┼", "─", "┼", "─", "┤" },
		{ "│", "　", "│", "　", "│", "　", "│" },
		{ "├", "─", "┼", "─", "┼", "─", "┤" },
		{ "│", "　", "│", "　", "│", "　", "│" },
		{ "└", "─", "┴", "─", "┴", "─", "┘" }
	};

	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 7; x++) {
			printf("\x1b[%d;%dH", y+1, 2*x+1);
			printf("%s", grid_line[y][x]);
		}
	}

	return 0;
}
