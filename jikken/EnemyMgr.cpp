#include "DxLib.h"
#include "Keyboard.h"
#include "Enemy.h"

static const int NUM = 2;        //�v���C���[�̐�

static Enemy_t m_Enemy[NUM];   //�v���C���[�̎���
static int m_ImgEnemy;          //�v���C���[�̉摜�n���h��
static int image[16];

// ������������
void EnemyMgr_Initialize() {
	LoadDivGraph("�摜/�L�����N�^10.png", 16, 4, 4, 32, 32, image);
	Enemy_Initialize(&m_Enemy[0], 160,160, image);// ������
	Enemy_Initialize(&m_Enemy[1], 320,320, image);// ������
}

// �������v�Z����
void EnemyMgr_Update() {
	for (int i = 0; i < NUM; i++) {
		Enemy_Update(&m_Enemy[i]);//�X�V
	}
}

// �`�悷��
void EnemyMgr_Draw() {
	for (int i = 0; i < NUM; i++) {
		Enemy_Draw(m_Enemy[i]);//�`��
	}
}

// �I������������
void EnemyMgr_Finalize() {
	for (int i = 0; i < NUM; i++) {
		Enemy_Finalize(m_Enemy[i]);//�I������
	}

	DeleteGraph(m_ImgEnemy);    //�摜�����
}
