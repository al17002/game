#include "DxLib.h"
#include "Game.h"
#include "Menu.h"
#include "SceneMgr.h"
#include "Title.h"
#include "Player.h"
#include "SaveSelect.h"
#include "Save.h"
#include "EquipmentChange.h"
#include "WareHouse.h"

static eScene Scene = eScene_Title;    //�V�[���Ǘ��ϐ�

//�X�V
void SceneMgr_Update() {
	switch (Scene) {       //�V�[���ɂ���ď����𕪊�
	case eScene_Menu:    //���݂̉�ʂ����j���[�Ȃ�
		Menu_Update();   //���j���[��ʂ̍X�V����������
		break;//�ȉ���
	case eScene_Game:
		Game_Update();
		break;
	case eScene_Title:
		Title_Update();
		break;
	case eScene_SaveSelect:
		SaveSelect_Update();
		break;
	case eScene_Save:
		Save_Update();
		break;
	case eScene_EquipmentChange:
		EquipmentChange_Update();
		break;
	case eScene_WareHouse:
		WareHouse_Update();
		break;
	case eScene_Death:
		Death_Update();
		break;
	}
}

//�`��
void SceneMgr_Draw() {
	switch (Scene) {      //�V�[���ɂ���ď����𕪊�
	case eScene_Menu:   //���݂̉�ʂ����j���[��ʂȂ�
		Menu_Draw();    //���j���[��ʂ̕`�揈��������
		break;//�ȉ���
	case eScene_Game:
		Game_Draw();
		break;
	case eScene_Title:
		Title_Draw();
		break;
	case eScene_SaveSelect:
		SaveSelect_Draw();
		break;
	case eScene_Save:
		Save_Draw();
		break;
	case eScene_EquipmentChange:
		EquipmentChange_Draw();
		break;
	case eScene_WareHouse:
		WareHouse_Draw();
		break;
	case eScene_Death:
		Death_Draw();
		break;
	}

}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene NextScene) {
	Scene = NextScene;
}