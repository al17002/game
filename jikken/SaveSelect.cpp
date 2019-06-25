#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Savedata.h"

//�X�V
void SaveSelect_Update() {
	if (CheckHitKey(KEY_INPUT_T) != 0) { //T��I��
		SceneMgr_ChangeScene(eScene_Title);//�^�C�g���ɖ߂�
	}
	if (CheckHitKey(KEY_INPUT_1) != 0) { //1��I��
		output_savedata(0);//�Z�[�u�f�[�^1���������Ă�
		SceneMgr_ChangeScene(eScene_Game);//�Z�[�u�f�[�^1��I�����ăQ�[�����J�n
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2��I��
		output_savedata(0);//�Z�[�u�f�[�^2���������Ă�
		SceneMgr_ChangeScene(eScene_Game);//�Z�[�u�f�[�^2��I�����ăQ�[�����J�n
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3��I��
		SceneMgr_ChangeScene(eScene_Game);//�Z�[�u�f�[�^3��I�����ăQ�[�����J�n
	}
}

//�`��
void SaveSelect_Draw() {
	int i;
	DrawString(0, 0, "�Z�[�u�I�����(�ԍ����v�b�V�����ăZ�[�u�f�[�^��I��)", GetColor(255, 255, 255));
	DrawString(0, 20, "T:�^�C�g����ʂɖ߂�", GetColor(255, 255, 255));
	DrawString(0, 60, "1.�A�C�e�����", GetColor(255, 255, 255));//�f�[�^1�A�C�e�����
	input_savedata(0);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "������:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {//�͈͂�player_item.itemnum
		DrawFormatString(0, 100 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
	DrawString(0, 320, "2.�A�C�e�����", GetColor(255, 255, 255));//�f�[�^2�A�C�e�����
	input_savedata(0);
	DrawFormatString(0, 340, GetColor(255, 255, 255), "������:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {
		DrawFormatString(0, 360 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
	DrawString(0, 580, "3.�A�C�e�����", GetColor(255, 255, 255));//�f�[�^2�A�C�e�����
	input_savedata(0);
	DrawFormatString(0, 600, GetColor(255, 255, 255), "������:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {
		DrawFormatString(0, 620 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID,player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
}
	