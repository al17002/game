#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
char t[5][20] = { "�\�[�h","a","i","u","e" };
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
	if (CheckHitKey(KEY_INPUT_S) != 0) {
		SceneMgr_ChangeScene(eScene_Save);
	}
}

//�`��
void Menu_Draw() {
	DrawString(20, 20, "���j���[", GetColor(255, 255, 255));
	DrawString(20, 40, "G:�Q�[����ʂɖ߂�", GetColor(255, 255, 255));
	DrawString(20, 60, "H:�����ύX", GetColor(255, 255, 255));
	DrawString(20, 80, "S:�Z�[�u�f�[�^�ۑ�", GetColor(255, 255, 255));
	DrawString(20, 100, "T:�^�C�g���ɖ߂�", GetColor(255, 255, 255));
	DrawString(20, 160, "�������", GetColor(255, 255, 255));
	//s = "�L�����N�^�Ǘ����̊֐�";
	DrawFormatString(20, 180, GetColor(255, 255, 255), "1:%s", t[0]);
	DrawFormatString(20, 200, GetColor(255, 255, 255), "2:%s", t[1]);
	DrawFormatString(20, 220, GetColor(255, 255, 255), "3:%s", t[2]);
	DrawFormatString(20, 240, GetColor(255, 255, 255), "4:%s", t[3]);
	DrawFormatString(20, 260, GetColor(255, 255, 255), "5:%s", t[4]);
}