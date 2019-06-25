#ifndef DEF_Enemy_H //二重include防止
#include "Savedata.h"
#define DEF_Enemy_H

typedef struct {
	int num;
	int Image[16];
	int m_Image;
	int y;
	int x;
	int muki;
	int walking_flag;
	bool enemy_turn;
	item equipment;
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

#endif