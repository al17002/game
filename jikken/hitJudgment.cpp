#include "hitJudgment.h"
#include "DxLib.h"     //hituyou??
#include "Enemy.h"     //For enemy position
#include "Savedata.h"  //For player position
#include "EnemyMgr.h"

static int hitmap[32][40] = {0};

//return mynum(player = -1, noone = 0 enemy = num

void removeHitbox(int y, int x) {
	y = y / 32;
	x = x / 32;
	hitmap[y][x] = 0;
}

void clearHitbox() {
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 40; j++) {
			hitmap[i][j] = 0;
		}
	}
}
int hitJudgement(int direction, int myNum) {
	if (myNum == -1) {//playerが移動している
		int x = player.x / 32, y = player.y / 32;
		if (direction == 0) {
			if (hitmap[y - 1][x] == 0) {//空いている
				hitmap[y][x] = 0;
				hitmap[y - 1][x] = -1;
				return 0;
			}
			else {//誰かがいる
				hitmap[y][x] = -1;
				return hitmap[y - 1][x];
			}
		}
		if (direction == 1) {
			if (hitmap[y][x - 1] == 0) {//空いている
				hitmap[y][x] = 0;
				hitmap[y][x - 1] = -1;
				return 0;
			}
			else {//誰かがいる
				hitmap[y][x] = -1;
				return hitmap[y][x - 1];
			}
		}
		if (direction == 2) {
			if (hitmap[y + 1][x] == 0) {//空いている
				hitmap[y][x] = 0;
				hitmap[y + 1][x] = -1;
				return 0;
			}
			else {//誰かがいる
				hitmap[y][x] = -1;
				return hitmap[y + 1][x];
			}
		}
		if (direction == 3) {
			if (hitmap[y][x + 1] == 0) {//空いている
				hitmap[y][x] = 0;
				hitmap[y][x + 1] = -1;
				return 0;
			}
			else {//誰かがいる
				hitmap[y][x] = -1;
				return hitmap[y][x + 1];
			}
		}

	}
	else {
		int x = m_Enemy[myNum].x / 32, y = m_Enemy[myNum].y / 32;
		myNum += 1;//Mapのデータに合わせて1を足す
		if (direction == 0) {
			if (hitmap[y - 1][x] == 0) {//空いている
				hitmap[y][x] = 0;
				hitmap[y - 1][x] = myNum;
				return 0;
			}
			else {//誰かがいる
				hitmap[y][x] = myNum;
				return hitmap[y - 1][x];
			}
		}
		if (direction == 1) {
			if (hitmap[y][x - 1] == 0) {//空いている
				hitmap[y][x] = 0;
				hitmap[y][x - 1] = myNum;
				return 0;
			}
			else {//誰かがいる
				hitmap[y][x] = myNum;
				return hitmap[y][x - 1];
			}
		}
		if (direction == 2) {
			if (hitmap[y + 1][x] == 0) {//空いている
				hitmap[y][x] = 0;
				hitmap[y + 1][x] = myNum;
				return 0;
			}
			else {//誰かがいる
				hitmap[y][x] = myNum;
				return hitmap[y + 1][x];
			}
		}
		if (direction == 3) {
			if (hitmap[y][x + 1] == 0) {//空いている
				hitmap[y][x] = 0;
				hitmap[y][x + 1] = myNum;
				return 0;
			}
			else {//誰かがいる
				hitmap[y][x] = myNum;
				return hitmap[y][x + 1];
			}
		}
	}
	return -2;
}