#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Savedata.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "Map.h"
int Font01;
int Font02;
int Font03;

void Font_Initialize() {
	Font01 = CreateFontToHandle("�l�r �S�V�b�N", 30, 9, DX_FONTTYPE_NORMAL);
	Font02 = CreateFontToHandle("�l�r �S�V�b�N", 70, 9, DX_FONTTYPE_NORMAL);
	Font03 = CreateFontToHandle("�l�r �S�V�b�N", 120, 9, DX_FONTTYPE_NORMAL);
}
//�X�V
void Title_Update() {
	if (CheckHitKey(KEY_INPUT_V) != 0) { //H�L�[�������ꂽ��
		input_savedata(0);
		//dataflow();
		//Player_Initialize();
		//EnemyMgr_Initialize();
		//Floor_Initialize();
		//load_map(1);
		SceneMgr_ChangeScene(eScene_WareHouse);//�͂��߂���
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) { //C�L�[�������ꂽ��
		SceneMgr_ChangeScene(eScene_SaveSelect);//��������
		//Player_Initialize();
		//EnemyMgr_Initialize();
		//Floor_Initialize();
		//load_map(1);
	}
}

//�`��
void Title_Draw() {
		DrawStringToHandle(350, 200, "���[�O���C�N�Q�[��(��)", GetColor(255, 255, 255), Font02);
		DrawStringToHandle(500, 450, "V:�͂��߂���", GetColor(255, 255, 255), Font02);
		DrawStringToHandle(500, 650, "C:��������", GetColor(255, 255, 255), Font02);
}
