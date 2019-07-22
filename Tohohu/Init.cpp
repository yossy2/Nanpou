#include <DxLib.h>
#include "main.h"
#include "Init.h"
#include "TitleScene.h"
#include "GameScene.h"

// ｼｽﾃﾑ系初期化
bool SysInit(void)
{
	bool rtnFlag = true;

	// ---------- ｼｽﾃﾑ処理
	SetWindowText("弾幕");

	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		AST();
		return false;
	}
	
	SetDrawScreen(DX_SCREEN_BACK);

	// 変数初期化
	sceneFunc = GameScene;
	framCnt = 0;

	for (int i = 0; i < 256; i++)
	{
		keyFram[i] = 0;
	}

	TitleInit();
	GameInit();

	return rtnFlag;
}