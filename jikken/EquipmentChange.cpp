#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "savedata.h"
#include "Keyboard.h"
#include "Title.h"
//更新
void EquipmentChange_Update() {
	player_data change;
	change = player;
	Keyboard_Update();
	if (Keyboard_Get(KEY_INPUT_M) == 1) { //Mを選択
		SceneMgr_ChangeScene(eScene_Menu);//メニューに戻る
	}
	else if (Keyboard_Get(KEY_INPUT_0) == 1) { //0を選択
		if (player.having_item[0].ID != 0) {
			player.equipment = player.having_item[0];
			player.having_item[0] = change.equipment;
		}
		//現在の装備と0の装備を入れ替える
	}
	else if (Keyboard_Get(KEY_INPUT_1) == 1) { //1を選択
		if (player.having_item[1].ID != 0) {
			player.equipment = player.having_item[1];
			player.having_item[1] = change.equipment;
			//現在の装備と1の装備を入れ替える
		}
	}
	else if (Keyboard_Get(KEY_INPUT_2) == 1) { //2を選択
		if (player.having_item[2].ID != 0) {
			player.equipment = player.having_item[2];
			player.having_item[2] = change.equipment;
		}
		//現在の装備と2の装備を入れ替える
	}
	else if (Keyboard_Get(KEY_INPUT_3) == 1) { //3を選択
		if (player.having_item[3].ID != 0) {
			player.equipment = player.having_item[3];
			player.having_item[3] = change.equipment;
		}
		//現在の装備と3の装備を入れ替える
	}
	else if (Keyboard_Get(KEY_INPUT_4) == 1) { //4を選択
		if (player.having_item[4].ID != 0) {
			player.equipment = player.having_item[4];
			player.having_item[4] = change.equipment;
		}
		//現在の装備と4の装備を入れ替える
	}
	else if (Keyboard_Get(KEY_INPUT_5) == 1) { //5を選択
		if (player.having_item[5].ID != 0) {
			player.equipment = player.having_item[5];
			player.having_item[5] = change.equipment;
		}
		//現在の装備と5の装備を入れ替える
	}
	else if (Keyboard_Get(KEY_INPUT_6) == 1) { //6を選択
		if (player.having_item[6].ID != 0) {
			player.equipment = player.having_item[6];
			player.having_item[6] = change.equipment;
		}
		//現在の装備と6の装備を入れ替える
	}
	else if (Keyboard_Get(KEY_INPUT_7) == 1) { //7を選択
		if (player.having_item[7].ID != 0) {
			player.equipment = player.having_item[7];
			player.having_item[7] = change.equipment;
		}
		//現在の装備と7の装備を入れ替える
	}
	else if (Keyboard_Get(KEY_INPUT_8) == 1) { //8を選択
		if (player.having_item[8].ID != 0) {
			player.equipment = player.having_item[8];
			player.having_item[8] = change.equipment;
		}
		//現在の装備と8の装備を入れ替える
	}
	else if (Keyboard_Get(KEY_INPUT_9) == 1) { //9を選択
		if (player.having_item[9].ID != 0) {
			player.equipment = player.having_item[9];
			player.having_item[9] = change.equipment;
		}
		//現在の装備と9の装備を入れ替える
	}
}

//描画
void EquipmentChange_Draw() {
	item change;
	int i;
	DrawStringToHandle(350, 50, "装備変更画面(番号をプッシュして装備変更情報を保存)", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 150, "M:メニュー画面に戻る", GetColor(255, 255, 255),Font01);
	DrawStringToHandle(550, 350, "アイテム情報", GetColor(255, 255, 255),Font01);//データ1アイテム情報
	DrawFormatStringToHandle(550, 420, GetColor(255, 255, 255),Font01, "装備中:%s atk:%d hp:%d", itemRef[player.equipment.ID].name, player.equipment.atk, player.equipment.hp);
	DrawStringToHandle(550, 490, "所持アイテム", GetColor(255, 255, 255), Font01);
	for (i = 0; i < 10; i++) {//範囲はplayer_item.itemnum
		DrawFormatStringToHandle(550, 540 + 40 * i, GetColor(255, 255, 255),Font01, "%d:%s atk:%d hp:%d", i, itemRef[player.having_item[i].ID].name, player.having_item[i].atk, player.having_item[i].hp);
	}
}
