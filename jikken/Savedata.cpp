#include "DxLib.h"
#include "Savedata.h"


player_all_of_data player_alldata;//他のファイルで使えるグローバル変数
player_data player;


void input_savedata(int num) {

	int i,n_int;
	char n_char[2];
	FILE *fp;
	
	if (num == 1) {
		fp=fopen("savedata1.txt", "r");
	}else if (num == 2) {
		fp = fopen("savedata2.txt", "r");
	}else {
		fp = fopen("new_savedata.txt", "r");//新しいセーブを作成の際のいい案が思いついてない
	}

	while (fgets(n_char,2,fp) != NULL) {
		n_int = atoi(n_char);
		if (i < 10)player_alldata.having_item.item[i] = n_int;
		else if(i < 20)player_alldata.stored_item.item[i-10] = n_int;
		else player_alldata.equipment= n_int;
	}

}

void data_flow() {
	//何をすべき関数なのかいまいちわからない
}

int get_equipment() {
	
	return player.equipment;
}

void move_player(int move_x,int move_y){
	//あんまり意味ない？
	player.x += move_x;
	player.y += move_y;
}

void data_update(int event_id,int change_id,int change_num) {
	int i;
	//event_idの使いどころはいまのところ未定
	for (i = 0; i < 10; i++) {
		if (change_id == i)player.having_item[i] += change_num;
	}
}

