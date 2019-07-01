#include "DxLib.h"
#include "Keyboard.h"
#include "Enemy.h"
#include "Map.h"
#include "Game.h"
#include "Savedata.h"
#include "hitJudgment.h"

// 初期化をする
void Enemy_Initialize(Enemy_t *Enemy,int x, int y, int *img,int num) {
	Enemy->num = num;
	for (int i = 0; i < 16; i++) {
		Enemy->Image[i] = img[i];
	}
	Enemy->m_Image = img[(x % 32 + y % 32) / 8 + Enemy->muki * 4];    //画像ハンドルの格納
	Enemy->y = y;      //y座標格納
	Enemy->x = x;		//x座標格納
	Enemy->muki = 0;
	Enemy->walking_flag = 0;
	Enemy->equipment.ID = 1;
	Enemy->equipment.atk = 1;
	Enemy->equipment.hp = 1;
	Enemy->enemy_turn = false;
	Enemy->alive = true;
}


// 動きを計算する ターンが終了する行動を取るとenemy_turnがtrueになりupdateされなくなる
void Enemy_Update(Enemy_t *Enemy) {
	if (Enemy->alive) {//aliveがfalseの場合は何も起こらない
		if (Enemy->x % 32 == 0 && Enemy->y % 32 == 0) {//座標が32で割り切れたら入力可能　ターンがなければ動けない
			Enemy->walking_flag = 0;         //歩かないフラグを立てる。
			if (!Enemy->enemy_turn) {//ターンがある（エネミー)
				Enemy->walking_flag = 1;
				if (player.y < Enemy->y && (IsAbleToGo(Enemy->x, Enemy->y, 0) != 1))  //上ボタンが押されたら
					Enemy->muki = 0;         //上向きフラグを立てる
				else if (player.x < Enemy->x && (IsAbleToGo(Enemy->x, Enemy->y, 1) != 1))  //左ボタンが押されたら
					Enemy->muki = 1;         //左向きフラグを立てる
				else if (player.y > Enemy->y && (IsAbleToGo(Enemy->x, Enemy->y, 2) != 1))  //下ボタンが押されたら
					Enemy->muki = 2;         //下向きフラグを立てる
				else if (player.x > Enemy->x && (IsAbleToGo(Enemy->x, Enemy->y, 3) != 1))  //右ボタンが押されたら
					Enemy->muki = 3;         //右向きフラグを立てる
				else                                    //何のボタンも押されてなかったら
					Enemy->walking_flag = 1; //まあ頑張って左に歩くフラグを立てる
			}
			if (Enemy->walking_flag == 1) {
				int hitcheck = hitJudgment(Enemy->muki, Enemy->num);
				if (hitcheck == -1) {//プレイヤーに当たった
					Enemy->walking_flag = 0;
					hit_player(Enemy->num);
					Enemy->enemy_turn = true;
				}
				else if (hitcheck != -2) {
					Enemy->walking_flag = 0;
					Enemy->enemy_turn = true;
				}
				if (IsAbleToGo(Enemy->x, Enemy->y, Enemy->muki) == 1) {
					Enemy->walking_flag = 0;
					Enemy->enemy_turn = true;
				}
			}
		}

		if (Enemy->walking_flag == 1) {//歩くフラグが立っていたら
			if (Enemy->muki == 0)        //上向きならch.y座標を減らす
				Enemy->y -= 8;
			else if (Enemy->muki == 1)        //左向きならch.x座標を減らす
				Enemy->x -= 8;
			else if (Enemy->muki == 2)        //下向きならch.y座標を増やす
				Enemy->y += 8;
			else if (Enemy->muki == 3)        //右向きならch.x座標を増やす
				Enemy->x += 8;
			if (Enemy->x % 32 == 0 && Enemy->y % 32 == 0) {
				Enemy->enemy_turn = true; //目的地に到着、ターン終了のためtrueに
			}
		}
	}
}

// 描画する
void Enemy_Draw(Enemy_t Enemy) {
	Enemy.m_Image = Enemy.Image[(Enemy.x % 32 + Enemy.y % 32) / 8 + Enemy.muki * 4];
	DrawGraph(Enemy.x, Enemy.y, Enemy.m_Image, true);
}

// 終了処理をする
void Enemy_Finalize(Enemy_t Enemy) {
}
