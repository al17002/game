#include "DxLib.h"
#include "Keyboard.h"
#include "Enemy.h"
#include "Map.h"
#include "Game.h"

// ������������
void Enemy_Initialize(Enemy_t *Enemy,int x, int y, int *img) {
	for (int i = 0; i < 16; i++) {
		Enemy->Image[i] = img[i];
	}
	Enemy->m_Image = img[(x % 32 + y % 32) / 8 + Enemy->muki * 4];    //�摜�n���h���̊i�[
	Enemy->y = y;      //y���W�i�[
	Enemy->x = x;		//x���W�i�[
}


// �������v�Z����
bool Enemy_Update(Enemy_t *Enemy) {
	if (Enemy->x % 32 == 0 && Enemy->y % 32 == 0&&!turn) {//���W��32�Ŋ���؂ꂽ����͉\�@�^�[�����Ȃ���Γ����Ȃ�
		Enemy->walking_flag = 1;         //�����t���O�𗧂Ă�B
		if (Keyboard_Get(KEY_INPUT_UP) == 1)  //��{�^���������ꂽ��
			Enemy->muki = 0;         //������t���O�𗧂Ă�
		else if (Keyboard_Get(KEY_INPUT_LEFT) == 1)  //���{�^���������ꂽ��
			Enemy->muki = 1;         //�������t���O�𗧂Ă�
		else if (Keyboard_Get(KEY_INPUT_DOWN) == 1)  //���{�^���������ꂽ��
			Enemy->muki = 2;         //�������t���O�𗧂Ă�
		else if (Keyboard_Get(KEY_INPUT_RIGHT) == 1)  //�E�{�^���������ꂽ��
			Enemy->muki = 3;         //�E�����t���O�𗧂Ă�
		else                                    //���̃{�^����������ĂȂ�������
			Enemy->walking_flag = 0; //�����Ȃ��t���O�𗧂Ă�

		if (Enemy->walking_flag == 1)
			if (IsAbleToGo(Enemy->x, Enemy->y, Enemy->muki) == 1)
				Enemy->walking_flag = 0;
	}

	if (Enemy->walking_flag == 1) {        //�����t���O�������Ă�����
		if (Enemy->muki == 0)        //������Ȃ�ch.y���W�����炷
			Enemy->y-=8;
		else if (Enemy->muki == 1)        //�������Ȃ�ch.x���W�����炷
			Enemy->x-=8;
		else if (Enemy->muki == 2)        //�������Ȃ�ch.y���W�𑝂₷
			Enemy->y+=8;
		else if (Enemy->muki == 3)        //�E�����Ȃ�ch.x���W�𑝂₷
			Enemy->x+=8;
		if (Enemy->x % 32 == 0 && Enemy->y % 32 == 0) {
			return false; //�ړI�n�ɓ����A�^�[���I���̂���false��Ԃ�
		}
		else
			return true; //�܂��s����
	}
}

// �`�悷��
void Enemy_Draw(Enemy_t Enemy) {
	Enemy.m_Image = Enemy.Image[(Enemy.x % 32 + Enemy.y % 32) / 8 + Enemy.muki * 4];
	DrawGraph(Enemy.x, Enemy.y, Enemy.m_Image, TRUE);
}

// �I������������
void Enemy_Finalize(Enemy_t Enemy) {
}
