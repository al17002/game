#pragma once

//階層の更新
void floor_renew(int map_id);

//アイテムイベントの発生
void item_event(int n);

//フロアイベントの発生
void floor_event(int n);

//進めるかを判定する
int IsAbleToGo(int x, int y, int muki,bool player);

//画像の読み込み
void Floor_Initialize();

//描画
void Map_Draw();

//プレイヤーの周囲以外黒を描画
void Map_Draw_Surround();

//マップの読み込み
void load_map(int map_id);

//敵の座標を計算する
void calcenemy(int *x, int *y);