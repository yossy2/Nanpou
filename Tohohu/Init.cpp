#include <DxLib.h>
#include "main.h"
#include "Init.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "UiManeger.h"

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

	// 画像
	if (LoadDivGraph("image/blast2.png", BIG_BLAST_ANIM_MAX, 7, 2,
		64, 64, bigBlastImg) == -1)
	{
		AST();
		return false;
	}

	// 効果音
	if ((eShotSound = LoadSoundMem("se/eShot.mp3")) == -1)
	{
		AST();
		return false;
	}

	if ((blastSound = LoadSoundMem("se/bomb.mp3")) == -1)
	{
		AST();
		return false;
	}

	// 効果音
	if ((bigBlastSound = LoadSoundMem("se/blast.mp3")) == -1)
	{
		AST();
		return false;
	}

	// 変数初期化
	framCnt = 0;

	for (int i = 0; i < 256; i++)
	{
		keyFram[i] = 0;
	}
	highScore = HIGHSCORE_DEF;

	TitleInit();

	return rtnFlag;
}