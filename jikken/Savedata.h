#pragma once
#include <iostream>
#include <string>

using namespace std;

void output_savedata(int num);
void input_savedata(int num);
int get_equipment();
void move_player(int move_x, int move_y);
void data_update(int event_id, int change_id, int item_hp, int change_num);

typedef struct item_desc{//アイテムの説明
	string name;
    string explain;
    string effect;
}item_desc;


item_desc itemRef[100]; //[アイテムid]

typedef struct item{
    int ID;
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
	int change_status; //装備による変化値
	int y; //playerの座標
	int x; 

}player_data;



extern player_item_data player_item; //グローバル変数
extern player_data player;

