#include "DxLib.h"
#include "Keyboard.h"
#include "Enemy.h"
#include "Map.h"
#include "Game.h"
#include "Savedata.h"
#include "hitJudgment.h"

// ������������
void Enemy_Initialize(Enemy_t *Enemy,int x, int y, int *img,int num) {
	Enemy->num = num;
	for (int i = 0; i < 16; i++) {
		Enemy->Image[i] = img[i];
	}
	Enemy->m_Image = img[(x % 32 + y % 32) / 8 + Enemy->muki * 4];    //�摜�n���h���̊i�[
	Enemy->y = y;      //y���W�i�[
	Enemy->x = x;		//x���W�i�[
	Enemy->muki = 0;
	Enemy->walking_flag = 0;
	Enemy->equipment.ID = 1;
	Enemy->equipment.atk = 1;
	Enemy->equipment.hp = 1;
	Enemy->enemy_turn = false;
	Enemy->alive = true;
}


// �������v�Z���� �^�[�����I������s��������enemy_turn��true�ɂȂ�update����Ȃ��Ȃ�
void Enemy_Update(Enemy_t *Enemy) {
	if (Enemy->alive) {//alive��false�̏ꍇ�͉����N����Ȃ�
		if (Enemy->x % 32 == 0 && Enemy->y % 32 == 0) {//���W��32�Ŋ���؂ꂽ����͉\�@�^�[�����Ȃ���Γ����Ȃ�
			Enemy->walking_flag = 0;         //�����Ȃ��t���O�𗧂Ă�B
			if (!Enemy->enemy_turn) {//�^�[��������i�G�l�~�[)
				Enemy->walking_flag = 1;
				if (player.y < Enemy->y && (IsAbleToGo(Enemy->x, Enemy->y, 0) != 1))  //��{�^���������ꂽ��
					Enemy->muki = 0;         //������t���O�𗧂Ă�
				else if (player.x < Enemy->x && (IsAbleToGo(Enemy->x, Enemy->y, 1) != 1))  //���{�^���������ꂽ��
					Enemy->muki = 1;         //�������t���O�𗧂Ă�
				else if (player.y > Enemy->y && (IsAbleToGo(Enemy->x, Enemy->y, 2) != 1))  //���{�^���������ꂽ��
					Enemy->muki = 2;         //�������t���O�𗧂Ă�
				else if (player.x > Enemy->x && (IsAbleToGo(Enemy->x, Enemy->y, 3) != 1))  //�E�{�^���������ꂽ��
					Enemy->muki = 3;         //�E�����t���O�𗧂Ă�
				else                                    //���̃{�^����������ĂȂ�������
					Enemy->walking_flag = 1; //�܂��撣���č��ɕ����t���O�𗧂Ă�
			}
			if (Enemy->walking_flag == 1) {
				int hitcheck = hitJudgment(Enemy->muki, Enemy->num);
				if (hitcheck == -1) {//�v���C���[�ɓ�������
					Enemy->walking_flag = 0;
					hit_player(Enemy->num);
					Enemy->enemy_turn = true;
				}
				else if (hitcheck != -2) {
					Enemy->walking_flag = 0;
					Enemy->enemy_turn = true;
				}
				if (IsAbleToGo(Enemy->x, Enemy->y, Enemy->muki) == 1) {
					Enemy->walking_flag = 0;
					Enemy->enemy_turn = true;
				}
			}
		}

		if (Enemy->walking_flag == 1) {//�����t���O�������Ă�����
			if (Enemy->muki == 0)        //������Ȃ�ch.y���W�����炷
				Enemy->y -= 8;
			else if (Enemy->muki == 1)        //�������Ȃ�ch.x���W�����炷
				Enemy->x -= 8;
			else if (Enemy->muki == 2)        //�������Ȃ�ch.y���W�𑝂₷
				Enemy->y += 8;
			else if (Enemy->muki == 3)        //�E�����Ȃ�ch.x���W�𑝂₷
				Enemy->x += 8;
			if (Enemy->x % 32 == 0 && Enemy->y % 32 == 0) {
				Enemy->enemy_turn = true; //�ړI�n�ɓ����A�^�[���I���̂���true��
			}
		}
	}
}

// �`�悷��
void Enemy_Draw(Enemy_t Enemy) {
	Enemy.m_Image = Enemy.Image[(Enemy.x % 32 + Enemy.y % 32) / 8 + Enemy.muki * 4];
	DrawGraph(Enemy.x, Enemy.y, Enemy.m_Image, true);
}

// �I������������
void Enemy_Finalize(Enemy_t Enemy) {
}
