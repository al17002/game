#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Player.h"
#include "Keyboard.h"
#include "Map.h"
#include "EnemyMgr.h"
#include "Enemy.h"
#include "Savedata.h"

bool turn = true;//�^�[��(Global) True = player false = enemy

typedef struct {
	int x, y, img;
}ch_t;

//�X�V
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_M) != 0) { //M�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
	if (CheckHitKey(KEY_INPUT_W) != 0) { //W�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�����Q�[���J�ڂɕύX
	}

	Keyboard_Update();
	Player_Update();
	EnemyMgr_Update();

	Player_Draw();
	EnemyMgr_Draw();
	Map_Draw();

}

//�`��
void Game_Draw() {
	DrawString(1250, 40, "�Q�[�����", GetColor(255, 255, 255));
	DrawFormatString(1250, 60, GetColor(255, 255, 255), "M�L�[��������\n���j���[��ʂɈړ����܂��B\nW�{�^����������\n�Q�[���J�ډ�ʂ֖߂�܂�");
	DrawFormatString(1250, 150, GetColor(255, 255, 255), "���݂�%d�K�w�ڂł�",1);
	DrawFormatString(1250, 200, GetColor(255, 255, 255), "������:%d atk: %d hp: %d", player.equipment.ID, player.equipment.atk, player.equipment.hp);
	DrawFormatString(1250, 300, GetColor(255, 255, 255), "�G1:%d atk: %d hp: %d,: %d", m_Enemy[1].equipment.ID, m_Enemy[1].equipment.atk, m_Enemy[1].equipment.hp, m_Enemy[1].alive);

}