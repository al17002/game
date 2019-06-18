#include "DxLib.h"
#include "Keyboard.h"
#include "Enemy.h"
#include "Map.h"
#include "Game.h"

static const int NUM = 2;        //�G�̐�

static Enemy_t m_Enemy[NUM];   //�G�̎���
static int m_ImgEnemy;          //�G�̉摜�n���h��
static int image[16];

static bool inturn = false;
static bool check = false;

// ������������
void EnemyMgr_Initialize() {
	LoadDivGraph("�摜/�L�����N�^10.png", 16, 4, 4, 32, 32, image);
	Enemy_Initialize(&m_Enemy[0], 288,320, image);// ������
	Enemy_Initialize(&m_Enemy[1], 320,320, image);// ������
}

// �������v�Z����
void EnemyMgr_Update() {
	if (!turn) {
		if (!inturn) {
			inturn = true;
			for (int i = 0; i < NUM; i++) {
				m_Enemy[i].enemy_turn = false;
			}
		}
		check = true;//���̌�̏�����check���ς��Ȃ���΃^�[���͏I����Ă���
		for (int i = 0; i < NUM; i++) {
			Enemy_Update(&m_Enemy[i]);
			if (!m_Enemy[i].enemy_turn) {
				check = false;
			}
		}
		if (check) {
			inturn = false;
			turn = true;
		}

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
