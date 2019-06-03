#pragma once

typedef struct player_item {
	int item[0];
	int item[1];
	int item[2];
	int item[3];
	int item[4];
	int item[5];
	int item[6];
	int item[7];
	int item[8];
	int item[9];
	int item[10];
}; //[アイテムid]の数。


typedef struct player_alldata {
	player_item having_item;  //所持しているアイテム
	player_item stored_item; //倉庫にあるアイテム
	int equipment;  //装備しているアイテムのID
};

typedef struct player_data {
	player_item having_item;
	int equipment;
	int change_status; //装備してるアイテムによる変化値
	int y; //playerのｙ座標
	int x; //x座標

};

extern player_alldata player_all_of_data; //すべてのファイルで使えるグローバル変数宣言。他の名前が思いつかなかった。
