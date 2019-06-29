#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "newfloor.h"
#include "savedata.h"
//�X�V
void Menu_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_H) != 0) {
		SceneMgr_ChangeScene(eScene_EquipmentChange);
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) {
			SceneMgr_ChangeScene(eScene_Title);
	}
	if (CheckHitKey(KEY_INPUT_N) != 0) {
		floor_renew(2);
	}
	if (CheckHitKey(KEY_INPUT_Z) != 0) {
		DxLib_End();
	}
}

//�`��
void Menu_Draw() {
	int i;
	DrawString(20, 20, "���j���[", GetColor(255, 255, 255));
	DrawString(20, 40, "G:�Q�[����ʂɖ߂�", GetColor(255, 255, 255));
	DrawString(20, 60, "H:�����ύX", GetColor(255, 255, 255));
	DrawString(20, 80, "T:�^�C�g���ɖ߂�", GetColor(255, 255, 255));
	DrawString(20, 160, "�������", GetColor(255, 255, 255));
	//s = "�L�����N�^�Ǘ����̊֐�";
	DrawFormatString(20, 180, GetColor(255, 255, 255), "������:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {//�͈͂�player_item.itemnum
		DrawFormatString(20, 200 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
}