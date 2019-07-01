#pragma once

//階層の更新
void floor_renew(int map_id);

//アイテムイベントの発生
void item_event(int n);

//フロアイベントの発生
void floor_event(int n);

//進めるかを判定する
int IsAbleToGo(int x, int y, int muki);

//画像の読み込み
void Floor_Initialize();

//描画
void Map_Draw();

//マップの読み込み
void load_map(int map_id);