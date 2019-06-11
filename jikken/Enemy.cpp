#include "DxLib.h"
#include "Keyboard.h"
#include "Enemy.h"
#include "Map.h"
#include "Game.h"

// 初期化をする
void Enemy_Initialize(Enemy_t *Enemy,int x, int y, int *img) {
	for (int i = 0; i < 16; i++) {
		Enemy->Image[i] = img[i];
	}
	Enemy->m_Image = img[(x % 32 + y % 32) / 8 + Enemy->muki * 4];    //画像ハンドルの格納
	Enemy->y = y;      //y座標格納
	Enemy->x = x;		//x座標格納
}


// 動きを計算する
bool Enemy_Update(Enemy_t *Enemy) {
	if (Enemy->x % 32 == 0 && Enemy->y % 32 == 0&&!turn) {//座標が32で割り切れたら入力可能　ターンがなければ動けない
		Enemy->walking_flag = 1;         //歩くフラグを立てる。
		if (Keyboard_Get(KEY_INPUT_UP) == 1)  //上ボタンが押されたら
			Enemy->muki = 0;         //上向きフラグを立てる
		else if (Keyboard_Get(KEY_INPUT_LEFT) == 1)  //左ボタンが押されたら
			Enemy->muki = 1;         //左向きフラグを立てる
		else if (Keyboard_Get(KEY_INPUT_DOWN) == 1)  //下ボタンが押されたら
			Enemy->muki = 2;         //下向きフラグを立てる
		else if (Keyboard_Get(KEY_INPUT_RIGHT) == 1)  //右ボタンが押されたら
			Enemy->muki = 3;         //右向きフラグを立てる
		else                                    //何のボタンも押されてなかったら
			Enemy->walking_flag = 0; //歩かないフラグを立てる

		if (Enemy->walking_flag == 1)
			if (IsAbleToGo(Enemy->x, Enemy->y, Enemy->muki) == 1)
				Enemy->walking_flag = 0;
	}

	if (Enemy->walking_flag == 1) {        //歩くフラグが立っていたら
		if (Enemy->muki == 0)        //上向きならch.y座標を減らす
			Enemy->y-=8;
		else if (Enemy->muki == 1)        //左向きならch.x座標を減らす
			Enemy->x-=8;
		else if (Enemy->muki == 2)        //下向きならch.y座標を増やす
			Enemy->y+=8;
		else if (Enemy->muki == 3)        //右向きならch.x座標を増やす
			Enemy->x+=8;
		if (Enemy->x % 32 == 0 && Enemy->y % 32 == 0) {
			return false; //目的地に到着、ターン終了のためfalseを返す
		}
		else
			return true; //まだ行動中
	}
}

// 描画する
void Enemy_Draw(Enemy_t Enemy) {
	Enemy.m_Image = Enemy.Image[(Enemy.x % 32 + Enemy.y % 32) / 8 + Enemy.muki * 4];
	DrawGraph(Enemy.x, Enemy.y, Enemy.m_Image, TRUE);
}

// 終了処理をする
void Enemy_Finalize(Enemy_t Enemy) {
}
