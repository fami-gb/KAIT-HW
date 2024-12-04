#include"trash_picking_game_func.h"

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

void input_key(int& ypos, int& xpos, int& figure) {
	// 224 && 十字キー
	if (kbhit() != 0) {
		int key = getch();
		if (key == 224) {
			key = getch();
			if (key == 75) {
				xpos--;
				if (xpos < 1) xpos = 1;
			}
			if (key == 77) {
				xpos++;
				if (xpos > WIDTH - 6) xpos = WIDTH - 6;
			}
			if (key == 72) {
				ypos--;
				if (ypos < 1) ypos = 1;
			}
			if (key == 80) {
				ypos++;
				if (ypos > HEIGHT - 2) ypos = HEIGHT - 2;
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
	static double lap_old = 0.0;
	double lap = get_time();

	if (lap - lap_old < INTERVAL) return false;
	lap_old = lap;
	return true;
}

void start_time() {
	get_time();
}

double get_time() {
	static clock_t start_time = 0;
	if (start_time == 0) start_time = clock();
	clock_t cur_time = clock();
	return static_cast<double>(cur_time - start_time) / CLOCKS_PER_SEC;
}

// 練習7
void throw_out_trash(int map[HEIGHT][WIDTH]) {
	if (check_interval_time() == false) return;
	int xp = rand() % (WIDTH - 1); // 練習10
	int yp = rand() % (HEIGHT - 1); // 練習11
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
int check_trash_picking(int ypos, int xpos, int map[HEIGHT][WIDTH]) {
	static int trash_count = 0;
	for (int y = ypos; y < ypos + 3; y++) {
		for (int x = xpos + 2; x < xpos + 5; x++) {
			if (map[y - 1][x - 1] == 1) {
				map[y - 1][x - 1] = 0;
				trash_count++;
				PlaySoundA("sound.wav", NULL, SND_FILENAME | SND_ASYNC);
			}
		}
	}
	return trash_count;
}

//void print_remaining_time() {
//	printf("\x1b[%d;1H", HEIGHT + 1);
//	for (int i = 0; i < WIDTH; i++) printf("-");
//	double r_time = LIMIT_TIME - get_time();
//	printf("\x1b[%d;1H", HEIGHT + 2);
//	printf("残り時間: %5.2lf秒", r_time);
//}

bool print_remaining_time() {
	printf("\x1b[%d;1H", HEIGHT + 1);
	for (int i = 0; i < WIDTH; i++) printf("-");
	double r_time = LIMIT_TIME - get_time();
	printf("\x1b[%d;1H", HEIGHT + 2);
	printf("残り時間: %5.2lf秒", r_time);
	if (r_time <= 0.0) return true;
	return false;
}

void wait_to_push_esc_key() {
	while (1) {
		if (kbhit() == true) {
			if (getch() == 27) break;
		}
	}
}

void print_score(int score) {
	printf("\x1b[%d;20H", HEIGHT + 2);
	printf("SCORE: %d個", score);
}
