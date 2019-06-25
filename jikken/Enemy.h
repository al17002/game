#ifndef DEF_Enemy_H //��dinclude�h�~
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

// ������������
void Enemy_Initialize(Enemy_t *Enemy,int x, int y, int *img, int num);

// �������v�Z����
void Enemy_Update(Enemy_t *Enemy);

// �`�悷��
void Enemy_Draw(Enemy_t Enemy);

// �I������������
void Enemy_Finalize(Enemy_t Enemy);

extern Enemy_t m_Enemy[];

#endif