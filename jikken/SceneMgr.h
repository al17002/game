#pragma once

typedef enum {
	eScene_Menu,    //���j���[���
	eScene_Game,    //�Q�[�����
	eScene_Title,  //�ݒ���
	eScene_SaveSelect, //�Z�[�u�f�[�^������
	eScene_Save, //�Z�[�u�f�[�^�ۑ�
	eScene_EquipmentChange, //�����ύX
	eScene_WareHouse,
} eScene;

//�X�V
void SceneMgr_Update();

//�`��
void SceneMgr_Draw();

// ���� nextScene �ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene nextScene);
