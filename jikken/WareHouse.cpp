#include "WareHouse.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "savedata.h"
//�X�V
void WareHouse_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
		//dataflow();
		SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) {
		SceneMgr_ChangeScene(eScene_Title);
	}
	if (CheckHitKey(KEY_INPUT_S) != 0) {
		SceneMgr_ChangeScene(eScene_Save);
	}
	if (CheckHitKey(KEY_INPUT_E) != 0) {
		DxLib_End();
	}
}

//�`��
void WareHouse_Draw() {
	int i;
	DrawString(20, 20, "�Q�[���J�ډ��", GetColor(255, 255, 255));
	DrawString(20, 40, "G:�Q�[����ʂ�", GetColor(255, 255, 255));
	DrawString(20, 80, "S:�Z�[�u�f�[�^�ۑ�", GetColor(255, 255, 255));
	DrawString(20, 100, "T:�^�C�g���֖߂�", GetColor(255, 255, 255));
	DrawString(20,120, "E:�I��", GetColor(255, 255, 255));
	DrawString(20, 160, "�������", GetColor(255, 255, 255));
	//s = "�L�����N�^�Ǘ����̊֐�";
	DrawFormatString(20, 180, GetColor(255, 255, 255), "������:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {//�͈͂�player_item.itemnum
		DrawFormatString(20, 200 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
}