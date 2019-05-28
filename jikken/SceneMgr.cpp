#include "DxLib.h"
#include "Game.h"
#include "Menu.h"
#include "SceneMgr.h"
#include "Title.h"
#include "Player.h"

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
	}
}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene NextScene) {
	Scene = NextScene;
}