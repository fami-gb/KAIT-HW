#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int main() {
	int dice = 0;
	int masu = 0;
	int cnt = 0;
	int trap1, trap2, trap3;
	int lucky1, lucky2;

	srand((unsigned int)time(NULL));

	while (1) {
		while (kbhit() == 0) {
			dice = rand() % 6 + 1;
			printf("\b%d", dice);
		}
		(void)scanf("%*c");
		printf("%dマス進む\n", dice);
		cnt++; // 試行回数
		masu += dice;
		printf("現在 %dマス目\n", masu);

		// ゴール判定
		if (masu >= 30) {
			printf("おめでとう！%d回でゴールしました！\n", cnt);
			break;
		}

		// トラップの設置
		trap1 = rand() % 30 + 1;
		trap2 = rand() % 30 + 1;
		trap3 = rand() % 30 + 1;

		// 幸運スポット設置
		lucky1 = rand() % 30 + 1;
		lucky2 = rand() % 30 + 1;
		
		// 以下幸運スポット
		if (masu == lucky1) {
			printf("古びたサイコロを発見した！\nあなたはもう一回サイコロを振れます！\n");

			// 再度サイコロを振る演出
			while (kbhit() == 0) {
				dice = rand() % 6 + 1;
				printf("\b%d", dice);
			}
			(void)scanf("%*c");
			printf("あなたはさらに%dマス進めます！\n", dice);
			masu += dice;

			printf("現在 %dマス目\n", masu);

			// 二回振った結果ゴールした場合
			if (masu >= 30) {
				printf("おめでとう！%d回でゴールしました！\n", cnt);
				break;
			}
			continue;
		}
		if (masu == lucky2) {
			dice = rand() % 15 + 1; // 1～15マス進める。
			printf("あなたは道中で優しいおじさんにトラックに乗せてもらった！\n%dマス進んだ！\n", dice);
			masu += dice;
			printf("現在 %dマス目\n", masu);
			
			// 進んだ結果ゴールした場合
			if (masu >= 30) {
				printf("おめでとう！%d回でゴールしました！\n", cnt);
				break;
			}
			continue;
		}

		// 以下トラップ
		if (masu == trap1) {
			printf("ざんねん！！あなたは罠に落ちてスタートに戻されました！WW\n");
			masu = 0;
			continue;
		}
		if (masu == trap2) {
			printf("あなたはアリを踏んだので地獄に落ちてしまった！\n");
			masu = -100;
			printf("現在 %dマス目\n", masu);
			continue;
		}
		if (masu == trap3) {
			printf("あなたは蜘蛛の巣に引っかかって足止めをくらってしまった！\n一回休み！\n");
			cnt++;
			continue;
		}
	}
}
