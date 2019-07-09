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

	Player_Draw();
	EnemyMgr_Draw();
	Map_Draw();

}

//�`��
void Game_Draw() {
	DrawString(1250, 40, "�Q�[�����", GetColor(255, 255, 255));
	DrawFormatString(1250, 60, GetColor(255, 255, 255), "M�L�[��������\n���j���[��ʂɈړ����܂��B");
	DrawFormatString(1250, 150, GetColor(255, 255, 255), "���݂�%d�K�w�ڂł�",1);
	DrawFormatString(1250, 200, GetColor(255, 255, 255), "������:%s \natk: %d hp: %d", itemRef[player.equipment.ID].name, player.equipment.atk, player.equipment.hp);


}