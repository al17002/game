#pragma once

#include "Savedata.h"

typedef struct {
	int num;
	int Image[16];
	int m_Image;
	int y;
	int x;
	int muki;
	int walking_flag;
	item equipment;
	bool enemy_turn = true;
	bool alive = false;
} Enemy_t;

// 初期化をする
void Enemy_Initialize(Enemy_t *Enemy,int x, int y, int *img, int num);

// 動きを計算する
void Enemy_Update(Enemy_t *Enemy);

// 描画する
void Enemy_Draw(Enemy_t Enemy);

// 終了処理をする
void Enemy_Finalize(Enemy_t Enemy);

extern Enemy_t m_Enemy[];