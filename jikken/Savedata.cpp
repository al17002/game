#include <iostream>
#include "Savedata.h"
#include "enemy.h"
#include "hitJudgment.h"
#include "SceneMgr.h"


player_item_data player_item;//グローバル変数
player_data player;
Enemy_t Enemy[];
item_desc itemRef[100];


void output_savedata(int num){//セーブ
    int i;
	FILE *fp;
	char *filename;
	
	switch(num){
        case 1:
			filename = "savedata1.dat";
		    //fopen_s(&fp,"savedata1.dat", "wb");
            break;
        case 2:
			filename = "savedata2.dat";
		    //fopen_s(&fp, "savedata2.dat", "wb");
            break;
        case 3:
			filename = "savedata3.dat";
		    //fopen_s(&fp, "savedata3.dat", "wb");
            break;
		default:
			filename = "savedata1.dat";
			//fopen_s(&fp, "savedata1.dat", "wb");
			break;
	}

	fopen_s(&fp, filename, "wb");
	fclose(fp);

	fopen_s(&fp, filename, "wb");

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
		player.having_item[i] = player_item.having_item[i];
	}

	player.itemnum = player_item.itemnum;


	player.equipment = player_item.equipment;
}

void back_dataflow() {

	int i;

	for (i = 0; i < 10; i++) {
		player_item.having_item[i] = player.having_item[i];
	}

	player_item.itemnum = player.itemnum;


	player_item.equipment = player.equipment;

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
		player.having_item[player.itemnum].atk = itemRef[player.having_item[player.itemnum].ID].atk;
		player.having_item[player.itemnum].hp = itemRef[player.having_item[player.itemnum].ID].hp;
		player.itemnum += 1;
	}
}

//プレイヤーが敵を攻撃
void hit_enemy(int enemy_id) {
	m_Enemy[enemy_id].equipment.hp -= player.equipment.atk;
	if (m_Enemy[enemy_id].equipment.hp < 0) {//敵が死亡
		removeHitbox(m_Enemy[enemy_id].y, m_Enemy[enemy_id].x);
		m_Enemy[enemy_id].y = 0;
		m_Enemy[enemy_id].x = 0;
		m_Enemy[enemy_id].enemy_turn = true;
		m_Enemy[enemy_id].alive = false;
	}
}

//敵がプレイヤーを攻撃
void hit_player(int enemy_id) {
	player.equipment.hp -= m_Enemy[enemy_id].equipment.atk;
	if (player.equipment.hp <= 0) {//プレイヤーの装備が壊れる
		if (player.having_item[0].ID != 0) {
			player.equipment = player.having_item[0];
			player.itemnum -= 1;
			for (int i = 0; i < 9; i++) {
				player.having_item[i] = player.having_item[i + 1];
			}
		}else {
			player.equipment.ID = 1;
			player.equipment.hp = itemRef[player.equipment.ID].hp;
			player.equipment.atk = itemRef[player.equipment.ID].atk;
			SceneMgr_ChangeScene(eScene_Death);
		}
	}
	
	
}


//アイテムデータを出力
void output_itemdata() {
	int i;
	FILE *fp;

	fopen_s(&fp, "item.dat", "rb");

	for (i = 0; i < 100; i++) {
		fread(itemRef[i].name, sizeof(char), sizeof(itemRef[i].name), fp);
		fread(itemRef[i].explain, sizeof(char), sizeof(itemRef[i].explain), fp);
		fread(itemRef[i].effect, sizeof(char), sizeof(itemRef[i].effect), fp);
		fread(&itemRef[i].atk, sizeof(int), 1, fp);
		fread(&itemRef[i].hp, sizeof(int), 1, fp);
	}

	fclose(fp);

}