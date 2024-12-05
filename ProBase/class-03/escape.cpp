#include<stdio.h>
#include<WIndows.h>

int main() {
	printf("\x1b[2J"); // テキストクリア
	printf("\x1b[?25l"); // カーソル非表示
	printf("\x1b[91m"); // 文字色を明るい赤

	int i;

	for (i = 0; i < 100; i++) {
		printf("\x1b[1;%dH", i);
		printf("●");
		Sleep(10);
		printf("\x1b[1;%dH", i);
		printf("\x1b[2P"); // 2文字削除
	}
	printf("\x1b[1;%dH", i);
	printf("●");

	printf("\x1b[0m"); // 文字色をリセット
	printf("\x1b[?25h"); // カーソルを表示

	// 練習1
	printf("\x1b[2J");
	printf("\x1b[?25l");
	printf("\x1b[35m"); // 文字色変更(赤紫)

	for (i = 0; i < 100; i++) {
		printf("\x1b[1;%dH", i);
		printf("●");
		Sleep(10);
		printf("\x1b[1;%dH", i);
		printf("\x1b[2P");
	}
	printf("\x1b[1;%dH", i);
	printf("●");

	printf("\x1b[0m");
	printf("\x1b[?25h");

	// 練習2
	printf("\x1b[2J");
	printf("\x1b[?25l");
	printf("\x1b[91m");

	for (i = 0; i < 100; i++) {
		printf("\x1b[1;%dH", i);
		printf("●");
		Sleep(10);
		printf("\x1b[1;%dH", i);
		printf("\x1b[2P");
	}
	printf("\x1b[1;%dH", i);
	printf("●");

	// 球が戻るやつを追加
	for (i = 100; i >= 0; i--) {
		printf("\x1b[1;%dH", i);
		printf("●");
		Sleep(100);
		printf("\x1b[1;%dH", i);
		printf("\x1b[2P");
	}
	printf("\x1b[1;1H");
	printf("●");

	printf("\x1b[0m");
	printf("\x1b[?25h");
	printf("\x1b[2J"); // テキストクリア

	// 練習3
	// 色の種類で分岐
	int color;
	printf("ボールの色を選択してください(1:赤, 2:緑, 3:黄, 4:青, 5:赤紫, 6:水色, 7:白)：");
	(void)scanf("%d", &color);
	rewind(stdin);

	switch (color) {
	case 1:
		printf("\x1b[91m"); // 明るい赤
		break;
	case 2:
		printf("\x1b[92m"); // 明るい緑
		break;
	case 3:
		printf("\x1b[93m"); // 明るい黄
		break;
	case 4:
		printf("\x1b[94m"); //明るい青
		break;
	case 5:
		printf("\x1b[95m"); //明るい赤紫
		break;
	case 6:
		printf("\x1b[96m"); // 明るい水色
		break;
	case 7:
		printf("\x1b[97m"); // 明るい白
		break;
	default:
		printf("\x1b[0m"); // リセット
		break;
	}

	printf("\x1b[2J");
	printf("\x1b[?25l");
	//printf("\x1b[91m");

	for (i = 0; i < 100; i++) {
		printf("\x1b[1;%dH", i);
		printf("●");
		Sleep(10);
		printf("\x1b[1;%dH", i);
		printf("\x1b[2P");
	}
	printf("\x1b[1;%dH", i);
	printf("●");

	printf("\x1b[0m");
	printf("\x1b[?25h");

	return 0;
}
