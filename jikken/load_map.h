//load_map.h


#ifndef LOAD_MAP_H
#define LOAD_MAP_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void load_map(int player_id,int map[50][50]) {
	int i=0,j=0;
	FILE *fp;
	char *filename = "map.txt";
	char buf[200], *p ,*end;
	printf("player_id:%d\n", player_id);
	fopen_s(&fp, filename, "r");
	if(fp==NULL){
		printf("error/n");
		fclose(fp);
		return;
	}

	for(i=0;i<50;i++){
		fgets(buf,sizeof(buf),fp);
		char *ctx;
		p=strtok_s(buf,",",&ctx);
		//printf("%s",buf);
		//printf("%s",p);
		while(p=strtok_s(NULL,",",&ctx)){
			map[i][j]=atoi(p);
			j++;
		}
		j=0;
	}
	fclose(fp);
}

#endif

 