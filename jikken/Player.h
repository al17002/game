#pragma once

// 初期化をする
void Player_Initialize();

// 動きを計算する
void Player_Update();

// 描画する
void Player_Draw();

// 終了処理をする
void Player_Finalize();

void Death_Update();
void Death_Draw();
void Win_Update();
void Win_Draw();