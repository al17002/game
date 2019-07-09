#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Player.h"
#include "Keyboard.h"
#include "Map.h"
#include "EnemyMgr.h"
#include "Enemy.h"
#include "Savedata.h"

//�X�V
bool turn = true;
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_M) != 0) { //M�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}

	Keyboard_Update();
	Player_Update();
	EnemyMgr_Update();

	Map_Draw();
	Player_Draw();
	EnemyMgr_Draw();

}

//�`��
void Game_Draw() {
	DrawString(1250, 40, "�Q�[�����", GetColor(255, 255, 255));
	DrawFormatString(1250, 60, GetColor(255, 255, 255), "M�L�[��������\n���j���[��ʂɈړ����܂��B");
	DrawFormatString(1250, 150, GetColor(255, 255, 255), "���݂�%d�K�w�ڂł�",1);
	DrawFormatString(1250, 200, GetColor(255, 255, 255), "������:%s atk: %d hp: %d", itemRef[player.equipment.ID].name, player.equipment.atk, player.equipment.hp);

	DrawFormatString(1250, 250, GetColor(255, 255, 255), "plx: %d y: %d", player.x, player.y);
	DrawFormatString(1250, 300, GetColor(255, 255, 255), "�G1x: %d y: %d", m_Enemy[1].x, m_Enemy[1].y);
	DrawFormatString(1250, 400, GetColor(255, 255, 255), "�G0x: %d y: %d", m_Enemy[0].x, m_Enemy[0].y);

}