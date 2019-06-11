#include "DxLib.h"
#include "Keyboard.h"
#include "Enemy.h"

static const int NUM = 2;        //プレイヤーの数

static Enemy_t m_Enemy[NUM];   //プレイヤーの実体
static int m_ImgEnemy;          //プレイヤーの画像ハンドル
static int image[16];

// 初期化をする
void EnemyMgr_Initialize() {
	LoadDivGraph("画像/キャラクタ10.png", 16, 4, 4, 32, 32, image);
	Enemy_Initialize(&m_Enemy[0], 160,160, image);// 初期化
	Enemy_Initialize(&m_Enemy[1], 320,320, image);// 初期化
}

// 動きを計算する
void EnemyMgr_Update() {
	for (int i = 0; i < NUM; i++) {
		Enemy_Update(&m_Enemy[i]);//更新
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
