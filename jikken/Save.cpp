#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Savedata.h"
player_item_data genzai;
//�X�V
void Save_Update() {
	if (CheckHitKey(KEY_INPUT_W) != 0) { //W��I��
		SceneMgr_ChangeScene(eScene_WareHouse);//���j���[�ɖ߂�
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) { //T��I��
		SceneMgr_ChangeScene(eScene_Title);//�^�C�g���ɖ߂�
	}
	if (CheckHitKey(KEY_INPUT_1) != 0) { //1��I��
		player_item = genzai;
		output_savedata(1);
		SceneMgr_ChangeScene(eScene_Save);//�Z�[�u�f�[�^1��I�����ăZ�[�u
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2��I��
		player_item = genzai;
		output_savedata(1);
		SceneMgr_ChangeScene(eScene_Save);//�Z�[�u�f�[�^2��I�����ăZ�[�u
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3��I��
		player_item = genzai;
		output_savedata(1);
		SceneMgr_ChangeScene(eScene_Save);//�Z�[�u�f�[�^3��I�����ăZ�[�u
	}
}

//�`��
void Save_Draw() {
	int i;
	genzai=player_item;
	DrawString(0, 0, "�Z�[�u�ۑ����(�ԍ����v�b�V�����ăZ�[�u�f�[�^��ۑ�)", GetColor(255, 255, 255));
	DrawString(0, 20, "W:�Q�[���J�ډ�ʂɖ߂�", GetColor(255, 255, 255));
	DrawString(0, 80, "1.�A�C�e�����", GetColor(255, 255, 255));//�f�[�^1�A�C�e�����
	input_savedata(1);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "������:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {//�͈͂�player_item.itemnum
		DrawFormatString(0, 120 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk,player_item.having_item[i].hp);
	}
	DrawString(0, 340, "2.�A�C�e�����", GetColor(255, 255, 255));//�f�[�^2�A�C�e�����
	input_savedata(1);
	DrawFormatString(0, 360, GetColor(255, 255, 255), "������:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {
		DrawFormatString(0, 380 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk,player_item.having_item[i].hp);
	}
	DrawString(0, 600, "3.�A�C�e�����", GetColor(255, 255, 255));//�f�[�^2�A�C�e�����
	input_savedata(1);
	DrawFormatString(0, 620, GetColor(255, 255, 255), "������:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {
		DrawFormatString(0, 640 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk,player_item.having_item[i].hp);
	}
}