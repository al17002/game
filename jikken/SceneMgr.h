#pragma once

typedef enum {
	eScene_Menu,    //メニュー画面
	eScene_Game,    //ゲーム画面
	eScene_Title,  //設定画面
	eScene_SaveSelect, //セーブデータ決定画面
	eScene_Save, //セーブデータ保存
	eScene_EquipmentChange, //装備変更
	eScene_WareHouse,
} eScene;

//更新
void SceneMgr_Update();

//描画
void SceneMgr_Draw();

// 引数 nextScene にシーンを変更する
void SceneMgr_ChangeScene(eScene nextScene);
