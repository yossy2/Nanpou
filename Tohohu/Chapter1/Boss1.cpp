#define BOSS1_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Boss1.h"
#include "BossShot1.h"
#include <Player.h>

int bossImg1[BOSS1_ANIM_MAX];		// âÊëúID
int atkAngle1;		// çUåÇ1ÇÃíeÇÃî≠éÀäpìx

// èâä˙âª
bool BossInit1(void)
{
	if (LoadDivGraph("image/boss1_anim.png", BOSS1_ANIM_MAX, BOSS1_ANIM_MAX, 1,
		BOSS1_SIZE_X, BOSS1_SIZE_Y, bossImg1) == -1)
	{
		AST();
		return false;
	}

	boss1.pos = { 340.0f,300.0f };
	boss1.life = 100;
	boss1.drawFlag = false;
	boss1.moveCount = 0;
	boss1.animCount = 0;

	atkAngle1 = 90;

	return true;
}

// ŒﬁΩÇÃèàóù
void BossCtl1(void)
{
	// èoåª
	if (framCnt == BOSS1_CNT)
	{
		boss1.drawFlag = true;
	}

	if (boss1.drawFlag)
	{
		if (boss1.life >= 50 && boss1.moveCount % 2 == 0)
		{
			BossAtk1_1();
		}

		boss1.moveCount++;
		boss1.animCount++;
	}
}

// ï`âÊ
void BossDraw1(void)
{
	DrawRotaGraphF(boss1.pos.x,boss1.pos.y,1.0,0.0,bossImg1[(boss1.animCount / 10) % BOSS1_ANIM_MAX],true,false);
}

// çUåÇ ﬂ¿∞›ÇªÇÃ1ÅAâÒì]
void BossAtk1_1(void)
{
	int cnt = 0;
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (!bShot1[i].flag)
		{
			bShot1[i].count = 0;
			bShot1[i].moveAngle = atkAngle1;
			bShot1[i].rotaAngle = 0;
			bShot1[i].pos = boss1.pos;
			bShot1[i].speed = 4.0f;
			bShot1[i].flag = true;
			atkAngle1 += 120;
			cnt++;
			if (cnt >= 3)
			{
				atkAngle1 += 7;
				return;
			}
		}
	}
}