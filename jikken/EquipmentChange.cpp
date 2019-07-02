#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "savedata.h"
#include "Keyboard.h"
//�X�V
void EquipmentChange_Update() {
	player_data change;
	change = player;
	Keyboard_Update();
	if (Keyboard_Get(KEY_INPUT_M) == 1) { //M��I��
		SceneMgr_ChangeScene(eScene_Menu);//���j���[�ɖ߂�
	}
	else if (Keyboard_Get(KEY_INPUT_T) == 1) { //T��I��
		SceneMgr_ChangeScene(eScene_Title);//�^�C�g���ɖ߂�
	}
	else if (Keyboard_Get(KEY_INPUT_0) == 1) { //0��I��
		if (player.having_item[0].ID != 0) {
			player.equipment = player.having_item[0];
			player.having_item[0] = change.equipment;
		}
		//���݂̑�����0�̑��������ւ���
	}
	else if (Keyboard_Get(KEY_INPUT_1) == 1) { //1��I��
		if (player.having_item[1].ID != 0) {
			player.equipment = player.having_item[1];
			player.having_item[1] = change.equipment;
			//���݂̑�����1�̑��������ւ���
		}
	}
	else if (Keyboard_Get(KEY_INPUT_2) == 1) { //2��I��
		if (player.having_item[2].ID != 0) {
			player.equipment = player.having_item[2];
			player.having_item[2] = change.equipment;
		}
		//���݂̑�����2�̑��������ւ���
	}
	else if (Keyboard_Get(KEY_INPUT_3) == 1) { //3��I��
		if (player.having_item[3].ID != 0) {
			player.equipment = player.having_item[3];
			player.having_item[3] = change.equipment;
		}
		//���݂̑�����3�̑��������ւ���
	}
	else if (Keyboard_Get(KEY_INPUT_4) == 1) { //4��I��
		if (player.having_item[4].ID != 0) {
			player.equipment = player.having_item[4];
			player.having_item[4] = change.equipment;
		}
		//���݂̑�����4�̑��������ւ���
	}
	else if (Keyboard_Get(KEY_INPUT_5) == 1) { //5��I��
		if (player.having_item[5].ID != 0) {
			player.equipment = player.having_item[5];
			player.having_item[5] = change.equipment;
		}
		//���݂̑�����5�̑��������ւ���
	}
	else if (Keyboard_Get(KEY_INPUT_6) == 1) { //6��I��
		if (player.having_item[6].ID != 0) {
			player.equipment = player.having_item[6];
			player.having_item[6] = change.equipment;
		}
		//���݂̑�����6�̑��������ւ���
	}
	else if (Keyboard_Get(KEY_INPUT_7) == 1) { //7��I��
		if (player.having_item[7].ID != 0) {
			player.equipment = player.having_item[7];
			player.having_item[7] = change.equipment;
		}
		//���݂̑�����7�̑��������ւ���
	}
	else if (Keyboard_Get(KEY_INPUT_8) == 1) { //8��I��
		if (player.having_item[8].ID != 0) {
			player.equipment = player.having_item[8];
			player.having_item[8] = change.equipment;
		}
		//���݂̑�����8�̑��������ւ���
	}
	else if (Keyboard_Get(KEY_INPUT_9) == 1) { //9��I��
		if (player.having_item[9].ID != 0) {
			player.equipment = player.having_item[9];
			player.having_item[9] = change.equipment;
		}
		//���݂̑�����9�̑��������ւ���
	}
}

//�`��
void EquipmentChange_Draw() {
	item change;
	int i;
	DrawString(0, 0, "�����ύX���(�ԍ����v�b�V�����đ����ύX����ۑ�)", GetColor(255, 255, 255));
	DrawString(0, 20, "M:���j���[��ʂɖ߂�", GetColor(255, 255, 255));
	DrawString(0, 40, "T:�^�C�g���Ɉړ�", GetColor(255, 255, 255));
	DrawString(0, 60, "�A�C�e�����", GetColor(255, 255, 255));//�f�[�^1�A�C�e�����
	DrawFormatString(0, 100, GetColor(255, 255, 255), "������:%s atk:%d hp:%d", itemRef[player.equipment.ID].name, player.equipment.atk, player.equipment.hp);
	for (i = 0; i < 10; i++) {//�͈͂�player_item.itemnum
		DrawFormatString(20, 140 + 20 * i, GetColor(255, 255, 255), "%d:%s atk:%d hp:%d", i, itemRef[player.having_item[i].ID].name, player.having_item[i].atk, player.having_item[i].hp);
	}
}
