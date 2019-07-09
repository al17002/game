#include "Map.h"
#include "stdlib.h"
#include "DxLib.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "Savedata.h"
#include "SceneMgr.h"
#include "hitJudgment.h"
#include "time.h"
static int image[16];

static int image_floor;
static int image_item;
static int map[32][40] = {};
int map_sur[32][40] = {};
static int current_map = 1;

//階層の更新
void floor_renew(int map_id) {
	load_map(map_id);
	EnemyMgr_Finalize();
	Player_Finalize();
	clearHitbox();
	EnemyMgr_Initialize();
	Player_Initialize();
}

//アイテムイベントの発生
void item_event(int n) {
	add_item(n);
}

//敵の座標を計算する
void calcenemy(int *x, int *y) {
	bool check = true;
	int tx, ty;
	srand((unsigned)time(NULL));
	tx = rand() % 39;
	ty = rand() % 31;
	while (check){
		if (map[ty][tx]==0) {
			map[ty][tx] = -1;
			*x = tx*32;
			*y = ty*32;
			check = false;
		}
		else {
			tx = rand() % 39;
			ty = rand() % 31;
		}
	}	
	check = true;
}
void floor_event(int n) {
	if (n == 3) {
		current_map++;
		if (current_map < 3) {
			floor_renew(current_map);
		}
		else {//clear
			SceneMgr_ChangeScene(eScene_Win);
			current_map = 1;
		}
	}
}
//進めるかを判定する
int IsAbleToGo(int x, int y, int muki,bool player) {
	if (muki == 0) {//上向きなら
		if (map[y / 32 - 1][x / 32] == 1){ 
			return 1;//壁
		}
		else if (map[y / 32 - 1][x / 32] <= 9 && map[y / 32 - 1][x / 32] >= 2) {
			if (player) {//進む先の2<=map[][]=<9のとき、floor_event関数呼び出し
				floor_event(map[y / 32 - 1][x / 32]); 
			}
			return 0;
		}
		else if (map[y / 32 - 1][x / 32] >= 10) {
			if (player) {//進む先のmap[][]>=10のとき、item_event関数呼び出し
				if (player) {
					item_event(map[y / 32 - 1][x / 32]);
					map[y / 32 - 1][x / 32] = 0;
				}
			}
			return 0;
		}
	}
	if (muki == 1) {//左向きなら
		if (map[y / 32][x / 32 - 1] == 1) {
			return 1;
		}
		else if (map[y / 32][x / 32 - 1] <= 9 && map[y / 32][x / 32 - 1] >= 2) {
			if (player) {
				floor_event(map[y / 32][x / 32 - 1]);
			}
			return 0;
		}
		else if (map[y / 32 ][x / 32 - 1] >= 10) {
			if (player) {
				item_event(map[y / 32][x / 32 - 1]);
				map[y / 32][x / 32 - 1] = 0;
			}
			return 0;
		}
	}

	if (muki == 2) {//下向きなら
		if (map[y / 32 + 1][x / 32] == 1) {
			return 1;
		}
		else if (map[y / 32 + 1][x / 32] <= 9 && map[y / 32 + 1][x / 32] >= 2) {
			if (player) {
				floor_event(map[y / 32 + 1][x / 32]);
			}
			return 0;
		}
		else if (map[y / 32 + 1][x / 32] >= 10) {
			if (player) {
				item_event(map[y / 32 + 1][x / 32]);
				map[y / 32 + 1][x / 32] = 0;
			}
			return 0;
		}
	}
	if (muki == 3) {//右向きなら
		if (map[y / 32][x / 32 + 1] == 1) {
			return 1;
		}
		else if (map[y / 32][x / 32 + 1] <= 9 && map[y / 32][x / 32 + 1] >= 2) {
			if (player) {
				floor_event(map[y / 32][x / 32 + 1]);
			}
			return 0;
		}
		else if (map[y / 32][x / 32 + 1] >= 10) {
			if (player) {
				item_event(map[y / 32][x / 32 + 1]);
				map[y / 32][x / 32 + 1] = 0;
			}
			return 0;
		}
	}
	return 0;//正常
}
static int m_Image;
void Floor_Initialize() {
	image_floor=LoadGraph("画像/階段.png");
}
void Item_Initialize() {
	image_item = LoadGraph("画像/アイテム01.png");
}

//描画
void Map_Draw() {
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 40; j++) {
			if (map[i][j] == 1) {
				DrawBox(j * 32, i * 32, (j + 1) * 32, (i + 1) * 32, GetColor(111, 51, 16), TRUE);
			}
			else if(map[i][j] == 3){
				DrawGraph(j * 32, i * 32, image_floor, TRUE);
			}
			else if (map[i][j] >= 10) {
				DrawGraph(j * 32, i * 32, image_item, TRUE);
			}
		}
	}
	Map_Draw_Surround();
}
void Map_Draw_Surround() {
	for (int i = 0; i < 32; i++){
		for (int j = 0; j < 40; j++) {
			map_sur[i][j] = map[i][j];
			if (j >= player.x / 32 - 5 && j <= player.x / 32 + 5 && i >= player.y / 32 - 5 && i <= player.y / 32 + 5)
				;
			else {
				map_sur[i][j] = 2;
			}
			if (map_sur[i][j] == 2)
				DrawBox(j * 32, i * 32, (j - 1) * 32, (i - 1) * 32, GetColor(220, 220, 220), TRUE);
		}
	}
}

//マップの読み込み
void load_map(int map_id) {
	int i = 0, j = 0;
	FILE *fp;
	char *filename = "map.txt";
	switch (map_id) {
	case 1:
		filename = "map.txt";
		break;
	case 2:
		filename = "map2.txt";
		break;
	case 3:
		filename = "map.txt";
		break;
	default:
		filename = "map.txt";
		break;
	}
	char buf[200], *p;
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



