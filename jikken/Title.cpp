#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Savedata.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "Map.h"

//更新
void Title_Update() {
	if (CheckHitKey(KEY_INPUT_H) != 0) { //Hキーが押されたら
		input_savedata(0);
		//dataflow();
		Player_Initialize();
		EnemyMgr_Initialize();
		Floor_Initialize();
		load_map(1);
		SceneMgr_ChangeScene(eScene_WareHouse);//はじめから
	}
	if (CheckHitKey(KEY_INPUT_C) != 0) { //Cキーが押されたら
		SceneMgr_ChangeScene(eScene_SaveSelect);//続きから
		Player_Initialize();
		EnemyMgr_Initialize();
		Floor_Initialize();
		load_map(1);
	}
}

//描画
void Title_Draw() {
	DrawString(0, 0, "ローグライクゲーム(仮)", GetColor(255, 255, 255));
	DrawString(0, 20, "H:はじめから", GetColor(255, 255, 255));
	DrawString(0, 40, "C:続きから", GetColor(255, 255, 255));
}