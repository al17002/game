#ifndef DEF_Enemy_H //��dinclude�h�~

#define DEF_Enemy_H

typedef struct {
	int Image;
	int y;
	int x;
} Enemy_t;

// ������������
void Enemy_Initialize(Enemy_t *Enemy,int x, int y, int img);

// �������v�Z����
void Enemy_Update(Enemy_t *Enemy);

// �`�悷��
void Enemy_Draw(Enemy_t Enemy);

// �I������������
void Enemy_Finalize(Enemy_t Enemy);

#endif