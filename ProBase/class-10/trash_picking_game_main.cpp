#include"trash_picking_game_func.h"

int main() {
	int xpos = 1;
	int ypos = 1;
	int fig = 0;
	int trash_map[HEIGHT][WIDTH] = { 0 };

	init_screen(WIDTH, HEIGHT+2);
	srand((unsigned int)time(NULL));

	printf("\x1b[?25l");

	start_time();
	while (1) {
		printf("\x1b[2J");
		input_key(ypos, xpos, fig);
		walk_baltan(ypos, xpos, fig);
		throw_out_trash(trash_map);
		print_trash(trash_map);
		int trash_count = check_trash_picking(ypos, xpos, trash_map);
		print_score(trash_count);
		if (print_remaining_time() == true) break;

		Sleep(100);
	}

	wait_to_push_esc_key();


	printf("\x1b[?25l");
	return 0;
}
