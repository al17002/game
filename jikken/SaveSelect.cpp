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
		//output_savedata(1);
		SceneMgr_ChangeScene(eScene_Title);//セーブデータ1を選択してゲームを開始
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2を選択
		//output_savedata(2);
		SceneMgr_ChangeScene(eScene_Title);//セーブデータ2を選択してゲームを開始
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3を選択
		//output_savedata(3);
		SceneMgr_ChangeScene(eScene_Title);//セーブデータ3を選択してゲームを開始
	}
}

//描画
void SaveSelect_Draw() {
	int i, j, k;
	DrawString(0, 0, "セーブ選択画面(番号をプッシュしてセーブデータを選択)", GetColor(255, 255, 255));
	DrawString(0, 20, "T:タイトル画面に戻る", GetColor(255, 255, 255));
	DrawString(0, 40, "1.アイテム情報", GetColor(255, 255, 255));//データ1アイテム情報
	input_savedata(0);
	for (i = 0; i < 10; i++) {//範囲はplayer_item.itemnum
		DrawFormatString(20, 60 + 20 * i, GetColor(255, 255, 255), "%d:%d hp:%d", i, player_item.having_item[i].ID, player_item.having_item[i].hp);
	}
	DrawString(0, 260, "2.アイテム情報", GetColor(255, 255, 255));//データ2アイテム情報
	input_savedata(0);
	for (i = 0; i < 10; i++) {
		DrawFormatString(20, 280 + 20 * i, GetColor(255, 255, 255), "%d:%d hp:%d", i, player_item.having_item[i].ID);
	}
	DrawString(0, 480, "3.アイテム情報", GetColor(255, 255, 255));//データ2アイテム情報
	input_savedata(0);
	for (i = 0; i < 10; i++) {
		DrawFormatString(20, 500 + 20 * i, GetColor(255, 255, 255), "%d:%d hp:%d", i, player_item.having_item[i].ID);
	}
}
	