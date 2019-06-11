#ifndef DEF_Enemy_H //二重include防止

#define DEF_Enemy_H

typedef struct {
	int Image[16];
	int m_Image;
	int y;
	int x;
	int muki;
	int walking_flag;
} Enemy_t;

// 初期化をする
void Enemy_Initialize(Enemy_t *Enemy,int x, int y, int *img);

// 動きを計算する
bool Enemy_Update(Enemy_t *Enemy);

// 描画する
void Enemy_Draw(Enemy_t Enemy);

// 終了処理をする
void Enemy_Finalize(Enemy_t Enemy);

#endif