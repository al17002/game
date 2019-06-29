#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Savedata.h"
player_item_data genzai;
//更新
void Save_Update() {
	if (CheckHitKey(KEY_INPUT_W) != 0) { //Wを選択
		SceneMgr_ChangeScene(eScene_WareHouse);//メニューに戻る
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) { //Tを選択
		SceneMgr_ChangeScene(eScene_Title);//タイトルに戻る
	}
	if (CheckHitKey(KEY_INPUT_1) != 0) { //1を選択
		player_item = genzai;
		output_savedata(1);
		SceneMgr_ChangeScene(eScene_Save);//セーブデータ1を選択してセーブ
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2を選択
		player_item = genzai;
		output_savedata(1);
		SceneMgr_ChangeScene(eScene_Save);//セーブデータ2を選択してセーブ
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3を選択
		player_item = genzai;
		output_savedata(1);
		SceneMgr_ChangeScene(eScene_Save);//セーブデータ3を選択してセーブ
	}
}

//描画
void Save_Draw() {
	int i;
	genzai=player_item;
	DrawString(0, 0, "セーブ保存画面(番号をプッシュしてセーブデータを保存)", GetColor(255, 255, 255));
	DrawString(0, 20, "W:ゲーム遷移画面に戻る", GetColor(255, 255, 255));
	DrawString(0, 80, "1.アイテム情報", GetColor(255, 255, 255));//データ1アイテム情報
	input_savedata(1);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "装備中:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {//範囲はplayer_item.itemnum
		DrawFormatString(0, 120 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk,player_item.having_item[i].hp);
	}
	DrawString(0, 340, "2.アイテム情報", GetColor(255, 255, 255));//データ2アイテム情報
	input_savedata(1);
	DrawFormatString(0, 360, GetColor(255, 255, 255), "装備中:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {
		DrawFormatString(0, 380 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk,player_item.having_item[i].hp);
	}
	DrawString(0, 600, "3.アイテム情報", GetColor(255, 255, 255));//データ2アイテム情報
	input_savedata(1);
	DrawFormatString(0, 620, GetColor(255, 255, 255), "装備中:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {
		DrawFormatString(0, 640 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk,player_item.having_item[i].hp);
	}
}