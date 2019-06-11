#include "DxLib.h"
#include "Keyboard.h"
#include "Enemy.h"

static const int NUM = 2;        //�v���C���[�̐�

static Enemy_t m_Enemy[NUM];   //�v���C���[�̎���
static int m_ImgEnemy;          //�v���C���[�̉摜�n���h��

// ������������
void EnemyMgr_Initialize() {
	m_ImgEnemy = LoadGraph("�摜/�L�����N�^01.png");
	Enemy_Initialize(&m_Enemy[0], 160,160, m_ImgEnemy);// ������
	Enemy_Initialize(&m_Enemy[1], 320,320, m_ImgEnemy);// ������
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
