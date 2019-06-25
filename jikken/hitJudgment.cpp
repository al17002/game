#include "hitJudgment.h"
#include "DxLib.h"     //hituyou??
#include "Enemy.h"     //For enemy position
#include "Savedata.h"  //For player position
#include "EnemyMgr.h"



int hitJudgment(int direction, int myNum) {//return = mynum (player = -1 noone = -2 enemy = num
	if (myNum == -1) {//check for player
		for (int i = 0; i < 2; i++) {
			if (direction == 0) {
				if ((player.x == m_Enemy[i].x) && (player.y - 32 == m_Enemy[i].y)) return i;
			}
			else if (direction == 1) {
				//left
				if ((player.x - 32 == m_Enemy[i].x) && (player.y == m_Enemy[i].y)) return i;
			}
			else if (direction == 2) {
				//under
				if ((player.x == m_Enemy[i].x) && (player.y + 32 == m_Enemy[i].y)) return i;
			}
			else if (direction == 3) {
				//right
				if ((player.x + 32 == m_Enemy[i].x) && (player.y == m_Enemy[i].y)) return i;
			}
		}
		return -2;
	}
	else {//check for enemy
		for (int i = 0; i < 2; i++) {//check enemy
			if (direction == 0) {
				if ((m_Enemy[myNum].x == m_Enemy[i].x) && (m_Enemy[myNum].y - 32 == m_Enemy[i].y)) return i;
				else if (m_Enemy[myNum].x == player.x && m_Enemy[myNum].y - 32 == player.y) return -1;
			}
			else if (direction == 1) {
				//left
				if ((m_Enemy[myNum].x - 32 == m_Enemy[i].x) && (m_Enemy[myNum].y == m_Enemy[i].y)) return i;
				else if (m_Enemy[myNum].x - 32 == (player.x) && m_Enemy[myNum].y  == (player.y)) return -1;
			}
			else if (direction == 2) {
				//under
				if ((m_Enemy[myNum].x == m_Enemy[i].x) && (m_Enemy[myNum].y + 32 == m_Enemy[i].y)) return i;
				else if (m_Enemy[myNum].x == player.x && m_Enemy[myNum].y + 32 == player.y) return -1;
			}
			else if (direction == 3) {
				//right
				if ((m_Enemy[myNum].x + 32 == m_Enemy[i].x) && (m_Enemy[myNum].y == m_Enemy[i].y)) return i;
				else if (m_Enemy[myNum].x +32 == player.x && m_Enemy[myNum].y == player.y) return -1;
			}
		}
		return -2;
	}
}