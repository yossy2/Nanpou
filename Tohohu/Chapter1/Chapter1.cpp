#define CP1_DEF

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
int bgmVol;

// 1�͏�����
bool ChapterInit1(void)
{
	// =============�Ұ�ޗp
	if ((bg1Image = LoadGraph("image/bg.png")) == -1)
	{
		AST();
		//return false;
	}

	// ==============����ޗp
	if ((chapter1Bgm = LoadSoundMem("bgm/chapter1.mp3")) == -1)
	{
		AST();
		return false;
	}

	if ((bossBgm = LoadSoundMem("bgm/boss1.mp3")) == -1)
	{
		AST();
	}
	// �ϐ��̏�����
	bgPos[0].x = 0;
	bgPos[0].y = 0;
	bgPos[1].x = 0;
	bgPos[1].y = -GAME_SCREEN_SIZE_Y;

	EnemyInit1_A();
	EnemyInit1_B();
	EShotInit1_A();
	BossInit1();
	BShotInit();

	bgmVol = 240;
	chapterFunc = Chapter1;

	return true;
}

// 1�͏���
void Chapter1(void)
{
	for (int i = 0; i < 2; i++)
	{
		if (!boss1.drawFlag)
		{
			bgPos[i].y += 2;
		}
		else
		{
			bgPos[i].y++;
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

// 1�͕`��
void DrawChapter1(void)
{
	ClsDrawScreen();
	SetDrawScreen(gameScreen);
	for (int i = 0; i < 2; i++)
	{
		DrawGraph((int)bgPos[i].x,(int)bgPos[i].y, bg1Image, false);
	}
	// �ײтƔw�i�̐F���ꏏ������Â�����
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 70);
	DrawBox(0, 0, GAME_SCREEN_SIZE_X + 1, GAME_SCREEN_SIZE_Y +  1, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	PlayerDraw();
	if (!bossStartFlag1)
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
	
	// ���ѕ`��
	ItemDraw();

	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();
	GameDraw();

	ScreenFlip();
}

// ����ލĐ�
void Chapter1Sound(void)
{
	if (!boss1.drawFlag)
	{
		if (CheckSoundMem(chapter1Bgm) == 0)
		{
			PlaySoundMem(chapter1Bgm, DX_PLAYTYPE_LOOP, true);
		}
	}

	if (framCnt > BOSS1_CNT - 60 && !boss1.drawFlag)
	{
		bgmVol -= (240 / 60);
		if (bgmVol < 0)
		{
			StopSoundMem(chapter1Bgm);
		}
		ChangeVolumeSoundMem(bgmVol, chapter1Bgm);
	}
	else if (boss1.drawFlag && CheckSoundMem(bossBgm) == 0)
	{
		PlaySoundMem(bossBgm, DX_PLAYTYPE_LOOP, true);
	}
}

// ���y���~�߂�
void StopBgm(void)
{
	if (CheckSoundMem(chapter1Bgm) != 0)
	{
		StopSoundMem(chapter1Bgm);
	}

	if (CheckSoundMem(bossBgm) != 0)
	{
		StopSoundMem(bossBgm);
	}
}