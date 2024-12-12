#include "shooting_game_func.h"

int main() {
	int ypos_of = HEIGHT - 1;
	int xpos_of = WIDTH / 2;

	int move_of = 0;

	int ypos_ef = 1;
	int xpos_ef = 2;

	int move_ef = 1;

	int xpos_ob = -1;
	int ypos_ob = -1;

	int shoot_ob = 0;

	int xpos_eb = -1;
	int ypos_eb = -1;

	init_screen(WIDTH, HEIGHT);

	srand((unsigned int)time(NULL));

	printf("\x1b[?25l");

	while (1) {
		input_key(move_of, shoot_ob);

		updatePosFighter(xpos_of, move_of);

		if (xpos_ef == 1 || xpos_ef == WIDTH - 2) move_ef = -move_ef;

		updatePosFighter(xpos_ef, move_ef);

		if (shoot_ob == 1) {
			setPosBullet(ypos_of, xpos_of, ypos_ob, xpos_ob);
			shoot_ob = 0;
		}

		if ((rand() % 10) < 3) {
			setPosBullet(ypos_ef, xpos_ef, ypos_eb, xpos_eb);
		}

		updatePosBullet(ypos_ob, -1);

		updatePosBullet(ypos_eb, 1);

		if (checkCollision(ypos_of, xpos_of, ypos_eb, xpos_eb)) {
			break;
		}

		if (checkCollision(ypos_ef, xpos_ef, ypos_ob, xpos_ob)) {
			break;
		}

		updateScreen(ypos_of, xpos_of, ypos_ef, xpos_ef, ypos_ob, xpos_ob, ypos_eb, xpos_eb);

		Sleep(50);
	}
	return 0;
}
