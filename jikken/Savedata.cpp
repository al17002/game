#include "DxLib.h"
#include "Savedata.h"


player_alldata player_all_of_data;//���̃t�@�C���Ŏg����O���[�o���ϐ�


void input_savedata(int num) {

	int i,n_int;
	char n_char[2];
	FILE *fp;
	
	if (num == 1) {
		fp=fopen("savedata1.txt", "r");
	}else if (num == 2) {
		fp = fopen("savedata2.txt", "r");
	}else {
		fp = fopen("new_savedata.txt", "r");//�V�����Z�[�u���쐬�̍ۂ̂����Ă��v�����ĂȂ�
	}

	while (fgets(n_char,2,fp) != NULL) {
		n_int = atoi(n_char);
		if (i < 10)player_all_of_data.having_item.item[i] = n_int;
		else if(i < 20)player_all_of_data.stored_item.item[i-10] = n_int;
		else player_all_of_data.equipment= n_int;
	}

}