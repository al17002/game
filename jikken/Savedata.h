#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef struct item_desc{//繧｢繧､繝�繝�縺ｮ隱ｬ譏弱↑縺ｩ縲繝｡繝九Η繝ｼ逕ｻ髱｢縺九ｉ蜻ｼ縺ｳ蜃ｺ縺励※遒ｺ隱阪☆繧�
	string name;
    string explain;
    string effect;
}item_desc;


item_desc itemRef[100]; //[繧｢繧､繝�繝�id]

typedef struct item{
    int ID;
    int hp;
}item;

typedef struct player_item_data{
	item having_item[10];  //謇謖√＠縺ｦ縺�繧九い繧､繝�繝�
	int itemnum;
	int stashed_item [100]; //蛟牙ｺｫ縺ｫ縺ゅｋ繧｢繧､繝�繝�縺ｮID
	int stashednum;
	item equipment;  //陬�蛯吶＠縺ｦ縺�繧九い繧､繝�繝�縺ｮID
    
}player_item_data;

typedef struct player_data {
	item having_item[10];
	int itemnum;
	item equipment;
	int change_status; //陬�蛯吶＠縺ｦ繧九い繧､繝�繝�縺ｫ繧医ｋ螟牙喧蛟､
	int y; //player縺ｮ�ｽ吝ｺｧ讓�
	int x; //x蠎ｧ讓�

}player_data;


extern player_item_data player_item; //縺吶∋縺ｦ縺ｮ繝輔ぃ繧､繝ｫ縺ｧ菴ｿ縺医ｋ繧ｰ繝ｭ繝ｼ繝舌Ν螟画焚螳｣險縲ゆｻ悶�ｮ蜷榊燕縺梧昴＞縺､縺九↑縺九▲縺溘�
extern player_data player;

