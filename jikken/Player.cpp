#include "DxLib.h"
#include "Player.h"
#include "Keyboard.h"
#include "Map.h"
#include "Game.h"
#include "Savedata.h"

// このファイル内でしか使えないグローバル変数
static int m_Image; //画像ハンドル
static int walking_flag;
static int muki;
static int image[16];

// 初期化をする
void Player_Initialize() {
	LoadDivGraph("画像/キャラクタ10.png", 16, 4, 4, 32, 32, image);
	m_Image = image[(m_x % 32 + m_y % 32) / 8 + muki * 4];
	player.x = 320;
	player.y = 160;
}

// 動きを計算する
void Player_Update() {
	if (m_x % 32 == 0 && m_y % 32 == 0) {//座標が32で割り切れたら入力可能　ターンがない限り動けない
		
		walking_flag = 0;         //止まるフラグを立てる。
		if (turn) {//ターンがある（ぷれいやー)
			walking_flag = 1;
			if (Keyboard_Get(KEY_INPUT_UP) == 1)  //上ボタンが押されたら
				muki = 0;         //上向きフラグを立てる
			else if (Keyboard_Get(KEY_INPUT_LEFT) == 1)  //左ボタンが押されたら
				muki = 1;         //左向きフラグを立てる
			else if (Keyboard_Get(KEY_INPUT_DOWN) == 1)  //下ボタンが押されたら
				muki = 2;         //下向きフラグを立てる
			else if (Keyboard_Get(KEY_INPUT_RIGHT) == 1)  //右ボタンが押されたら
				muki = 3;         //右向きフラグを立てる
			else                                    //何のボタンも押されてなかったら
				walking_flag = 0; //歩かないフラグを立てる

			if (walking_flag == 1)
				if (IsAbleToGo(m_x, m_y, muki) == 1) {
					walking_flag = 0;
					turn = false;
				}
		}
	}

	if (walking_flag == 1) {        //歩くフラグが立っていたら
		if (muki == 0)        //上向きならch.y座標を減らす
			move_player(0, -8);
		else if (muki == 1)        //左向きならch.x座標を減らす
			move_player(-8, 0);
		else if (muki == 2)        //下向きならch.y座標を増やす
			move_player(0, 8);
		else if (muki == 3)        //右向きならch.x座標を増やす
			move_player(8, 0);

		if (m_x % 32 == 0 && m_y % 32 == 0) {
			turn = false; //目的地に到着、ターンを渡す
		}
	}
}

// 描画する
void Player_Draw() {
	m_Image = image[(m_x % 32 + m_y % 32) / 8 + muki * 4];
	DrawGraph(m_x, m_y, m_Image, TRUE);
}

// 終了処理をする
void Player_Finalize() {
	DeleteGraph(m_Image);
}
