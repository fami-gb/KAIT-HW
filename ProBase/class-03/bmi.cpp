#include<stdio.h>

int main() {
	float shincho, taiju, action, rcmd_cal1, rcmd_cal2, taiju_best, himan_do, BMI;

	printf("身長を入力してください[m]：");
	(void)scanf("%f", &shincho);
	printf("体重を入力してください[kg]：");
	(void)scanf("%f", &taiju);
	printf("あなたの普段の活動を入力してください。(軽度な活動:1, 中程度の活動:2, 重い活動:3, 重労働:4)：");
	(void)scanf("%f", &action);

	BMI = taiju / (shincho * shincho);
	taiju_best = shincho * shincho * 22;
	himan_do = ((taiju - taiju_best) / taiju_best) * 100;

	printf("BMI値は\x1b[4m%.2f\x1b[0mです。\n", BMI);
	printf("あなたの適正体重は\x1b[4m%.2fkg\x1b[0mです。\n", taiju_best);
	printf("あなたの肥満度は\x1b[4m%.2f%%\x1b[0mです。\n", himan_do);

	printf("BMI値から見ると\nあなたは、");
	if (BMI < 18.5) {
		printf("\x1b[94m");
		printf("やせています。\n");
	}
	else if (18.5 <= BMI && BMI < 25.0) {
		printf("ふつうです。\n");
	}
	else if (25.0 <= BMI && BMI < 30.0) {
		printf("\x1b[91m");
		printf("太りぎみです。\n");
	}
	else if (30.0 <= BMI && BMI < 35.0) {
		printf("\x1b[91m");
		printf("太っている。\n");
	}
	else if (35.0 <= BMI && BMI < 40.0) {
		printf("\x1b[91m");
		printf("太りすぎ。\n");
	}
	else if (40.0 <= BMI && BMI < 45.0) {
		printf("\x1b[91m");
		printf("かなり太りすぎ");
	}
	printf("\x1b[0m"); // 文字色リセット

	printf("肥満度から見ると\nあなたは、");
	if (himan_do < -10) {
		printf("\x1b[94m");
		printf("やせています。\n");
	}
	else if (-10 <= himan_do && himan_do < 10) {
		printf("普通です。\n");
	}
	else if (10 <= himan_do && himan_do < 20) {
		printf("\x1b[91m");
		printf("太っています。\n");
	}
	else if (himan_do >= 20) {
		printf("\x1b[91m");
		printf("肥満です。\n");
	}
	printf("\x1b[0m"); // 文字色リセット

	switch ((int)action) {
	case 1:
		rcmd_cal1 = 20 * taiju_best;
		rcmd_cal2 = 30 * taiju_best;
		printf("あなたの活動に対する一日の摂取カロリーの目安は%.2f~%.2fkcalです。\n", rcmd_cal1, rcmd_cal2);
		break;
	case 2:
		rcmd_cal1 = 30 * taiju_best;
		rcmd_cal2 = 35 * taiju_best;
		printf("あなたの活動に対する一日の摂取カロリーの目安は%.2f~%.2fkcalです。\n", rcmd_cal1, rcmd_cal2);
		break;
	case 3:
		rcmd_cal1 = 35 * taiju_best;
		rcmd_cal2 = 40 * taiju_best;
		printf("あなたの活動に対する一日の摂取カロリーの目安は%.2f~%.2fkcalです。\n", rcmd_cal1, rcmd_cal2);
		break;
	case 4:
		rcmd_cal1 = 40 * taiju_best;
		printf("あなたの活動に対する一日の摂取カロリーの目安は%.2fkcal以上です。\n", rcmd_cal1);
		break;
	}

	return 0;
}
