#include "DxLib.h"
#include "Keyboard.h"
#include "Enemy.h"
#include "Map.h"


// 初期化をする
void Enemy_Initialize(Enemy_t *Enemy,int x, int y, int img) {
	Enemy->Image = img;    //画像ハンドルの格納
	Enemy->y = y;      //y座標格納
	Enemy->x = x;		//x座標格納
}


// 動きを計算する
void Enemy_Update(Enemy_t *Enemy) {/*
	int r = 0;
	int walking_flag = 0;
	int muki = 0;
	if (Enemy->x % 32 == 0 && Enemy->y % 32 == 0) {         //座標が32で割り切れたら入力可能
		walking_flag = 1;         //歩くフラグを立てる。
		if (r == 0)  //上ボタンが押されたら
			muki = 0;         //上向きフラグを立てる
		else if (r == 1)  //左ボタンが押されたら
			muki = 1;         //左向きフラグを立てる
		else if (r == 2)  //下ボタンが押されたら
			muki = 2;         //下向きフラグを立てる
		else if (r == 3)  //右ボタンが押されたら
			muki = 3;         //右向きフラグを立てる
		else                                    //何のボタンも押されてなかったら
			walking_flag = 0; //歩かないフラグを立てる

		if (walking_flag == 1)
			if (IsAbleToGo(Enemy->x, Enemy->y, muki) == 1)
				walking_flag = 0;
	}

	if (walking_flag == 1) {        //歩くフラグが立っていたら
		if (muki == 0)        //上向きならch.y座標を減らす
			Enemy->y--;
		else if (muki == 1)        //左向きならch.x座標を減らす
			Enemy->x--;
		else if (muki == 2)        //下向きならch.y座標を増やす
			Enemy->y++;
		else if (muki == 3)        //右向きならch.x座標を増やす
			Enemy->x++;
	}*/
	Enemy->y--;

}

// 描画する
void Enemy_Draw(Enemy_t Enemy) {
	DrawGraph(Enemy.x, Enemy.y, Enemy.Image, TRUE);
}

// 終了処理をする
void Enemy_Finalize(Enemy_t Enemy) {
}
