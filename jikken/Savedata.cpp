#include <iostream>
#include "Savedata.h"


player_item_data player_item;//グローバル変数
player_data player;

void output_savedata(int num){//セーブ
    int i;
	FILE *fp;
	
	switch(num){
        case 1:
		    fopen_s(&fp,"savedata1.dat", "wb");
            break;
        case 2:
		    fopen_s(&fp, "savedata2.txt", "wb");
            break;
        case 3:
		    fopen_s(&fp, "savedata3.txt", "wb");
            break;
        default:
			fopen_s(&fp, "savedata1.dat", "wb");
            break;
	}

    //fp=fopen("savedata.txt","wb");
    //fp=fopen("savedata.dat","wb");


    for(i=0;i<10;i++){
        //fprintf(fp,"%d %d ",player_item.having_item[i].ID,player_item.having_item[i].hp);
        fwrite(&player_item.having_item[i].ID,sizeof(int),1,fp);
        fwrite(&player_item.having_item[i].hp,sizeof(int),1,fp);

    }
    //fprintf(fp,"\n");
    //fprintf(fp,"%d",player_item.itemnum);
    fwrite(&player_item.itemnum,sizeof(int),1,fp);
    //fprintf(fp,"\n");

    for(i=0;i<100;i++){
        //fprintf(fp,"%d ",player_item.stashed_item[i]);
        fwrite(&player_item.stashed_item[i],sizeof(int),1,fp);
        //if((i+1)%10==0)fprintf(fp,"\n");
    }
    //fprintf(fp,"%d ",player_item.stashednum);
    fwrite(&player_item.stashednum,sizeof(int),1,fp);
    //fprintf(fp,"\n");
    //fprintf(fp,"%d %d",player_item.equipment.ID,player_item.equipment.hp);
    fwrite(&player_item.equipment.ID,sizeof(int),1,fp);
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
        default:
		    fopen_s(&fp, "new_savedata.dat", "rb");
            break;
	}
    

    //fp=fopen("new_savedata.txt", "rb");
    fopen_s(&fp, "savedata.dat", "rb");

	for(i=0;i<10;i++){
        //fscanf(fp,"%d %d",&player_item.having_item[i].ID,&player_item.having_item[i].hp);
        fread(&player_item.having_item[i].ID,sizeof(int),1,fp);
        fread(&player_item.having_item[i].hp,sizeof(int),1,fp);
    }

    //fscanf(fp,"%d",&player_item.itemnum);
    fread(&player_item.itemnum,sizeof(int),1,fp);

    for(i=0;i<100;i++){
        //fscanf(fp,"%d",&player_item.stashed_item[i]);
        fread(&player_item.stashed_item[i],sizeof(int),1,fp);
    }

    //fscanf(fp,"%d",&player_item.stashednum);
    fread(&player_item.stashednum,sizeof(int),1,fp);
    //fscanf(fp,"%d %d",&player_item.equipment.ID,&player_item.equipment.hp);
    fread(&player_item.equipment.ID,sizeof(int),1,fp);
    fread(&player_item.equipment.hp,sizeof(int),1,fp);
    fclose(fp);
    output_savedata(1);
}



int get_equipment() {
	
	return player.equipment.ID;
}

void move_player(int move_x,int move_y){
	//プレイヤーを移動
	player.x += move_x;
	player.y += move_y;
}

void data_update(int event_id,int change_id,int item_hp,int change_num) {
	int i;
	//event_idの使いどころは未定

    switch (event_id){
        case 0://get item
            player.having_item[player.itemnum].ID=change_id;
            player.having_item[player.itemnum].ID=item_hp;
            player.itemnum+=change_num;
        break;
        case 1://hit enemy
            player.equipment.hp-=item_hp;
            if(player.equipment.hp==0){
                player.equipment.ID=0;
                player.itemnum-=1;
            }

        break;
        case 2://on the stairs
            /*player.flore+=1;


            */
        break;

    }
    
	
}
