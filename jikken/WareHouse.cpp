#include "WareHouse.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "savedata.h"
#include "Title.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "Map.h"

player_item_data save_temp;

//更新
void WareHouse_Update() {
	
	if (CheckHitKey(KEY_INPUT_G) != 0) {//Gキーが押されていたら
		EnemyMgr_Finalize();
		Player_Finalize();
		dataflow();
		load_map(1);
		Player_Initialize();
		EnemyMgr_Initialize();
		Floor_Initialize();
		SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) {
		SceneMgr_ChangeScene(eScene_Title);
	}
	if (CheckHitKey(KEY_INPUT_E) != 0) {
		DxLib_End();
	}
	if (CheckHitKey(KEY_INPUT_S) != 0) {
		save_temp = player_item;
		SceneMgr_ChangeScene(eScene_Save);
	}

}

//描画
void WareHouse_Draw() {
	int i;
	DrawStringToHandle(550, 50, "倉庫画面", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 150, "G:ゲーム画面へ", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 200, "T:タイトルへ戻る", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 250, "S:セーブ", GetColor(255, 255, 255), Font01);
	DrawStringToHandle(550, 300, "E:終了", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 400, "装備情報", GetColor(255, 255, 255),Font01);
	//s = "キャラクタ管理部の関数";
	DrawFormatStringToHandle(550, 470, GetColor(255, 255, 255),Font01,"装備中:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	DrawStringToHandle(550, 540, "所持アイテム", GetColor(255, 255, 255), Font01);
	for (i = 0; i < 10; i++) {//範囲はplayer_item.itemnum
		DrawFormatStringToHandle(550, 590 + 40 * i, GetColor(255, 255, 255),Font01,"%d:%s atk:%d hp:%d", i,itemRef[player_item.having_item[i].ID].name, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
}