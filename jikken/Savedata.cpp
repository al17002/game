#include <iostream>
#include "Savedata.h"
#include "enemy.h"


player_item_data player_item;//グローバル変数
player_data player;
Enemy_t Enemy[];
item_desc itemRef[100];

void output_savedata(int num){//セーブ
    int i;
	FILE *fp;
	
	switch(num){
        case 1:
		    fopen_s(&fp,"savedata1.dat", "wb");
            break;
        case 2:
		    fopen_s(&fp, "savedata2.dat", "wb");
            break;
        case 3:
		    fopen_s(&fp, "savedata3.dat", "wb");
            break;
		default:
			fopen_s(&fp, "savedata1.dat", "wb");
			break;
	}

    for(i=0;i<10;i++){
        fwrite(&player_item.having_item[i].ID,sizeof(int),1,fp);
		fwrite(&player_item.having_item[i].atk, sizeof(int), 1, fp);
        fwrite(&player_item.having_item[i].hp,sizeof(int),1,fp);
    }

    fwrite(&player_item.itemnum,sizeof(int),1,fp);

    for(i=0;i<100;i++){

        fwrite(&player_item.stashed_item[i],sizeof(int),1,fp);
    }

    fwrite(&player_item.stashednum,sizeof(int),1,fp);
    fwrite(&player_item.equipment.ID,sizeof(int),1,fp);
	fwrite(&player_item.equipment.atk, sizeof(int), 1, fp);
    fwrite(&player_item.equipment.hp,sizeof(int),1,fp);
    

    fclose(fp);

}


void input_savedata(int num) {//ロード

	int i;
	FILE *fp;
	
	switch(num) {
        case 1:
		    fopen_s(&fp, "savedata1.dat", "rb");
            break;
        case 2:
		    fopen_s(&fp, "savedata2.dat", "rb");
            break;
		case 3:
			fopen_s(&fp, "savedata3.dat", "rb");
			break;
        default:
		    fopen_s(&fp, "new_savedata.dat", "rb");
            break;
	}
    

	for(i=0;i<10;i++){
        fread(&player_item.having_item[i].ID,sizeof(int),1,fp);
		fread(&player_item.having_item[i].atk,sizeof(int), 1, fp);
        fread(&player_item.having_item[i].hp,sizeof(int),1,fp);
    }

    fread(&player_item.itemnum,sizeof(int),1,fp);

    for(i=0;i<100;i++){

        fread(&player_item.stashed_item[i],sizeof(int),1,fp);
    }

    fread(&player_item.stashednum,sizeof(int),1,fp);
    fread(&player_item.equipment.ID,sizeof(int),1,fp);
	fread(&player_item.equipment.atk, sizeof(int), 1, fp);
    fread(&player_item.equipment.hp,sizeof(int),1,fp);
    fclose(fp);
    
}

//データの移し替え
void dataflow() {

	int i;

	for (i = 0; i < 10; i++) {
		player.having_item[i].ID = player_item.having_item[i].ID;
		player.having_item[i].atk = player_item.having_item[i].atk;
		player.having_item[i].hp = player_item.having_item[i].hp;
	}

	player.itemnum = player_item.itemnum;


	player.equipment.ID = player_item.equipment.ID;
	player.equipment.atk = player_item.equipment.atk;
	player.equipment.hp = player_item.equipment.hp;
}

//プレイヤーを移動
void move_player(int move_x,int move_y){

	player.x += move_x;
	player.y += move_y;
}

//アイテムを追加
void add_item(int n) {

	if (player.itemnum == 10) {

	}
	else {
		player.having_item[player.itemnum].ID = n - 10;
		player.having_item[player.itemnum].atk = 1;
		player.having_item[player.itemnum].hp = 1;
		player.itemnum += 1;
	}

}

//プレイヤーが敵を攻撃
void hit_enemy(int enemy_id) {
	m_Enemy[enemy_id].equipment.hp -= player.equipment.atk;
	if (m_Enemy[enemy_id].equipment.hp < 0) {//敵が死亡
		m_Enemy[enemy_id].y = -3200;
		m_Enemy[enemy_id].x = -3200;
		m_Enemy[enemy_id].enemy_turn = true;
		m_Enemy[enemy_id].alive = false;
	}
}

//敵がプレイヤーを攻撃
void hit_player(int enemy_id) {
	player.equipment.hp -= m_Enemy[enemy_id].equipment.atk;
}

//アイテムデータを出力
void output_itemdata() {
	int i;
	FILE *fp;

	fopen_s(&fp, "itemdata.dat", "wb");

	for (i = 0; i < 100; i++) {
		fread(itemRef[i].name, sizeof(char), sizeof(itemRef[i].name), fp);
		fread(itemRef[i].explain, sizeof(char), sizeof(itemRef[i].explain), fp);
		fread(itemRef[i].effect, sizeof(char), sizeof(itemRef[i].effect), fp);
		fread(&itemRef[i].atk, sizeof(int), 1, fp);
		fread(&itemRef[i].hp, sizeof(int), 1, fp);
	}

	fclose(fp);

}