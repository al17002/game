#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"

//更新
void Title_Update() {
	if (CheckHitKey(KEY_INPUT_G) != 0) { //Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Game);//シーンをメニューに変更
	}
}

//描画
void Title_Draw() {
	DrawString(0, 0, "タイトル画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Gキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
}