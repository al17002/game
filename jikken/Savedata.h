#pragma once

typedef struct player_item {
	int item[0];
	int item[1];
	int item[2];
	int item[3];
	int item[4];
	int item[5];
	int item[6];
	int item[7];
	int item[8];
	int item[9];
	int item[10];
}; //[�A�C�e��id]�̐��B


typedef struct player_alldata {
	player_item having_item;  //�������Ă���A�C�e��
	player_item stored_item; //�q�ɂɂ���A�C�e��
	int equipment;  //�������Ă���A�C�e����ID
};

typedef struct player_data {
	player_item having_item;
	int equipment;
	int change_status; //�������Ă�A�C�e���ɂ��ω��l
	int y; //player�̂����W
	int x; //x���W

};

extern player_alldata player_all_of_data; //���ׂẴt�@�C���Ŏg����O���[�o���ϐ��錾�B���̖��O���v�����Ȃ������B
