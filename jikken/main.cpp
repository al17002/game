#include "DxLib.h"
#include "SceneMgr.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "Map.h"
#include "Savedata.h"
#include "Title.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetGraphMode(1480,1024, 32), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	output_itemdata();
	Player_Initialize();
	EnemyMgr_Initialize();
	//Floor_Initialize();
	load_map(1);

	Font_Initialize();
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���
		SceneMgr_Update();  //�X�V
		SceneMgr_Draw();    //�`��
	}
	EnemyMgr_Finalize();
	Player_Finalize();
	DxLib_End(); // DX���C�u�����I������
	return 0;
}