#include<stdio.h>
#include<Windows.h>
#include<conio.h>

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

void input_key(int& ypos, int& xpos, int& fig);
void walk_baltan(int ypos, int xpos, int fig);

int main() {
	int xpos = 1;
	int ypos = 1;
	int fig = 0;

	printf("\x1b[?25l");

	while (1) {
		printf("\x1b[2J");
		input_key(ypos, xpos, fig);
		walk_baltan(ypos, xpos, fig);
		Sleep(10);
	}

	printf("\x1b[?25l");

	return 0;
}

void input_key(int& ypos, int& xpos, int& figure) {
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
			figure = (figure + 1) % 2;
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
