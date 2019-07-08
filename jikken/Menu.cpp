#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "savedata.h"
#include "Title.h"

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
}

//描画
void Menu_Draw() {
	int i;
	DrawStringToHandle(550, 50, "メニュー", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 150, "G:ゲーム画面に戻る", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 200, "H:装備変更", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 250, "T:タイトルへ戻る", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 300, "E:終了", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 400, "装備情報", GetColor(255, 255, 255),Font01);
	DrawFormatStringToHandle(550, 470, GetColor(255, 255, 255),Font01, "装備中:%s atk:%d hp:%d", itemRef[player.equipment.ID].name, player.equipment.atk, player.equipment.hp);
	DrawStringToHandle(550, 540, "所持アイテム", GetColor(255, 255, 255), Font01);
	for (i = 0; i < 10; i++) {//範囲はplayer_item.itemnum
		DrawFormatStringToHandle(550, 590 + 40 * i, GetColor(255, 255, 255),Font01, "%d:%s atk:%d hp:%d", i, itemRef[player.having_item[i].ID].name, player.having_item[i].atk, player.having_item[i].hp);
	}
}