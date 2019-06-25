#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "savedata.h"
char a[5][20] = { "�\�[�h","�V�[���h","u","e","o" };//�b��I�ȃZ�[�u�f�[�^
//�X�V
void EquipmentChange_Update() {
	if (CheckHitKey(KEY_INPUT_M) != 0) { //M��I��
		SceneMgr_ChangeScene(eScene_Menu);//���j���[�ɖ߂�
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) { //T��I��
		SceneMgr_ChangeScene(eScene_Title);//�^�C�g���ɖ߂�
	}
	if (CheckHitKey(KEY_INPUT_1) != 0) { //1��I��
		//GetSavedata();
		SceneMgr_ChangeScene(eScene_EquipmentChange);//���݂̑�����1�̑��������ւ���
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2��I��
		//GetSavedata(2);
		SceneMgr_ChangeScene(eScene_EquipmentChange);//���݂̑�����2�̑��������ւ���
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3��I��
		//GetSaveData(3);
		SceneMgr_ChangeScene(eScene_EquipmentChange);//���݂̑�����3�̑��������ւ���
	}
}

//�`��
void EquipmentChange_Draw() {
	int i;
	DrawString(0, 0, "�����ύX���(�ԍ����v�b�V�����đ����ύX����ۑ�)", GetColor(255, 255, 255));
	DrawString(0, 20, "M:���j���[��ʂɖ߂�", GetColor(255, 255, 255));
	DrawString(0, 40, "T:�^�C�g���Ɉړ�", GetColor(255, 255, 255));
	DrawString(0, 60, "1.�A�C�e�����", GetColor(255, 255, 255));//�f�[�^1�A�C�e�����
	DrawFormatString(0, 80, GetColor(255, 255, 255), "������:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {//�͈͂�player_item.itemnum
		DrawFormatString(20, 100 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
}
