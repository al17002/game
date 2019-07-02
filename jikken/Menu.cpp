#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
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
	if (CheckHitKey(KEY_INPUT_E) != 0) {
		DxLib_End();
	}
	if (CheckHitKey(KEY_INPUT_S) != 0) {
		SceneMgr_ChangeScene(eScene_Save);
	}
}

//�`��
void Menu_Draw() {
	int i;
	DrawString(20, 20, "���j���[", GetColor(255, 255, 255));
	DrawString(20, 40, "G:�Q�[����ʂɖ߂�", GetColor(255, 255, 255));
	DrawString(20, 60, "H:�����ύX", GetColor(255, 255, 255));
	DrawString(20, 80, "S:�Z�[�u", GetColor(255, 255, 255));
	DrawString(20, 100, "T:�^�C�g���֖߂�", GetColor(255, 255, 255));
	DrawString(20, 120, "E:�I��", GetColor(255, 255, 255));
	DrawString(20, 160, "�������", GetColor(255, 255, 255));
	//s = "�L�����N�^�Ǘ����̊֐�";
	DrawFormatString(20, 180, GetColor(255, 255, 255), "������:%s atk:%d hp:%d", itemRef[player.equipment.ID].name, player.equipment.atk, player.equipment.hp);
	for (i = 0; i < 10; i++) {//�͈͂�player_item.itemnum
		DrawFormatString(20, 200 + 20 * i, GetColor(255, 255, 255), "%d:%s atk:%d hp:%d", i, itemRef[player.having_item[i].ID].name, player.having_item[i].atk, player.having_item[i].hp);
	}
}