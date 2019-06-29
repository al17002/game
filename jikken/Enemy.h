#ifndef DEF_Enemy_H //“ñdinclude–h~

#define DEF_Enemy_H
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
	bool enemy_turn;
} Enemy_t;

// ‰Šú‰»‚ğ‚·‚é
void Enemy_Initialize(Enemy_t *Enemy,int x, int y, int *img, int num);

// “®‚«‚ğŒvZ‚·‚é
void Enemy_Update(Enemy_t *Enemy);

// •`‰æ‚·‚é
void Enemy_Draw(Enemy_t Enemy);

// I—¹ˆ—‚ğ‚·‚é
void Enemy_Finalize(Enemy_t Enemy);

extern Enemy_t m_Enemy[];

#endif