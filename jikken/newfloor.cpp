#include "newfloor.h"
#include "Map.h"
#include "Player.h"
#include "EnemyMgr.h"

void floor_renew(int map_id) {
	load_map(map_id);
	EnemyMgr_Finalize();
	Player_Finalize();

	EnemyMgr_Initialize();
	Player_Initialize();
}