#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "load_map.h"

int map[50][50] = {};

int main() {
	int player_id = 123;
	int i,j;
	load_map(player_id,map);
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
