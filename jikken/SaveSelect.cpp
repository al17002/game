#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
char save1[5][20] = { "�\�[�h","�V�[���h","u","e","o" };//�b��I�ȃZ�[�u�f�[�^
char save2[5][20] = { "a","i","u","e","o"};
char save3[5][20] = { "a","i","u","e","o" };
//�X�V
void SaveSelect_Update() {
	if (CheckHitKey(KEY_INPUT_T) != 0) { //T��I��
		SceneMgr_ChangeScene(eScene_Title);//�^�C�g���ɖ߂�
	}
	if (CheckHitKey(KEY_INPUT_1) != 0) { //1��I��
		//GetSavedata();
		SceneMgr_ChangeScene(eScene_Title);//�Z�[�u�f�[�^1��I�����ăQ�[�����J�n
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2��I��
		//GetSavedata(2);
		SceneMgr_ChangeScene(eScene_Title);//�Z�[�u�f�[�^2��I�����ăQ�[�����J�n
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3��I��
		//GetSaveData(3);
		SceneMgr_ChangeScene(eScene_Title);//�Z�[�u�f�[�^3��I�����ăQ�[�����J�n
	}
}

//�`��
void SaveSelect_Draw() {
	DrawString(0, 0, "�Z�[�u�I�����(�ԍ����v�b�V�����ăZ�[�u�f�[�^��I��)", GetColor(255, 255, 255));
	DrawString(0, 20, "T:�^�C�g����ʂɖ߂�", GetColor(255, 255, 255));
	DrawString(0, 40, "1.�A�C�e�����", GetColor(255, 255, 255));//�f�[�^1�A�C�e�����
	//save1 = ;//�Z�[�u�f�[�^�Ăяo��
	DrawFormatString(20, 60, GetColor(255, 255, 255), "1:%s", save1[0]);
	DrawFormatString(20, 80, GetColor(255, 255, 255), "2:%s", save1[1]);
	DrawFormatString(20, 100, GetColor(255, 255, 255), "3:%s", save1[2]);
	DrawFormatString(20, 120, GetColor(255, 255, 255), "4:%s", save1[3]);
	DrawFormatString(20, 140, GetColor(255, 255, 255), "5:%s", save1[4]);

	DrawString(0, 180, "2.�A�C�e�����", GetColor(255, 255, 255));//�f�[�^2�A�C�e�����
	//save2 = ;//�Z�[�u�f�[�^�Ăяo��
	DrawFormatString(20, 200, GetColor(255, 255, 255), "1:%s", save2[0]);
	DrawFormatString(20, 220, GetColor(255, 255, 255), "2:%s", save2[1]);
	DrawFormatString(20, 240, GetColor(255, 255, 255), "3:%s", save2[2]);
	DrawFormatString(20, 260, GetColor(255, 255, 255), "4:%s", save2[3]);
	DrawFormatString(20, 280, GetColor(255, 255, 255), "5:%s", save2[4]);
	//save3=;//�Z�[�u�f�[�^�Ăяo��
	DrawString(0, 320, "3.�A�C�e�����", GetColor(255, 255, 255));//�f�[�^3�A�C�e�����
	DrawFormatString(20, 340, GetColor(255, 255, 255), "1:%s", save3[0]);
	DrawFormatString(20, 360, GetColor(255, 255, 255), "2:%s", save3[1]);
	DrawFormatString(20, 380, GetColor(255, 255, 255), "3:%s", save3[2]);
	DrawFormatString(20, 400, GetColor(255, 255, 255), "4:%s", save3[3]);
	DrawFormatString(20, 420, GetColor(255, 255, 255), "5:%s", save3[4]);
}