#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Player.h"
#include "Keyboard.h"
#include "Map.h"
#include "EnemyMgr.h"
#include "Savedata.h"

bool turn = true;//ターン(Global) True = player false = enemy

typedef struct {
	int x, y, img;
}ch_t;

//更新
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_M) != 0) { //Mキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
	if (CheckHitKey(KEY_INPUT_W) != 0) { //Wキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをゲーム遷移に変更
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
	DrawString(1250, 40, "ゲーム画面", GetColor(255, 255, 255));
	DrawFormatString(1250, 60, GetColor(255, 255, 255), "Mキーを押すと\nメニュー画面に移動します。\nWボタンを押すと\nゲーム遷移画面へ戻ります");
	DrawFormatString(1250, 150, GetColor(255, 255, 255), "現在は%d階層目です",1);
	DrawFormatString(1250, 200, GetColor(255, 255, 255), "装備中:%d atk: %d hp: %d", player_item.equipment.ID, player_item.equipment.atk, player_item.equipment.hp);
}