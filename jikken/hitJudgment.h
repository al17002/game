#pragma once

//当たり判定の確認　player = -1, noone = 0 enemy = num
void removeHitbox(int y, int x);
void clearHitbox();
int hitJudgement(int direction, int myNum);