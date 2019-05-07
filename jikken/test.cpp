#include "DxLib.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
    ChangeWindowMode(TRUE); // ウィンドウモードに設定
    DxLib_Init();   // DXライブラリ初期化処理
	LoadGraphScreen(50, 100, "画像/r7u3rf000000012y.png", TRUE);
    WaitKey();      // キー入力待ち
    DxLib_End();    // DXライブラリ終了処理
    return 0;
}