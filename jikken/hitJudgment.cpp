#include "hitJudgment.h"
#include "DxLib.h"     //hituyou??
#include "Enemy.h"     //For enemy position
#include "Savedata.h"  //For player position



bool hitJudgment(int direction,int enemyNUM,Enemy_t *m_Enemy) {
	if (direction == 0){
		//up
		if ((player.x == m_Enemy[enemyNUM].x) && (player.y - 32 == m_Enemy[enemyNUM].y)) return FALSE;
	}else if (direction == 1) {
		//left
		if ((player.x - 32 == m_Enemy[enemyNUM].x) && (player.y == m_Enemy[enemyNUM].y)) return FALSE;
	}else if (direction == 2) {
		//under
		if ((player.x == m_Enemy[enemyNUM].x) && (player.y + 32 == m_Enemy[enemyNUM].y)) return FALSE;
	}else if (direction == 3) {
		//right
		if ((player.x + 32 == m_Enemy[enemyNUM].x) && (player.y == m_Enemy[enemyNUM].y)) return FALSE;
	}
	return TRUE;
}