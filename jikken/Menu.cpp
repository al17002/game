#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"
char s[5][20] = { "ソード","a","i","u","e" };
//更新
void Menu_Update() {
	char c[20];
	if (CheckHitKey(KEY_INPUT_G) != 0) {//Gキーが押されていたら
		SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}
	if (CheckHitKey(KEY_INPUT_H) != 0) {
		DrawString(20, 280, "変更したい装備をプッシュ", GetColor(255, 255, 255));
	}
	//	if (CheckHitKey(KEY_INPUT_2) != 0) {
	//		SceneMgr_ChangeScene();
	//	}
}

//描画
void Menu_Draw() {
	DrawString(20, 20, "メニュー", GetColor(255, 255, 255));
	DrawString(20, 40, "G:ゲーム画面に戻る", GetColor(255, 255, 255));
	DrawString(20, 60, "H:装備変更", GetColor(255, 255, 255));
	DrawString(20, 80, "S:セーブデータ保存", GetColor(255, 255, 255));
	DrawString(20, 160, "装備情報", GetColor(255, 255, 255));
	//s = "キャラクタ管理部の関数";
	DrawFormatString(20, 180, GetColor(255, 255, 255), "1:%s", s[0]);
	DrawFormatString(20, 200, GetColor(255, 255, 255), "2:%s", s[1]);
	DrawFormatString(20, 220, GetColor(255, 255, 255), "3:%s", s[2]);
	DrawFormatString(20, 240, GetColor(255, 255, 255), "4:%s", s[3]);
	DrawFormatString(20, 260, GetColor(255, 255, 255), "5:%s", s[4]);
}