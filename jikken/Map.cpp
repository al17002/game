#include "Map.h"
#include "DxLib.h"

int hantei[15][20] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1 },
		{ 1,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1 },
		{ 1,0,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,1 },
		{ 1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};

int IsAbleToGo(int x, int y, int muki) {//進めるかを判定する
	if (muki == 0)//上向きなら
		if (hantei[y / 32 - 1][x / 32] == 1)//進めるか判定
			return 1;//エラー
	if (muki == 1)//左向きなら
		if (hantei[y / 32][x / 32 - 1] == 1)
			return 1;
	if (muki == 2)//下向きなら
		if (hantei[y / 32 + 1][x / 32] == 1)
			return 1;
	if (muki == 3)//右向きなら
		if (hantei[y / 32][x / 32 + 1] == 1)
			return 1;
	return 0;//正常
}

void Map_Draw() {
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 20; j++)
			if (hantei[i][j] == 1)
				DrawBox(j * 32, i * 32, (j + 1) * 32, (i + 1) * 32, GetColor(255, 255, 255), TRUE);
			else if(hantei[i][j] == 2)
				DrawBox(j * 32, i * 32, (j + 1) * 32, (i + 1) * 32, GetColor(0, 255, 0), TRUE);
			else if (hantei[i][j] == 3)
				DrawBox(j * 32, i * 32, (j + 1) * 32, (i + 1) * 32, GetColor(255, 0, 0), TRUE);
}