#include "DxLib.h"
#include "Keyboard.h"
#include "Enemy.h"
#include "Map.h"
#include "Game.h"

static const int NUM = 2;        //敵の数

static Enemy_t m_Enemy[NUM];   //敵の実体
static int m_ImgEnemy;          //敵の画像ハンドル
static int image[16];

static bool inturn = false;
static bool check = false;

// 初期化をする
void EnemyMgr_Initialize() {
	LoadDivGraph("画像/キャラクタ10.png", 16, 4, 4, 32, 32, image);
	Enemy_Initialize(&m_Enemy[0], 288,320, image);// 初期化
	Enemy_Initialize(&m_Enemy[1], 320,320, image);// 初期化
}

// 動きを計算する
void EnemyMgr_Update() {
	if (!turn) {
		if (!inturn) {
			inturn = true;
			for (int i = 0; i < NUM; i++) {
				m_Enemy[i].enemy_turn = false;
			}
		}
		check = true;//この後の処理でcheckが変わらなければターンは終わっている
		for (int i = 0; i < NUM; i++) {
			Enemy_Update(&m_Enemy[i]);
			if (!m_Enemy[i].enemy_turn) {
				check = false;
			}
		}
		if (check) {
			inturn = false;
			turn = true;
		}

	}
}

// 描画する
void EnemyMgr_Draw() {
	for (int i = 0; i < NUM; i++) {
		Enemy_Draw(m_Enemy[i]);//描画
	}
}

// 終了処理をする
void EnemyMgr_Finalize() {
	for (int i = 0; i < NUM; i++) {
		Enemy_Finalize(m_Enemy[i]);//終了処理
	}

	DeleteGraph(m_ImgEnemy);    //画像を解放
}
