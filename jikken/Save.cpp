#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
char u[5][20] = { "�\�[�h","�V�[���h","u","e","o" };//�b��I�ȃZ�[�u�f�[�^
//�X�V
void Save_Update() {
	if (CheckHitKey(KEY_INPUT_M) != 0) { //T��I��
		SceneMgr_ChangeScene(eScene_Menu);//�^�C�g���ɖ߂�
	}
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
void Save_Draw() {
	DrawString(0, 0, "�Z�[�u�ۑ����(�ԍ����v�b�V�����ăZ�[�u�f�[�^��ۑ�)", GetColor(255, 255, 255));
	DrawString(0, 20, "M:���j���[��ʂɖ߂�", GetColor(255, 255, 255));
	DrawString(0, 40, "T:�^�C�g���Ɉړ�", GetColor(255, 255, 255));
	DrawString(0, 60, "1.�A�C�e�����", GetColor(255, 255, 255));//�f�[�^1�A�C�e�����
	//s = ;//�Z�[�u�f�[�^�Ăяo��
	DrawFormatString(20, 80, GetColor(255, 255, 255), "1:%s", u[0]);
	DrawFormatString(20, 100, GetColor(255, 255, 255), "2:%s", u[1]);
	DrawFormatString(20, 120, GetColor(255, 255, 255), "3:%s", u[2]);
	DrawFormatString(20, 140, GetColor(255, 255, 255), "4:%s", u[3]);
	DrawFormatString(20, 160, GetColor(255, 255, 255), "5:%s", u[4]);

	DrawString(0, 200, "2.�A�C�e�����", GetColor(255, 255, 255));//�f�[�^2�A�C�e�����
	//s = ;//�Z�[�u�f�[�^�Ăяo��
	DrawFormatString(20, 220, GetColor(255, 255, 255), "1:%s", u[0]);
	DrawFormatString(20, 240, GetColor(255, 255, 255), "2:%s", u[1]);
	DrawFormatString(20, 260, GetColor(255, 255, 255), "3:%s", u[2]);
	DrawFormatString(20, 280, GetColor(255, 255, 255), "4:%s", u[3]);
	DrawFormatString(20, 300, GetColor(255, 255, 255), "5:%s", u[4]);
	//s=;//�Z�[�u�f�[�^�Ăяo��
	DrawString(0, 340, "3.�A�C�e�����", GetColor(255, 255, 255));//�f�[�^3�A�C�e�����
	DrawFormatString(20, 360, GetColor(255, 255, 255), "1:%s", u[0]);
	DrawFormatString(20, 380, GetColor(255, 255, 255), "2:%s", u[1]);
	DrawFormatString(20, 400, GetColor(255, 255, 255), "3:%s", u[2]);
	DrawFormatString(20, 420, GetColor(255, 255, 255), "4:%s", u[3]);
	DrawFormatString(20, 440, GetColor(255, 255, 255), "5:%s", u[4]);
}