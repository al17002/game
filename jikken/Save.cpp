#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Savedata.h"
#include "Title.h"

//更新
void Save_Update() {
	if (CheckHitKey(KEY_INPUT_W) != 0) { //Wを選択
		SceneMgr_ChangeScene(eScene_WareHouse);//メニューに戻る
	}
	if (CheckHitKey(KEY_INPUT_1) != 0) { //1を選択
		player_item = save_temp;
		output_savedata(1);
		//SceneMgr_ChangeScene(eScene_WareHouse);
		SceneMgr_ChangeScene(eScene_Save);//セーブデータ1を選択してセーブ
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2を選択
		player_item = save_temp;
		output_savedata(2);
		//SceneMgr_ChangeScene(eScene_WareHouse);
		SceneMgr_ChangeScene(eScene_Save);//セーブデータ2を選択してセーブ
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3を選択
		player_item = save_temp;
		output_savedata(3);
		//SceneMgr_ChangeScene(eScene_WareHouse);
		SceneMgr_ChangeScene(eScene_Save);//セーブデータ3を選択してセーブ
	}
}

//描画
void Save_Draw() {
	int i;
	DrawStringToHandle(350, 50, "セーブ保存画面(番号をプッシュしてセーブデータを保存)", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 150, "W:セーブ遷移画面に戻る", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(30, 300, "1.アイテム情報", GetColor(255, 255, 255),Font01);//データ1アイテム情報
	input_savedata(1);
	DrawFormatStringToHandle(30, 400, GetColor(255, 255, 255),Font01, "装備中:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	DrawStringToHandle(30, 500, "所持アイテム", GetColor(255, 255, 255), Font01);
	for (i = 0; i < 10; i++) {//範囲はplayer_item.itemnum
		DrawFormatStringToHandle(30, 550 + 40 * i, GetColor(255, 255, 255),Font01, "%d:%s atk:%d hp:%d", i, itemRef[player_item.having_item[i].ID].name, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
	DrawStringToHandle(530, 300, "2.アイテム情報", GetColor(255, 255, 255),Font01);//データ2アイテム情報
	input_savedata(2);
	DrawFormatStringToHandle(530, 400, GetColor(255, 255, 255),Font01, "装備中:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	DrawStringToHandle(530, 500, "所持アイテム", GetColor(255, 255, 255), Font01);
	for (i = 0; i < 10; i++) {
		DrawFormatStringToHandle(530, 550 + 40 * i, GetColor(255, 255, 255),Font01, "%d:%s atk:%d hp:%d", i, itemRef[player_item.having_item[i].ID].name, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
	DrawStringToHandle(1030, 300, "3.アイテム情報", GetColor(255, 255, 255),Font01);//データ2アイテム情報
	input_savedata(3);
	DrawFormatStringToHandle(1030, 400, GetColor(255, 255, 255),Font01, "装備中:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	DrawStringToHandle(1030, 500, "所持アイテム", GetColor(255, 255, 255), Font01);
	for (i = 0; i < 10; i++) {
		DrawFormatStringToHandle(1030, 550 + 40 * i, GetColor(255, 255, 255),Font01, "%d:%s atk:%d hp:%d", i, itemRef[player_item.having_item[i].ID].name, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
}