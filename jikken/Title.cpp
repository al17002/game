#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"

//�X�V
void Title_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) { //Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Game);//�V�[�������j���[�ɕύX
	}
}

//�`��
void Title_Draw() {
	DrawString(0, 0, "�^�C�g����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "G�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
}