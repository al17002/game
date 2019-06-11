#include "DxLib.h"
#include "Keyboard.h"
#include "Enemy.h"
#include "Map.h"


// ������������
void Enemy_Initialize(Enemy_t *Enemy,int x, int y, int img) {
	Enemy->Image = img;    //�摜�n���h���̊i�[
	Enemy->y = y;      //y���W�i�[
	Enemy->x = x;		//x���W�i�[
}


// �������v�Z����
void Enemy_Update(Enemy_t *Enemy) {/*
	int r = 0;
	int walking_flag = 0;
	int muki = 0;
	if (Enemy->x % 32 == 0 && Enemy->y % 32 == 0) {         //���W��32�Ŋ���؂ꂽ����͉\
		walking_flag = 1;         //�����t���O�𗧂Ă�B
		if (r == 0)  //��{�^���������ꂽ��
			muki = 0;         //������t���O�𗧂Ă�
		else if (r == 1)  //���{�^���������ꂽ��
			muki = 1;         //�������t���O�𗧂Ă�
		else if (r == 2)  //���{�^���������ꂽ��
			muki = 2;         //�������t���O�𗧂Ă�
		else if (r == 3)  //�E�{�^���������ꂽ��
			muki = 3;         //�E�����t���O�𗧂Ă�
		else                                    //���̃{�^����������ĂȂ�������
			walking_flag = 0; //�����Ȃ��t���O�𗧂Ă�

		if (walking_flag == 1)
			if (IsAbleToGo(Enemy->x, Enemy->y, muki) == 1)
				walking_flag = 0;
	}

	if (walking_flag == 1) {        //�����t���O�������Ă�����
		if (muki == 0)        //������Ȃ�ch.y���W�����炷
			Enemy->y--;
		else if (muki == 1)        //�������Ȃ�ch.x���W�����炷
			Enemy->x--;
		else if (muki == 2)        //�������Ȃ�ch.y���W�𑝂₷
			Enemy->y++;
		else if (muki == 3)        //�E�����Ȃ�ch.x���W�𑝂₷
			Enemy->x++;
	}*/
	Enemy->y--;

}

// �`�悷��
void Enemy_Draw(Enemy_t Enemy) {
	DrawGraph(Enemy.x, Enemy.y, Enemy.Image, TRUE);
}

// �I������������
void Enemy_Finalize(Enemy_t Enemy) {
}
