#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define WIDTH 80
#define HEIGHT 25
#define INTERVAL 1.0

const char* baltan[2][3][7] = {
	{
		{ " ", "Y", "o", "\\", "o", "Y", " " },
		{ " ", " ", " ", "w", " ", " ", " " },
		{ " ", " ", "|", " ", "|", " ", " " }
	},
	{
		{ " ", " ", "o", "\\", "o", " ", " " },
		{ ">", "-", " ", "w", " ", "-", "<" },
		{ " ", " ", "<", " ", ">", " ", " " }
	}
};

void input_key(int& ypos, int& xpos, int& figure);
void walk_baltan(int ypos, int xpos, int figure);
void init_screen(short width, short height);
bool check_interval_time();
void throw_out_trash(int map[HEIGHT][WIDTH]);
void print_trash(int map[HEIGHT][WIDTH]);
void check_trash_picking(int ypos, int xpos, int map[HEIGHT][WIDTH]);

int main() {
	int xpos = 1;
	int ypos = 1;
	int fig = 0;
	int trash_map[HEIGHT][WIDTH] = { 0 };
	
	init_screen(WIDTH, HEIGHT);
	srand((unsigned int)time(NULL));

	printf("\x1b[?25l");

	while (1) {
		printf("\x1b[2J");
		input_key(ypos, xpos, fig);
		walk_baltan(ypos, xpos, fig);
		throw_out_trash(trash_map);
		print_trash(trash_map);
		check_trash_picking(ypos, xpos, trash_map);

		Sleep(100);
	}

	printf("\x1b[?25l");
	return 0;
}

void input_key(int& ypos, int& xpos, int& figure) {
	// 224 && 十字キー
	if (kbhit() != 0) {
		int key = getch();
		if (key == 224) {
			key = getch();
			if (key == 75) {
				xpos--;
			}
			if (key == 77) {
				xpos++;
			}
			if (key == 72) {
				ypos--;
			}
			if (key == 80) {
				ypos++;
			}
			// figure = (figure + 1) % 2;
			figure ^= 1; // xorで0と1を切り替え
		}
	}
}

void walk_baltan(int ypos, int xpos, int figure) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 7; x++) {
			printf("\x1b[%d;%dH%s", ypos + y, xpos + x, baltan[figure][y][x]);
		}
	}
}

// 練習5
void init_screen(short width, short height) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT size = { 0, 0, width - 1, height - 1 };
	COORD coord = { width, height };
	SetConsoleWindowInfo(handle, TRUE, &size);
	SetConsoleScreenBufferSize(handle, coord);
}

// 練習6
bool check_interval_time() {
	// static: プログラムが終了するまで値が保持される
	static clock_t start_time = 0;
	static double lap_old = 0.0;
	if (start_time == 0)start_time = clock();
	clock_t cur_time = clock();
	double lap = static_cast<double>(cur_time - start_time) / CLOCKS_PER_SEC;

	if (lap - lap_old < INTERVAL) return false;
	lap_old = lap;
	return true;
}

// 練習7
void throw_out_trash(int map[HEIGHT][WIDTH]) {
	if (check_interval_time() == false) return;
	int xp = rand() % (WIDTH - 1) + 1; // 練習10
	int yp = rand() % (HEIGHT - 1) + 1; // 練習11
	map[yp][xp] = 1;
}

// 練習8
void print_trash(int map[HEIGHT][WIDTH]) {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (map[y][x] == 1) printf("\x1b[%d;%dH*", y + 1, x + 1);
		}
	}
}

// 練習9
void check_trash_picking(int ypos, int xpos, int map[HEIGHT][WIDTH]) {
	for (int y = ypos; y < ypos + 3; y++) {
		for (int x = xpos + 2; x < xpos + 5; x++) {
			if (map[y - 1][x - 1] == 1) {
				map[y - 1][x - 1] = 0;
			}
		}
	}
}
