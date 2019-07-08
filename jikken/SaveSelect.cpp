#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Savedata.h"
#include "Title.h"
int Font1;


//更新
void SaveSelect_Update() {
	if (CheckHitKey(KEY_INPUT_T) != 0) { //Tを選択
		SceneMgr_ChangeScene(eScene_Title);//タイトルに戻る
	}
	if (CheckHitKey(KEY_INPUT_1) != 0) { //1を選択
		input_savedata(1);//セーブデータ1をもう一回呼ぶ
		//dataflow();
		SceneMgr_ChangeScene(eScene_WareHouse);//セーブデータ1を選択してゲームを開始
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2を選択
		input_savedata(2);//セーブデータ2をもう一回呼ぶ
		//dataflow();
		SceneMgr_ChangeScene(eScene_WareHouse);//セーブデータ2を選択してゲームを開始
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3を選択
		input_savedata(3);//セーブデータ3をもう一回呼ぶ
		//dataflow();
		SceneMgr_ChangeScene(eScene_WareHouse);//セーブデータ3を選択してゲームを開始
	}
}

//描画
void SaveSelect_Draw() {
	int i;
	DrawStringToHandle(325, 50, "セーブ選択画面(番号をプッシュしてセーブデータを選択)", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 150, "T:タイトル画面に戻る", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(30, 300, "1.アイテム情報", GetColor(255, 255, 255),Font01);//データ1アイテム情報
	input_savedata(1);
	DrawFormatStringToHandle(30, 370, GetColor(255, 255, 255),Font01, "装備中:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	DrawStringToHandle(30, 440, "所持アイテム", GetColor(255, 255, 255), Font01);
	for (i = 0; i < 10; i++) {//範囲はplayer_item.itemnum
		DrawFormatStringToHandle(30, 490 + 40 * i, GetColor(255, 255, 255),Font01 ,"%d:%s atk:%d hp:%d", i, itemRef[player_item.having_item[i].ID].name, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
	DrawStringToHandle(530, 300, "2.アイテム情報", GetColor(255, 255, 255),Font01);//データ2アイテム情報
	input_savedata(2);
	DrawFormatStringToHandle(530,370, GetColor(255, 255, 255),Font01, "装備中:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	DrawStringToHandle(530, 440, "所持アイテム", GetColor(255, 255, 255), Font01);
	for (i = 0; i < 10; i++) {
		DrawFormatStringToHandle(530, 490 + 40 * i, GetColor(255, 255, 255),Font01, "%d:%s atk:%d hp:%d", i, itemRef[player_item.having_item[i].ID].name, player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
	DrawStringToHandle(1030, 300, "3.アイテム情報", GetColor(255, 255, 255),Font01);//データ2アイテム情報
	input_savedata(3);
	DrawFormatStringToHandle(1030, 370, GetColor(255, 255, 255),Font01,"装備中:%s atk:%d hp:%d", itemRef[player_item.equipment.ID].name, player_item.equipment.atk, player_item.equipment.hp);
	DrawStringToHandle(1030, 440, "所持アイテム", GetColor(255, 255, 255), Font01);
	for (i = 0; i < 10; i++) {
		DrawFormatStringToHandle(1030, 490 + 40 * i, GetColor(255, 255, 255),Font01, "%d:%s atk:%d hp:%d", i, itemRef[player_item.having_item[i].ID].name,player_item.having_item[i].atk, player_item.having_item[i].hp);
	}
}
	