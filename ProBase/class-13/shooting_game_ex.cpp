#include"ShootingGameClassEx.h"
#include"shooting_game_func.h"

int main() {
	OwnFighter own_fighter(HEIGHT - 1, WIDTH / 2, "---");
	EnemyFighter enemy_fighter(2, 1, "=====");

	ShootingGameEx sg(own_fighter, enemy_fighter);

	init_screen(WIDTH, HEIGHT);

	sg.run();

	sg.ending();

	return 0;
}
