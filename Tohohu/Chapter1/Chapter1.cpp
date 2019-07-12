#include <DxLib.h>
#include <main.h>
#include <GameScene.h>
#include "Chapter1.h"
#include "Enemy1_a.h"
#include "EnemyShot1_a.h"
#include <Player.h>

// 1�͏�����
bool ChapterInit1(void)
{
	EnemyInit1_A();
	EShotInit1_A();
	chapterFunc = Chapter1;

	return true;
}

// 1�͏���
void Chapter1(void)
{
	EnemyCtl1_A();
	EShotCtl1_A();
	DrawChapter1();
}

// 1�͕`��
void DrawChapter1(void)
{
	ClsDrawScreen();
	PlayerDraw();
	DrawEnemy1_A();
	DrawEShot1_A();
	GameDraw();

	ScreenFlip();
}