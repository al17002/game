#include "DxLib.h"
#include "Player.h"
#include "Keyboard.h"
#include "Map.h"
#include "Game.h"

// ���̃t�@�C�����ł����g���Ȃ��O���[�o���ϐ�
static int m_Image; //�摜�n���h��
static int m_y;     //y���W
static int m_x;
static int walking_flag;
static int muki;
static int image[16];

// ������������
void Player_Initialize() {
	LoadDivGraph("�摜/�L�����N�^10.png", 16, 4, 4, 32, 32, image);
	m_Image = image[(m_x % 32 + m_y % 32) / 8 + muki * 4];
	m_y = 320;
	m_x = 160;
}

// �������v�Z����
void Player_Update() {
	if (m_x % 32 == 0 && m_y % 32 == 0) {//���W��32�Ŋ���؂ꂽ����͉\�@�^�[�����Ȃ����蓮���Ȃ�
		
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

			if (walking_flag == 1)
				if (IsAbleToGo(m_x, m_y, muki) == 1) {
					walking_flag = 0;
					turn = false;
				}
		}
	}

	if (walking_flag == 1) {        //�����t���O�������Ă�����
		if (muki == 0)        //������Ȃ�ch.y���W�����炷
			m_y--;
		else if (muki == 1)        //�������Ȃ�ch.x���W�����炷
			m_x--;
		else if (muki == 2)        //�������Ȃ�ch.y���W�𑝂₷
			m_y++;
		else if (muki == 3)        //�E�����Ȃ�ch.x���W�𑝂₷
			m_x++;

		if (m_x % 32 == 0 && m_y % 32 == 0) {
			turn = false; //�ړI�n�ɓ����A�^�[����n��
		}
	}
}

// �`�悷��
void Player_Draw() {
	m_Image = image[(m_x % 32 + m_y % 32) / 8 + muki * 4];
	DrawGraph(m_x, m_y, m_Image, TRUE);
}

// �I������������
void Player_Finalize() {
	DeleteGraph(m_Image);
}
