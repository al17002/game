#include "DxLib.h"
#include "SceneMgr.h"
#include "Player.h"
#include "EnemyMgr.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	Player_Initialize();
	EnemyMgr_Initialize();
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���
		SceneMgr_Update();  //�X�V
		SceneMgr_Draw();    //�`��
	}
	EnemyMgr_Finalize();
	Player_Finalize();
	DxLib_End(); // DX���C�u�����I������
	return 0;
}