#include "shooting_game_func.h"

const char* own_fighter = "_|_";
const char* enemy_fighter = "===";
const char* own_bullet = "|";
const char* enemy_bullet = "$";

void init_screen(short width, short height) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT size = { 0, 0, width - 1, height - 1 };
	COORD coord = { width, height };
	SetConsoleWindowInfo(handle, TRUE, &size);
	SetConsoleScreenBufferSize(handle, coord);
}

void input_key(int& move, int& shoot) {
	move = 0;
	if (kbhit() != 0) {
		int key = getch();
		if (key == 32) shoot = 1;
		if (key == 224) {
			key = getch();
			if (key == 75) {
				move = -1; // 練習2
			}
			if (key == 77) {
				move = 1; // 練習3
			}
		}
	}
}

void updatePosFighter(int& xpos, int move) {
	xpos += move;
	if (xpos < 1) xpos = 1; // 練習4
	if (xpos > WIDTH - 2) xpos = WIDTH - 2; // 練習5

}

void setPosBullet(int ypos_f, int xpos_f, int& ypos_b, int& xpos_b) {
	if (ypos_b < 0) {
		xpos_b = xpos_f + 1;
		ypos_b = ypos_f;
	}
}

void updatePosBullet(int& ypos, int move) {
	if (ypos > 0) ypos += move;
	if (ypos > HEIGHT || ypos < 1) ypos = -1;
}

bool checkCollision(int ypos_f, int xpos_f, int ypos_b, int xpos_b) {
	if (ypos_f == ypos_b && xpos_f <= xpos_b && xpos_f + 2 >= xpos_b) return true;
	return false;
}

void updateScreen(int ypos_of, int xpos_of, int ypos_ef, int xpos_ef, int ypos_ob, int xpos_ob, int ypos_eb, int xpos_eb) {
	printf("\x1b[2J");
	printf("\x1b[%d;%dH", ypos_of, xpos_of);
	printf("%s", own_fighter);
	printf("\x1b[%d;%dH", ypos_ef, xpos_ef);
	printf("%s", enemy_fighter);
	if (ypos_ob > 0) {
		printf("\x1b[%d;%dH", ypos_ob, xpos_ob);
		printf("%s", own_bullet);
	}
	if (ypos_eb > 0) {
		printf("\x1b[%d;%dH", ypos_eb, xpos_eb);
		printf("%s", enemy_bullet);
	}
}
