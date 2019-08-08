#include <DxLib.h>
#include "main.h"
#include "Init.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "UiManeger.h"

// ���ьn������
bool SysInit(void)
{
	bool rtnFlag = true;

	// ---------- ���я���
	SetWindowText("�e��");

	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		AST();
		return false;
	}
	
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜
	if (LoadDivGraph("image/blast2.png", BIG_BLAST_ANIM_MAX, 7, 2,
		64, 64, bigBlastImg) == -1)
	{
		AST();
		return false;
	}

	// ���ʉ�
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

	// ���ʉ�
	if ((bigBlastSound = LoadSoundMem("se/blast.mp3")) == -1)
	{
		AST();
		return false;
	}

	// �ϐ�������
	framCnt = 0;

	for (int i = 0; i < 256; i++)
	{
		keyFram[i] = 0;
	}
	highScore = HIGHSCORE_DEF;

	TitleInit();

	return rtnFlag;
}