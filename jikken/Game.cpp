#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Player.h"
#include "Keyboard.h"
#include "Map.h"
#include "EnemyMgr.h"

bool turn = true;//ターン(Global) True = player false = enemy

typedef struct {
	int x, y, img;
}ch_t;

//更新
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}

	Keyboard_Update();
	Player_Update();
	EnemyMgr_Update();

	Player_Draw();
	EnemyMgr_Draw();
	Map_Draw();

}

//描画
void Game_Draw() {
	DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
}