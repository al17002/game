#include "DxLib.h"
#include "Player.h"
#include "Keyboard.h"
#include "Map.h"
#include "Game.h"
#include "Savedata.h"
#include "hitJudgment.h"
#include "SceneMgr.h"
#include "Enemymgr.h"
#include "Title.h"

// ���̃t�@�C�����ł����g���Ȃ��O���[�o���ϐ�
static int m_Image; //�摜�n���h��
static int walking_flag;
static int muki;
static int image[16];

// ������������
void Player_Initialize() {
	LoadDivGraph("�摜/�L�����N�^10.png", 16, 4, 4, 32, 32, image);
	m_Image = image[(player.x % 32 + player.y % 32) / 8 + muki * 4];
	player.x = 160;
	player.y = 160;
}

// �������v�Z����
void Player_Update() {
	if (player.x % 32 == 0 && player.y % 32 == 0) {//���W��32�Ŋ���؂ꂽ����͉\�@�^�[�����Ȃ����蓮���Ȃ�
		
		walking_flag = 0;         //�~�܂�t���O�𗧂Ă�B
		if (turn) {//�^�[��������i�Ղꂢ��[)
			walking_flag = 1;
			if (Keyboard_Get(KEY_INPUT_UP) == 1)  //��{�^���������ꂽ��
				muki = 0;         //������t���O�𗧂Ă�
			else if (Keyboard_Get(KEY_INPUT_LEFT) == 1)  //���{�^���������ꂽ��
				muki = 1;         //�������t���O�𗧂Ă�
			else if (Keyboard_Get(KEY_INPUT_DOWN) == 1)  //���{�^���������ꂽ��
				muki = 2;         //�������t���O�𗧂Ă�
			else if (Keyboard_Get(KEY_INPUT_RIGHT) == 1)  //�E�{�^���������ꂽ��
				muki = 3;         //�E�����t���O�𗧂Ă�
			else                                    //���̃{�^����������ĂȂ�������
				walking_flag = 0; //�����Ȃ��t���O�𗧂Ă�

			if (walking_flag == 1) {
				if (IsAbleToGo(player.x, player.y, muki,true) == 1) {
					walking_flag = 0;
					turn = false;
				}
				else {
					int hitcheck = hitJudgement(muki, -1);
					if (hitcheck != 0) {
						walking_flag = 0;
						hit_enemy(hitcheck - 1);//���킹�邽�߂�-1
						turn = false;
					}
				}
			}
		}
	}

	if (walking_flag == 1) {        //�����t���O�������Ă�����
		if (muki == 0)        //������Ȃ�ch.y���W�����炷
			move_player(0, -8);
		else if (muki == 1)        //�������Ȃ�ch.x���W�����炷
			move_player(-8, 0);
		else if (muki == 2)        //�������Ȃ�ch.y���W�𑝂₷
			move_player(0, 8);
		else if (muki == 3)        //�E�����Ȃ�ch.x���W�𑝂₷
			move_player(8, 0);

		if (player.x % 32 == 0 && player.y % 32 == 0) {
			turn = false; //�ړI�n�ɓ����A�^�[����n��
		}
	}
}

// �`�悷��
void Player_Draw() {
	m_Image = image[(player.x % 32 + player.y % 32) / 8 + muki * 4];
	DrawGraph(player.x, player.y, m_Image, TRUE);
}

// �I������������
void Player_Finalize() {
	DeleteGraph(m_Image);
}


void Death_Update() {
	//back_dataflow();  //�Z�[�u�ɂ��Ċm�F�������Ƃ��͂��̊֐��𗘗p
	//EnemyMgr_Finalize();
	//Player_Finalize();
	if (CheckHitKey(KEY_INPUT_RETURN) != 0) {
		back_dataflow();
		SceneMgr_ChangeScene(eScene_WareHouse);
	}
}

void Death_Draw() {
	DrawStringToHandle(450, 400, "GAME OVER!!", GetColor(255, 255, 255),Font03);
	DrawStringToHandle(850, 950, "PRESS ENTER�ő��s", GetColor(255, 255, 255),Font02);
	
}

void Win_Update() {
	//back_dataflow();  //�Z�[�u�ɂ��Ċm�F�������Ƃ��͂��̊֐��𗘗p
	//EnemyMgr_Finalize();
	//Player_Finalize();
	if (CheckHitKey(KEY_INPUT_RETURN) != 0) {
		back_dataflow();
		SceneMgr_ChangeScene(eScene_WareHouse);
	}
}

void Win_Draw() {
	DrawStringToHandle(400, 400, "GAME CLEAR!!", GetColor(255, 255, 255),Font03);
	DrawStringToHandle(850, 950, "ENTER KEY�ő��s", GetColor(255, 255, 255),Font02);
}