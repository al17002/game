#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Savedata.h"

//更新
void SaveSelect_Update() {
	if (CheckHitKey(KEY_INPUT_T) != 0) { //Tを選択
		SceneMgr_ChangeScene(eScene_Title);//タイトルに戻る
	}
	if (CheckHitKey(KEY_INPUT_1) != 0) { //1を選択
		output_savedata(0);//セーブデータ1をもう一回呼ぶ
		SceneMgr_ChangeScene(eScene_Game);//セーブデータ1を選択してゲームを開始
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2を選択
		output_savedata(0);//セーブデータ2をもう一回呼ぶ
		SceneMgr_ChangeScene(eScene_Game);//セーブデータ2を選択してゲームを開始
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3を選択
		SceneMgr_ChangeScene(eScene_Game);//セーブデータ3を選択してゲームを開始
	}
}

//描画
void SaveSelect_Draw() {
	int i;
	DrawString(0, 0, "セーブ選択画面(番号をプッシュしてセーブデータを選択)", GetColor(255, 255, 255));
	DrawString(0, 20, "T:タイトル画面に戻る", GetColor(255, 255, 255));
	DrawString(0, 60, "1.アイテム情報", GetColor(255, 255, 255));//データ1アイテム情報
	input_savedata(0);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "装備中:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {//範囲はplayer_item.itemnum
		DrawFormatString(0, 100 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
	DrawString(0, 320, "2.アイテム情報", GetColor(255, 255, 255));//データ2アイテム情報
	input_savedata(0);
	DrawFormatString(0, 340, GetColor(255, 255, 255), "装備中:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {
		DrawFormatString(0, 360 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
	DrawString(0, 580, "3.アイテム情報", GetColor(255, 255, 255));//データ2アイテム情報
	input_savedata(0);
	DrawFormatString(0, 600, GetColor(255, 255, 255), "装備中:%d atk:%d hp:%d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
	for (i = 0; i < 10; i++) {
		DrawFormatString(0, 620 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player_item.having_item[i].ID,player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
}
	