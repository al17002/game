//load_map.h
#ifndef LOAD_MAP_H
#define LOAD_MAP_H
void load_map(int player_id,int map[50][50]) {
	int i=0,j=0;
	FILE *fp;
	char *filename = "map.txt";
	char buf[200], *p ,*end;
	printf("player_id:%d\n", player_id);
	if ((fp=fopen(filename,"r"))==NULL) {
		printf("error:E-C6-1\nマップ情報の読込に失敗しました。");
		fclose(fp);
		return;
	}

	for(i=0;i<50;i++){
		fgets(buf,sizeof(buf),fp);
		p=strtok(buf,",");
		//printf("%s",buf);
		//printf("%s",p);
		while(p=strtok(NULL,",")){
			map[i][j]=atoi(p);
			j++;
		}
		j=0;
	}
	fclose(fp);
}

#endif
