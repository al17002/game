#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"

//�X�V
void Menu_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//G�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
}

//�`��
void Menu_Draw() {
	DrawString(0, 0, "���j���[��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "G�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
}