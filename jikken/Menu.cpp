#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "newfloor.h"
#include "savedata.h"
//更新
void Menu_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//Gキーが押されていたら
		SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}
	if (CheckHitKey(KEY_INPUT_H) != 0) {
		SceneMgr_ChangeScene(eScene_EquipmentChange);
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) {
			SceneMgr_ChangeScene(eScene_Title);
	}
	if (CheckHitKey(KEY_INPUT_N) != 0) {
		floor_renew(2);
	}
	if (CheckHitKey(KEY_INPUT_Z) != 0) {
		DxLib_End();
	}
}

//描画
void Menu_Draw() {
	int i;
	DrawString(20, 20, "メニュー", GetColor(255, 255, 255));
	DrawString(20, 40, "G:ゲーム画面に戻る", GetColor(255, 255, 255));
	DrawString(20, 60, "H:装備変更", GetColor(255, 255, 255));
	DrawString(20, 80, "T:タイトルに戻る", GetColor(255, 255, 255));
	DrawString(20, 160, "装備情報", GetColor(255, 255, 255));
	//s = "キャラクタ管理部の関数";
	DrawFormatString(20, 180, GetColor(255, 255, 255), "装備中:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {//範囲はplayer_item.itemnum
		DrawFormatString(20, 200 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
}