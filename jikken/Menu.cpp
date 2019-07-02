#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
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
	if (CheckHitKey(KEY_INPUT_E) != 0) {
		DxLib_End();
	}
	if (CheckHitKey(KEY_INPUT_S) != 0) {
		SceneMgr_ChangeScene(eScene_Save);
	}
}

//描画
void Menu_Draw() {
	int i;
	DrawString(20, 20, "メニュー", GetColor(255, 255, 255));
	DrawString(20, 40, "G:ゲーム画面に戻る", GetColor(255, 255, 255));
	DrawString(20, 60, "H:装備変更", GetColor(255, 255, 255));
	DrawString(20, 80, "S:セーブ", GetColor(255, 255, 255));
	DrawString(20, 100, "T:タイトルへ戻る", GetColor(255, 255, 255));
	DrawString(20, 120, "E:終了", GetColor(255, 255, 255));
	DrawString(20, 160, "装備情報", GetColor(255, 255, 255));
	//s = "キャラクタ管理部の関数";
	DrawFormatString(20, 180, GetColor(255, 255, 255), "装備中:%s atk:%d hp:%d", itemRef[player.equipment.ID].name, player.equipment.atk, player.equipment.hp);
	for (i = 0; i < 10; i++) {//範囲はplayer_item.itemnum
		DrawFormatString(20, 200 + 20 * i, GetColor(255, 255, 255), "%d:%s atk:%d hp:%d", i, itemRef[player.having_item[i].ID].name, player.having_item[i].atk, player.having_item[i].hp);
	}
}