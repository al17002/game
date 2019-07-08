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

static eScene Scene = eScene_Title;    //シーン管理変数

//更新
void SceneMgr_Update() {
	switch (Scene) {       //シーンによって処理を分岐
	case eScene_Menu:    //現在の画面がメニューなら
		Menu_Update();   //メニュー画面の更新処理をする
		break;//以下略
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

//描画
void SceneMgr_Draw() {
	switch (Scene) {      //シーンによって処理を分岐
	case eScene_Menu:   //現在の画面がメニュー画面なら
		Menu_Draw();    //メニュー画面の描画処理をする
		break;//以下略
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

// 引数 nextScene にシーンを変更する
void SceneMgr_ChangeScene(eScene NextScene) {
	Scene = NextScene;
}