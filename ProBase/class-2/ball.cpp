#include<stdio.h>
#include<Windows.h>

int main() {
	int i;

	// 例題
	for (i = 0; i < 50; i++)
	{
		printf("o");
		Sleep(100);
		printf("\b ");
	}
	printf("o\n");

	// 練習1
	for (i = 0; i < 200; i++)
	{
		printf("o");
		Sleep(100);
		printf("\b ");
	}
	printf("o\n");

	// 練習2
	for (i = 0; i < 200; i++)
	{
		printf("o");
		Sleep(10);
		printf("\b ");
	}
	printf("o\n");

	// 練習3
	for (i = 0; i < 66; i++)
	{
		printf("===");
		Sleep(100);
		printf("\b\b\b   ");
	}
	printf("===\n");

	// 練習4
	for (i = 0; i < 39; i++)
	{
		printf("abcde");
		Sleep(100);
		printf("\b\b\b\b\b     ");
	}
	printf("abcde\n");

	// 練習5
	for (i = 0; i < 100; i++)
	{
		printf("●");
		Sleep(100);
		printf("\b\b　");
	}
	printf("●\n");

	// 練習6
	for (i = 0; i < 28; i++)
	{
		printf("名前");
		Sleep(100);
		printf("\b\b\b\b\b\b　　　");
	}
	printf("名前\n");

	// 番外編
	for (i = 200; i > 0; i--) {
		printf("\033[0;%dH", i); // カーソルの位置をデクリメント
		printf("o");
		Sleep(100);
		printf("\b "); // o消す用
	}
	printf("o\n");

	for (i = 0; i < 100; i++) {
		printf("\x1b[1;%dH", i);
		printf("o");
		Sleep(100);
		printf("\x1b[1;%dH", i);
		printf("\b ");
	}
	printf("\x1b[1;%dH", i);

	return 0;
}
