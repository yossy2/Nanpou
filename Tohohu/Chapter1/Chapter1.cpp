#include <DxLib.h>
#include <main.h>
#include <GameScene.h>
#include "Chapter1.h"
#include "Enemy1_a.h"
#include "EnemyShot1_a.h"
#include "Enemy1_b.h"
#include "Boss1.h"
#include <Player.h>

// 1�͏�����
bool ChapterInit1(void)
{
	EnemyInit1_A();
	EnemyInit1_B();
	EShotInit1_A();
	BossInit1();
	chapterFunc = Chapter1;

	return true;
}

// 1�͏���
void Chapter1(void)
{
	if (!boss1.drawFlag)
	{
		EnemyCtl1_A();
		EnemyCtl1_B();
		EShotCtl1_A();
	}
	BossCtl1();
	DrawChapter1();
}

// 1�͕`��
void DrawChapter1(void)
{
	ClsDrawScreen();
	PlayerDraw();
	if (!boss1.drawFlag)
	{
		DrawEnemy1_A();
		DrawEnemy1_B();
		DrawEShot1_A();
	}
	else
	{
		BossDraw1();
	}
	
	GameDraw();

	ScreenFlip();
}