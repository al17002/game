#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"

//更新
void Menu_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) {//Gキーが押されていたら
		SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}
}

//描画
void Menu_Draw() {
	DrawString(0, 0, "メニュー画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Gキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
}