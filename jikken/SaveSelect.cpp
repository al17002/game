#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Savedata.h"
#include "Title.h"
int Font1;


//�X�V
void SaveSelect_Update() {
	if (CheckHitKey(KEY_INPUT_T) != 0) { //T��I��
		SceneMgr_ChangeScene(eScene_Title);//�^�C�g���ɖ߂�
	}
	if (CheckHitKey(KEY_INPUT_1) != 0) { //1��I��
		input_savedata(1);//�Z�[�u�f�[�^1���������Ă�
		//dataflow();
		SceneMgr_ChangeScene(eScene_WareHouse);//�Z�[�u�f�[�^1��I�����ăQ�[�����J�n
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2��I��
		input_savedata(2);//�Z�[�u�f�[�^2���������Ă�
		//dataflow();
		SceneMgr_ChangeScene(eScene_WareHouse);//�Z�[�u�f�[�^2��I�����ăQ�[�����J�n
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3��I��
		input_savedata(3);//�Z�[�u�f�[�^3���������Ă�
		//dataflow();
		SceneMgr_ChangeScene(eScene_WareHouse);//�Z�[�u�f�[�^3��I�����ăQ�[�����J�n
	}
}

//�`��
void SaveSelect_Draw() {
	int i;
	DrawStringToHandle(30, 0, "�Z�[�u�I�����(�ԍ����v�b�V�����ăZ�[�u�f�[�^��I��)", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(30, 100, "T:�^�C�g����ʂɖ߂�", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(30, 200, "1.�A�C�e�����", GetColor(255, 255, 255),Font01);//�f�[�^1�A�C�e�����
	input_savedata(1);
	DrawFormatStringToHandle(30, 240, GetColor(255, 255, 255),Font01, "������:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {//�͈͂�player_item.itemnum
		DrawFormatStringToHandle(30, 280 + 40 * i, GetColor(255, 255, 255),Font01 ,"%d:%s atk:%d hp:%d", i, itemRef[player_item.having_item[i].ID].name, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
	DrawStringToHandle(530, 200, "2.�A�C�e�����", GetColor(255, 255, 255),Font01);//�f�[�^2�A�C�e�����
	input_savedata(2);
	DrawFormatStringToHandle(530,240, GetColor(255, 255, 255),Font01, "������:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {
		DrawFormatStringToHandle(530, 280 + 40 * i, GetColor(255, 255, 255),Font01, "%d:%s atk:%d hp:%d", i, itemRef[player_item.having_item[i].ID].name, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
	DrawStringToHandle(1030, 200, "3.�A�C�e�����", GetColor(255, 255, 255),Font01);//�f�[�^2�A�C�e�����
	input_savedata(3);
	DrawFormatStringToHandle(1030, 240, GetColor(255, 255, 255),Font01,"������:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {
		DrawFormatStringToHandle(1030, 280 + 40 * i, GetColor(255, 255, 255),Font01, "%d:%s atk:%d hp:%d", i, itemRef[player_item.having_item[i].ID].name,player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
}
	