#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "savedata.h"
#include "Title.h"

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
}

//�`��
void Menu_Draw() {
	int i;
	DrawStringToHandle(550, 50, "���j���[", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 150, "G:�Q�[����ʂɖ߂�", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 200, "H:�����ύX", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 250, "T:�^�C�g���֖߂�", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 300, "E:�I��", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 400, "�������", GetColor(255, 255, 255),Font01);
	DrawFormatStringToHandle(550, 470, GetColor(255, 255, 255),Font01, "������:%s atk:%d hp:%d", itemRef[player.equipment.ID].name, player.equipment.atk, player.equipment.hp);
	DrawStringToHandle(550, 540, "�����A�C�e��", GetColor(255, 255, 255), Font01);
	for (i = 0; i < 10; i++) {//�͈͂�player_item.itemnum
		DrawFormatStringToHandle(550, 590 + 40 * i, GetColor(255, 255, 255),Font01, "%d:%s atk:%d hp:%d", i, itemRef[player.having_item[i].ID].name, player.having_item[i].atk, player.having_item[i].hp);
	}
}