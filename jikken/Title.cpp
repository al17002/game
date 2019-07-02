#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Savedata.h"

//�X�V
void Title_Update() {
	if (CheckHitKey(KEY_INPUT_H) != 0) { //H�L�[�������ꂽ��
		input_savedata(0);
		//dataflow();
		SceneMgr_ChangeScene(eScene_WareHouse);//�͂��߂���
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