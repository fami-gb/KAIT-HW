#include<stdio.h>

void print_title();
float input_value(const char* str);
void cal_bmi(float shincho, float taiju);
float cal_best_taiju(float shincho);

// チャレンジ1
float cal_himan_do(float taiju, float best);
// チャレンジ2
void check_himan(float himan_do);

int main() {
	print_title();
	float shincho = input_value("身長を入力してください[m]：");
	float taiju = input_value("体重を入力してください[kg]：");
	cal_bmi(shincho, taiju);
	float best_taiju = cal_best_taiju(shincho);
	//チャレンジ用
	float himan_do = cal_himan_do(taiju, best_taiju);
	printf("あなたの肥満度は%4.1f%%です。\n", himan_do);
	check_himan(himan_do);

	return 0;
}

void print_title() {
	printf("==============================\n");
	printf("===あなたの肥満度を測ります===\n");
	printf("==============================\n");
}

float input_value(const char* str) {
	float val;
	printf("%s", str);
	(void)scanf("%f", &val);
	rewind(stdin);
	return val;
}

void cal_bmi(float shincho, float taiju) {
	float bmi = taiju / (shincho * shincho);
	printf("BMIは、%4.1f です\n", bmi);
}

// 練習1, 2, 3, 4
float cal_best_taiju(float shincho) {
	float best = (shincho * shincho) * 22;
	printf("適正体重は、%4.1f[kg]です\n", best);
	return best;
}

float cal_himan_do(float taiju, float best) {
	float himan_do = ((taiju - best) / best) * 100;
	return himan_do;
}

void check_himan(float himan_do) {
	printf("あなたは、");
	if (himan_do < -10) {
		printf("やせています");
	}
	else if (himan_do >= -10 && himan_do < 10) {
		printf("普通です");
	}
	else if (himan_do >= 10 && himan_do < 20) {
		printf("太っています");
	}
	else if (himan_do >= 20) {
		printf("肥満です");
	}
}
