#pragma once

//�K�w�̍X�V
void floor_renew(int map_id);

//�A�C�e���C�x���g�̔���
void item_event(int n);

//�t���A�C�x���g�̔���
void floor_event(int n);

//�i�߂邩�𔻒肷��
int IsAbleToGo(int x, int y, int muki,bool player);

//�摜�̓ǂݍ���
void Floor_Initialize();

//�`��
void Map_Draw();

//�v���C���[�̎��͈ȊO����`��
void Map_Draw_Surround();

//�}�b�v�̓ǂݍ���
void load_map(int map_id);

//�G�̍��W���v�Z����
void calcenemy(int *x, int *y);