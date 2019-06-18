#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"

//�X�V
void Title_Update() {
	if (CheckHitKey(KEY_INPUT_H) != 0) { //H�L�[�������ꂽ��
		SceneMgr_ChangeScene(eScene_Game);//�͂��߂���
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) { //C�L�[�������ꂽ��
		SceneMgr_ChangeScene(eScene_SaveSelect);//��������
	}
}

//�`��
void Title_Draw() {
	DrawString(0, 0, "���[�O���C�N�Q�[��(��)", GetColor(255, 255, 255));
	DrawString(0, 20, "H:�͂��߂���", GetColor(255, 255, 255));
	DrawString(0, 40, "C:��������", GetColor(255, 255, 255));
}