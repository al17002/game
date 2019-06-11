#ifndef DEF_EnemyMGR_H //二重include防止

#define DEF_EnemyMGR_H

// 初期化をする
void EnemyMgr_Initialize();

// 動きを計算する
void EnemyMgr_Update();

// 描画する
void EnemyMgr_Draw();

// 終了処理をする
void EnemyMgr_Finalize();

#endif