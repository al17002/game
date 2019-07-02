#include "WareHouse.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "savedata.h"
#include "Title.h"
//�X�V
void WareHouse_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
		dataflow();
		SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) {
		SceneMgr_ChangeScene(eScene_Title);
	}
	if (CheckHitKey(KEY_INPUT_E) != 0) {
		DxLib_End();
	}
}

//�`��
void WareHouse_Draw() {
	int i;
	DrawStringToHandle(550, 50, "�Q�[���J�ډ��", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 150, "G:�Q�[����ʂ�", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 200, "T:�^�C�g���֖߂�", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550,250, "E:�I��", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 400, "�������", GetColor(255, 255, 255),Font01);
	//s = "�L�����N�^�Ǘ����̊֐�";
	DrawFormatStringToHandle(550, 490, GetColor(255, 255, 255),Font01,"������:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {//�͈͂�player_item.itemnum
		DrawFormatStringToHandle(550, 530 + 40 * i, GetColor(255, 255, 255),Font01,"%d:%s atk:%d hp:%d", i,itemRef[player_item.having_item[i].ID].name, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
}