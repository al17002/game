#include "WareHouse.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "savedata.h"
//更新
void WareHouse_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//Gキーが押されていたら
		//dataflow();
		SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) {
		SceneMgr_ChangeScene(eScene_Title);
	}
	if (CheckHitKey(KEY_INPUT_S) != 0) {
		SceneMgr_ChangeScene(eScene_Save);
	}
	if (CheckHitKey(KEY_INPUT_E) != 0) {
		DxLib_End();
	}
}

//描画
void WareHouse_Draw() {
	int i;
	DrawString(20, 20, "ゲーム遷移画面", GetColor(255, 255, 255));
	DrawString(20, 40, "G:ゲーム画面へ", GetColor(255, 255, 255));
	DrawString(20, 80, "S:セーブデータ保存", GetColor(255, 255, 255));
	DrawString(20, 100, "T:タイトルへ戻る", GetColor(255, 255, 255));
	DrawString(20,120, "E:終了", GetColor(255, 255, 255));
	DrawString(20, 160, "装備情報", GetColor(255, 255, 255));
	//s = "キャラクタ管理部の関数";
	DrawFormatString(20, 180, GetColor(255, 255, 255), "装備中:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {//範囲はplayer_item.itemnum
		DrawFormatString(20, 200 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
}