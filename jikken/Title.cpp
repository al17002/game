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
	Font01 = CreateFontToHandle("ＭＳ ゴシック", 30, 9, DX_FONTTYPE_NORMAL);
	Font02 = CreateFontToHandle("ＭＳ ゴシック", 70, 9, DX_FONTTYPE_NORMAL);
	Font03 = CreateFontToHandle("ＭＳ ゴシック", 120, 9, DX_FONTTYPE_NORMAL);
}
//更新
void Title_Update() {
	if (CheckHitKey(KEY_INPUT_V) != 0) { //Hキーが押されたら
		input_savedata(0);
		//dataflow();
		//Player_Initialize();
		//EnemyMgr_Initialize();
		//Floor_Initialize();
		//load_map(1);
		SceneMgr_ChangeScene(eScene_WareHouse);//はじめから
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) { //Cキーが押されたら
		SceneMgr_ChangeScene(eScene_SaveSelect);//続きから
		//Player_Initialize();
		//EnemyMgr_Initialize();
		//Floor_Initialize();
		//load_map(1);
	}
}

//描画
void Title_Draw() {
		DrawStringToHandle(350, 200, "ローグライクゲーム(仮)", GetColor(255, 255, 255), Font02);
		DrawStringToHandle(500, 450, "V:はじめから", GetColor(255, 255, 255), Font02);
		DrawStringToHandle(500, 650, "C:続きから", GetColor(255, 255, 255), Font02);
}
