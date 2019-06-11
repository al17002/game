#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
char u[5][20] = { "ソード","シールド","u","e","o" };//暫定的なセーブデータ
//更新
void Save_Update() {
	if (CheckHitKey(KEY_INPUT_M) != 0) { //Tを選択
		SceneMgr_ChangeScene(eScene_Menu);//タイトルに戻る
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) { //Tを選択
		SceneMgr_ChangeScene(eScene_Title);//タイトルに戻る
	}
	if (CheckHitKey(KEY_INPUT_1) != 0) { //1を選択
		//GetSavedata();
		SceneMgr_ChangeScene(eScene_Title);//セーブデータ1を選択してゲームを開始
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2を選択
		//GetSavedata(2);
		SceneMgr_ChangeScene(eScene_Title);//セーブデータ2を選択してゲームを開始
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3を選択
		//GetSaveData(3);
		SceneMgr_ChangeScene(eScene_Title);//セーブデータ3を選択してゲームを開始
	}
}

//描画
void Save_Draw() {
	DrawString(0, 0, "セーブ保存画面(番号をプッシュしてセーブデータを保存)", GetColor(255, 255, 255));
	DrawString(0, 20, "M:メニュー画面に戻る", GetColor(255, 255, 255));
	DrawString(0, 40, "T:タイトルに移動", GetColor(255, 255, 255));
	DrawString(0, 60, "1.アイテム情報", GetColor(255, 255, 255));//データ1アイテム情報
	//s = ;//セーブデータ呼び出し
	DrawFormatString(20, 80, GetColor(255, 255, 255), "1:%s", u[0]);
	DrawFormatString(20, 100, GetColor(255, 255, 255), "2:%s", u[1]);
	DrawFormatString(20, 120, GetColor(255, 255, 255), "3:%s", u[2]);
	DrawFormatString(20, 140, GetColor(255, 255, 255), "4:%s", u[3]);
	DrawFormatString(20, 160, GetColor(255, 255, 255), "5:%s", u[4]);

	DrawString(0, 200, "2.アイテム情報", GetColor(255, 255, 255));//データ2アイテム情報
	//s = ;//セーブデータ呼び出し
	DrawFormatString(20, 220, GetColor(255, 255, 255), "1:%s", u[0]);
	DrawFormatString(20, 240, GetColor(255, 255, 255), "2:%s", u[1]);
	DrawFormatString(20, 260, GetColor(255, 255, 255), "3:%s", u[2]);
	DrawFormatString(20, 280, GetColor(255, 255, 255), "4:%s", u[3]);
	DrawFormatString(20, 300, GetColor(255, 255, 255), "5:%s", u[4]);
	//s=;//セーブデータ呼び出し
	DrawString(0, 340, "3.アイテム情報", GetColor(255, 255, 255));//データ3アイテム情報
	DrawFormatString(20, 360, GetColor(255, 255, 255), "1:%s", u[0]);
	DrawFormatString(20, 380, GetColor(255, 255, 255), "2:%s", u[1]);
	DrawFormatString(20, 400, GetColor(255, 255, 255), "3:%s", u[2]);
	DrawFormatString(20, 420, GetColor(255, 255, 255), "4:%s", u[3]);
	DrawFormatString(20, 440, GetColor(255, 255, 255), "5:%s", u[4]);
}