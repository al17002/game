#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Savedata.h"
#include "Title.h"

//�X�V
void Save_Update() {
	if (CheckHitKey(KEY_INPUT_W) != 0) { //W��I��
		SceneMgr_ChangeScene(eScene_WareHouse);//���j���[�ɖ߂�
	}
	if (CheckHitKey(KEY_INPUT_1) != 0) { //1��I��
		player_item = save_temp;
		output_savedata(1);
		//SceneMgr_ChangeScene(eScene_WareHouse);
		SceneMgr_ChangeScene(eScene_Save);//�Z�[�u�f�[�^1��I�����ăZ�[�u
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2��I��
		player_item = save_temp;
		output_savedata(2);
		//SceneMgr_ChangeScene(eScene_WareHouse);
		SceneMgr_ChangeScene(eScene_Save);//�Z�[�u�f�[�^2��I�����ăZ�[�u
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3��I��
		player_item = save_temp;
		output_savedata(3);
		//SceneMgr_ChangeScene(eScene_WareHouse);
		SceneMgr_ChangeScene(eScene_Save);//�Z�[�u�f�[�^3��I�����ăZ�[�u
	}
}

//�`��
void Save_Draw() {
	int i;
	DrawStringToHandle(350, 50, "�Z�[�u�ۑ����(�ԍ����v�b�V�����ăZ�[�u�f�[�^��ۑ�)", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 150, "W:�Z�[�u�J�ډ�ʂɖ߂�", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(30, 300, "1.�A�C�e�����", GetColor(255, 255, 255),Font01);//�f�[�^1�A�C�e�����
	input_savedata(1);
	DrawFormatStringToHandle(30, 370, GetColor(255, 255, 255),Font01, "������:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	DrawStringToHandle(30, 440, "�����A�C�e��", GetColor(255, 255, 255), Font01);
	for (i = 0; i < 10; i++) {//�͈͂�player_item.itemnum
		DrawFormatStringToHandle(30, 490 + 40 * i, GetColor(255, 255, 255),Font01, "%d:%s atk:%d hp:%d", i, itemRef[player_item.having_item[i].ID].name, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
	DrawStringToHandle(530, 300, "2.�A�C�e�����", GetColor(255, 255, 255),Font01);//�f�[�^2�A�C�e�����
	input_savedata(2);
	DrawFormatStringToHandle(530, 370, GetColor(255, 255, 255),Font01, "������:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	DrawStringToHandle(530, 440, "�����A�C�e��", GetColor(255, 255, 255), Font01);
	for (i = 0; i < 10; i++) {
		DrawFormatStringToHandle(530, 490 + 40 * i, GetColor(255, 255, 255),Font01, "%d:%s atk:%d hp:%d", i, itemRef[player_item.having_item[i].ID].name, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
	DrawStringToHandle(1030, 300, "3.�A�C�e�����", GetColor(255, 255, 255),Font01);//�f�[�^2�A�C�e�����
	input_savedata(3);
	DrawFormatStringToHandle(1030, 370, GetColor(255, 255, 255),Font01, "������:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	DrawStringToHandle(1030, 440, "�����A�C�e��", GetColor(255, 255, 255), Font01);
	for (i = 0; i < 10; i++) {
		DrawFormatStringToHandle(1030, 490 + 40 * i, GetColor(255, 255, 255),Font01, "%d:%s atk:%d hp:%d", i, itemRef[player_item.having_item[i].ID].name, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
}