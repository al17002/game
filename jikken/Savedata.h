#pragma once
#include <iostram>

typedef struct item_desc{//アイテムの説明など　メニュー画面から呼び出して確認する
	string name;
    string explain;
    string effect;
}


item_desc itemRef[100]; //[アイテムid]

typedef struct item{
    int ID;
    int hp;
}

typedef struct player_item_data{
	item having_item;  //所持しているアイテム
	int stashed_item [100]; //倉庫にあるアイテムのID
	int equipment;  //装備しているアイテムのID
    int itemnum;
};

typedef struct player_data {
	item having_item;
	int equipment;
	int change_status; //装備してるアイテムによる変化値
	int y; //playerのｙ座標
	int x; //x座標

};


extern player_item_data player_item; //すべてのファイルで使えるグローバル変数宣言。他の名前が思いつかなかった。
extern player_data player;
