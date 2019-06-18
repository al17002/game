#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef struct item_desc{//アイテムの説明
	string name;
    string explain;
    string effect;
	int atk;
	int hp;
}item_desc;


extern item_desc itemRef[100]; //[アイテムid]

typedef struct item{
    int ID;
	int atk;
    int hp;
}item;

typedef struct player_item_data{
	item having_item[10];  //所持しているアイテム
	int itemnum;
	int stashed_item [100]; //倉庫にあるアイテムのID
	int stashednum;
	item equipment;  //装備しているアイテム
    
}player_item_data;

typedef struct player_data {
	item having_item[10];
	int itemnum;
	item equipment;
	int y; //playerの座標
	int x; 

}player_data;


extern player_item_data player_item; //グローバル変数
extern player_data player;

