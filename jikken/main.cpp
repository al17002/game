#include "DxLib.h"
#include "SceneMgr.h"
#include "Player.h"
#include "EnemyMgr.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定
	Player_Initialize();
	EnemyMgr_Initialize();
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新 & メッセージ処理 & 画面消去
		SceneMgr_Update();  //更新
		SceneMgr_Draw();    //描画
	}
	EnemyMgr_Finalize();
	Player_Finalize();
	DxLib_End(); // DXライブラリ終了処理
	return 0;
}