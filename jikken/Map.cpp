#include "Map.h"
#include "DxLib.h"
#include "load_map.h"

static int map[32][40] = {};

void enemy_event() {};

int IsAbleToGo(int x, int y, int muki) {//進めるかを判定する
	if (muki == 0){//上向きなら
		if (map[y / 32 - 1][x / 32] == 1) //進めるか判定
			return 1;//エラー
		else if (map[y / 32 - 1][x / 32] == 2) {
			enemy_event(); //進む先のmap[][]==2のとき、enemyとのイベント発生の関数呼び出し
			return 1;
		}
		}
	if (muki == 1){//左向きなら
		if (map[y / 32][x / 32 - 1] == 1) {
			return 1;
		}
		else if (map[y / 32][x / 32 - 1] == 2) {
			enemy_event(); //進む先のmap[][]==2のとき、enemyとのイベント発生の関数呼び出し
			return 1;
		}
		}
	if (muki == 2){//下向きなら
		if (map[y / 32 + 1][x / 32] == 1) {
			return 1;
		}
		else if (map[y / 32 + 1][x / 32] == 2) {
			enemy_event(); //進む先のmap[][]==2のとき、enemyとのイベント発生の関数呼び出し
			return 1;
		}
		}
	if (muki == 3){//右向きなら
		if (map[y / 32][x / 32 + 1] == 1) {
			return 1;
		}
		else if (map[y / 32][x / 32 + 1] == 2) {
			enemy_event(); //進む先のmap[][]==2のとき、enemyとのイベント発生の関数呼び出し
			return 1;
		}
		}
	return 0;//正常


}


void Map_Draw() {
	for (int i = 0; i < 32; i++)
		for (int j = 0; j < 40; j++)
			if (map[i][j] == 1)
				DrawBox(j * 32, i * 32, (j + 1) * 32, (i + 1) * 32, GetColor(255, 255, 255), TRUE);
			else if(map[i][j] == 2)
				DrawBox(j * 32, i * 32, (j + 1) * 32, (i + 1) * 32, GetColor(0, 255, 0), TRUE);
			else if (map[i][j] == 3)
				DrawBox(j * 32, i * 32, (j + 1) * 32, (i + 1) * 32, GetColor(255, 0, 0), TRUE);
}

void load_map(int player_id) {
	int i = 0, j = 0;
	FILE *fp;
	char *filename = "map.txt";
	char buf[200], *p, *end;
	printf("player_id:%d\n", player_id);
	fopen_s(&fp, filename, "r");
	/*if (fp == NULL) {
		printf("error/n");
		fclose(fp);
		return;
	}*/

	for (i = 0; i < 32; i++) {
		fgets(buf, sizeof(buf), fp);
		char *ctx;
		p = strtok_s(buf, ",", &ctx);
		while (p = strtok_s(NULL, ",", &ctx)) {
			map[i][j] = atoi(p);
			j++;
		}
		j = 0;
	}
	fclose(fp);
}



