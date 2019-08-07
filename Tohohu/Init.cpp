#include <DxLib.h>
#include "main.h"
#include "Init.h"
#include "TitleScene.h"
#include "GameScene.h"

// ¼½ÃÑŒn‰Šú‰»
bool SysInit(void)
{
	bool rtnFlag = true;

	// ---------- ¼½ÃÑˆ—
	SetWindowText("’e–‹");

	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		AST();
		return false;
	}
	
	SetDrawScreen(DX_SCREEN_BACK);

	// Œø‰Ê‰¹
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

	// •Ï”‰Šú‰»
	framCnt = 0;

	for (int i = 0; i < 256; i++)
	{
		keyFram[i] = 0;
	}

	TitleInit();

	return rtnFlag;
}