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

// 1Í‰Šú‰»
bool ChapterInit1(void)
{
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
	if (!boss1.drawFlag)
	{
		EnemyCtl1_A();
		EShotCtl1_A();
	}
	EnemyCtl1_B();
	BossCtl1();
	BShotCtl1();
	DrawChapter1();
}

// 1Í•`‰æ
void DrawChapter1(void)
{
	ClsDrawScreen();
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