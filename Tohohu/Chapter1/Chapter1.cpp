#include <DxLib.h>
#include <main.h>
#include <GameScene.h>
#include "Chapter1.h"
#include "Enemy1_a.h"
#include "EnemyShot1_a.h"
#include "Enemy1_b.h"
#include "Boss1.h"
#include "BossShot1.h"
#include <Player.h>
#include "Item.h"

int bg1Image;
Vector2 bgPos[2];

int chapter1Bgm;

// 1Í‰Šú‰»
bool ChapterInit1(void)
{
	// =============²Ò°¼Ş—p
	if ((bg1Image = LoadGraph("image/bg.png")) == -1)
	{
		AST();
		return false;
	}

	// ==============»³İÄŞ—p
	if ((chapter1Bgm = LoadSoundMem("bgm/chapter1.mp3")) == -1)
	{
		AST();
		return false;
	}
	// •Ï”‚Ì‰Šú‰»
	bgPos[0].x = 0;
	bgPos[0].y = 0;
	bgPos[1].x = 0;
	bgPos[1].y = -GAME_SCREEN_SIZE_Y;

	EnemyInit1_A();
	EnemyInit1_B();
	EShotInit1_A();
	BossInit1();
	BShotInit();
	chapterFunc = Chapter1;

	return true;
}

// 1Íˆ—
void Chapter1(void)
{
	for (int i = 0; i < 2; i++)
	{
		if (!boss1.drawFlag)
		{
			bgPos[i].y += 2;
		}
		if (bgPos[i].y >= GAME_SCREEN_SIZE_Y)
		{
			bgPos[i].y = -GAME_SCREEN_SIZE_Y + 2;
		}
	}
	if (!boss1.drawFlag)
	{
		EnemyCtl1_A();
		EShotCtl1_A();
	}
	EnemyCtl1_B();
	BossCtl1();
	BShotCtl1();
	Chapter1Sound();
	DrawChapter1();
}

// 1Í•`‰æ
void DrawChapter1(void)
{
	ClsDrawScreen();
	for (int i = 0; i < 2; i++)
	{
		DrawGraph(GAME_SCREEN_X + bgPos[i].x, GAME_SCREEN_Y + bgPos[i].y, bg1Image, false);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 70);
	DrawBox(GAME_SCREEN_X, GAME_SCREEN_Y, GAME_SCREEN_SIZE_X + 1 + GAME_SCREEN_X, GAME_SCREEN_SIZE_Y +  1 + GAME_SCREEN_Y, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	PlayerDraw();
	if (!boss1.drawFlag)
	{
		DrawEnemy1_A();
		DrawEShot1_A();
	}
	else
	{
		BossDraw1();
		BShotDraw1();
	}
	DrawEnemy1_B();
	
	// ±²ÃÑ•`‰æ
	ItemDraw();

	GameDraw();

	ScreenFlip();
}

// »³İÄŞÄ¶
void Chapter1Sound(void)
{
	if (!boss1.drawFlag)
	{
		if (CheckSoundMem(chapter1Bgm) == 0)
		{
			PlaySoundMem(chapter1Bgm, DX_PLAYTYPE_BACK, true);
		}
	}
}