#include "DxLib.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
    ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɐݒ�
    DxLib_Init();   // DX���C�u��������������
	LoadGraphScreen(50, 100, "�摜/r7u3rf000000012y.png", TRUE);
    WaitKey();      // �L�[���͑҂�
    DxLib_End();    // DX���C�u�����I������
    return 0;
}