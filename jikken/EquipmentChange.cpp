#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "savedata.h"
//更新
void EquipmentChange_Update() {
	player_data change;
	change = player;
	if (CheckHitKey(KEY_INPUT_M) != 0) { //Mを選択
		SceneMgr_ChangeScene(eScene_Menu);//メニューに戻る
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) { //Tを選択
		SceneMgr_ChangeScene(eScene_Title);//タイトルに戻る
	}
	if (CheckHitKey(KEY_INPUT_0) != 0) { //0を選択
		player.equipment = player.having_item[0];
		player_item.having_item[0] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//現在の装備と0の装備を入れ替える
	}
	if (CheckHitKey(KEY_INPUT_1) != 0) { //1を選択
		player.equipment = player.having_item[1];
		player.having_item[1] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//現在の装備と1の装備を入れ替える
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2を選択
		player.equipment = player.having_item[2];
		player.having_item[2] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//現在の装備と2の装備を入れ替える
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3を選択
		player.equipment = player.having_item[3];
		player.having_item[3] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//現在の装備と3の装備を入れ替える
	}
	if (CheckHitKey(KEY_INPUT_4) != 0) { //4を選択
		player.equipment = player.having_item[4];
		player.having_item[4] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//現在の装備と4の装備を入れ替える
	}
	if (CheckHitKey(KEY_INPUT_5) != 0) { //5を選択
		player.equipment = player.having_item[5];
		player.having_item[5] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//現在の装備と5の装備を入れ替える
	}
	if (CheckHitKey(KEY_INPUT_6) != 0) { //6を選択
		player.equipment = player.having_item[6];
		player.having_item[6] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//現在の装備と6の装備を入れ替える
	}
	if (CheckHitKey(KEY_INPUT_7) != 0) { //7を選択
		player.equipment = player.having_item[7];
		player.having_item[7] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//現在の装備と7の装備を入れ替える
	}
	if (CheckHitKey(KEY_INPUT_8) != 0) { //8を選択
		player.equipment = player.having_item[8];
		player.having_item[8] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//現在の装備と8の装備を入れ替える
	}
	if (CheckHitKey(KEY_INPUT_9) != 0) { //9を選択
		player.equipment = player.having_item[9];
		player.having_item[9] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//現在の装備と9の装備を入れ替える
	}
}

//描画
void EquipmentChange_Draw() {
	item change;
	int i;
	DrawString(0, 0, "装備変更画面(番号をプッシュして装備変更情報を保存)", GetColor(255, 255, 255));
	DrawString(0, 20, "M:メニュー画面に戻る", GetColor(255, 255, 255));
	DrawString(0, 40, "T:タイトルに移動", GetColor(255, 255, 255));
	DrawString(0, 60, "アイテム情報", GetColor(255, 255, 255));//データ1アイテム情報
	DrawFormatString(0, 100, GetColor(255, 255, 255), "装備中:%d atk:%d hp:%d", player.equipment.ID, player.equipment.atk, player.equipment.hp);
	for (i = 0; i < 10; i++) {//範囲はplayer_item.itemnum
		DrawFormatString(20, 140 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player.having_item[i].ID, player.having_item[i].atk, player.having_item[i].hp);
	}
}
