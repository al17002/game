#include <stdio.h>
static int map[50][50] = {

}
void load_map(int player_id) {
	FILE *file;
	file = fopen("map.txt", "r");
	printf("player_id:%d\n", player_id);
	fclose(file);
}

int main() {
	int player_id = 123;
	load_map(player_id);
	return 0;
}
