#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "savedata.h"
//�X�V
void EquipmentChange_Update() {
	player_data change;
	change = player;
	if (CheckHitKey(KEY_INPUT_M) != 0) { //M��I��
		SceneMgr_ChangeScene(eScene_Menu);//���j���[�ɖ߂�
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) { //T��I��
		SceneMgr_ChangeScene(eScene_Title);//�^�C�g���ɖ߂�
	}
	if (CheckHitKey(KEY_INPUT_0) != 0) { //0��I��
		player.equipment = player.having_item[0];
		player_item.having_item[0] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//���݂̑�����0�̑��������ւ���
	}
	if (CheckHitKey(KEY_INPUT_1) != 0) { //1��I��
		player.equipment = player.having_item[1];
		player.having_item[1] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//���݂̑�����1�̑��������ւ���
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) { //2��I��
		player.equipment = player.having_item[2];
		player.having_item[2] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//���݂̑�����2�̑��������ւ���
	}
	if (CheckHitKey(KEY_INPUT_3) != 0) { //3��I��
		player.equipment = player.having_item[3];
		player.having_item[3] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//���݂̑�����3�̑��������ւ���
	}
	if (CheckHitKey(KEY_INPUT_4) != 0) { //4��I��
		player.equipment = player.having_item[4];
		player.having_item[4] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//���݂̑�����4�̑��������ւ���
	}
	if (CheckHitKey(KEY_INPUT_5) != 0) { //5��I��
		player.equipment = player.having_item[5];
		player.having_item[5] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//���݂̑�����5�̑��������ւ���
	}
	if (CheckHitKey(KEY_INPUT_6) != 0) { //6��I��
		player.equipment = player.having_item[6];
		player.having_item[6] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//���݂̑�����6�̑��������ւ���
	}
	if (CheckHitKey(KEY_INPUT_7) != 0) { //7��I��
		player.equipment = player.having_item[7];
		player.having_item[7] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//���݂̑�����7�̑��������ւ���
	}
	if (CheckHitKey(KEY_INPUT_8) != 0) { //8��I��
		player.equipment = player.having_item[8];
		player.having_item[8] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//���݂̑�����8�̑��������ւ���
	}
	if (CheckHitKey(KEY_INPUT_9) != 0) { //9��I��
		player.equipment = player.having_item[9];
		player.having_item[9] = change.equipment;
		SceneMgr_ChangeScene(eScene_EquipmentChange);//���݂̑�����9�̑��������ւ���
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
	DrawFormatString(0, 100, GetColor(255, 255, 255), "������:%d atk:%d hp:%d", player.equipment.ID, player.equipment.atk, player.equipment.hp);
	for (i = 0; i < 10; i++) {//�͈͂�player_item.itemnum
		DrawFormatString(20, 140 + 20 * i, GetColor(255, 255, 255), "%d:%d atk:%d hp:%d", i, player.having_item[i].ID, player.having_item[i].atk, player.having_item[i].hp);
	}
}
