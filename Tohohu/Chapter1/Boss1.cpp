#define BOSS1_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Boss1.h"
#include "BossShot1.h"
#include "Enemy1_b.h"
#include <Player.h>

int bossImg1[BOSS1_ANIM_MAX];		// âÊëúID
int atkAngle;		// çUåÇ1ÇÃíeÇÃî≠éÀäpìx

// èâä˙âª
bool BossInit1(void)
{
	if (LoadDivGraph("image/boss1_anim.png", BOSS1_ANIM_MAX, BOSS1_ANIM_MAX, 1,
		BOSS1_SIZE_X, BOSS1_SIZE_Y, bossImg1) == -1)
	{
		AST();
		return false;
	}

	boss1.pos = { 320.0f,300.0f };
	boss1.life = 100;
	boss1.drawFlag = false;
	boss1.moveCount = 0;
	boss1.moveAngle = 0;
	boss1.animCount = 0;

	atkAngle = 90;

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
			BossAtk1_4();
		}

		boss1.moveCount++;
		boss1.animCount++;
	}
}

// ï`âÊ
void BossDraw1(void)
{
	DrawRotaGraphF(boss1.pos.x + GAME_SCREEN_X,boss1.pos.y + GAME_SCREEN_Y,1.0,0.0,bossImg1[(boss1.animCount / 10) % BOSS1_ANIM_MAX],true,false);
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
			bShot1[i].moveAngle = atkAngle;
			bShot1[i].rotaAngle = 0;
			bShot1[i].pos = { boss1.pos.x , boss1.pos.y + BOSS1_SHOT_OFSET };
			bShot1[i].speed = 4.0f;
			bShot1[i].flag = true;
			atkAngle += 120;
			cnt++;
			if (cnt >= 3)
			{
				atkAngle += 7;
				return;
			}
		}
	}
}

// íeÇâ~èÛÇ…î≠éÀ
void BossAtk1_2(void)
{
	if ((boss1.moveCount / 60) % 2 == 0)
	{
		atkAngle = rand() % 10;
		return;
	}
	else if (boss1.moveCount % 10 != 0)
	{
		return;
	}
	else
	{

	}

	int cnt = 0;
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (!bShot1[i].flag)
		{
			bShot1[i].count = 0;
			bShot1[i].moveAngle = atkAngle + cnt * 10;
			bShot1[i].rotaAngle = 0;
			bShot1[i].pos = { boss1.pos.x , boss1.pos.y + BOSS1_SHOT_OFSET };
			bShot1[i].speed = 2.0f;
			bShot1[i].flag = true;
			cnt++;
			if (cnt >= 36)
			{
				atkAngle += 5;
				return;
			}
		}
	}
}

// à⁄ìÆÇµÇ»Ç™ÇÁíeÇî≠éÀ
void BossAtk1_3(void)
{
	if ((boss1.moveCount / 60) % 3 != 1)
	{
		return;
	}
	else if (boss1.moveCount % 60 == 0)
	{
		boss1.moveAngle -= 70;
	}
	boss1.speed = 8.0f - (float)(boss1.moveCount % 60) / 10.0f;

	boss1.move.x = boss1.speed * cosf(DEG_TO_RAD(boss1.moveAngle));
	boss1.move.y = boss1.speed * sinf(DEG_TO_RAD(boss1.moveAngle));

	boss1.pos.x += boss1.move.x;
	boss1.pos.y += boss1.move.y;
	
	float angle = atan2f(player.pos.y - boss1.pos.y, player.pos.x - boss1.pos.x);

	//if(boss1.moveCount % 10 != 0)
	//{
	//	return;
	//}

	// íeÇàÍî≠
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (!bShot1[i].flag)
		{
			bShot1[i].count = 0;
			bShot1[i].moveAngle = RAD_TO_DEG(angle) + ((rand() % 11) - 5);
			bShot1[i].rotaAngle = 0;
			bShot1[i].pos = { boss1.pos.x , boss1.pos.y + BOSS1_SHOT_OFSET };
			bShot1[i].speed = 4.0f;
			bShot1[i].flag = true;
			return;
		}
	}
}

// Ω◊≤—ëÂçsêi
void BossAtk1_4(void)
{
	if (boss1.moveCount % 10 != 0)
	{
		return;
	}

	for (int i = 0; i < ENEMY1_B_MAX; i++)
	{
		if (!enemy1B[i].drawFlag)
		{
			enemy1B[i].pos = { (float)(rand() % GAME_SCREEN_SIZE_X), 0.0f };
			enemy1B[i].initData.movePtn = 2;
			enemy1B[i].moveCount = rand() % 180;
			enemy1B[i].drawFlag = true;
			break;
		}
	}

	if (boss1.moveCount % 120 != 0)
	{
		return;
	}

	int cnt = 0;
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (!bShot1[i].flag)
		{
			bShot1[i].count = 0;
			bShot1[i].moveAngle = atkAngle + cnt * 20;
			bShot1[i].rotaAngle = 0;
			bShot1[i].pos = { boss1.pos.x , boss1.pos.y + BOSS1_SHOT_OFSET };
			bShot1[i].speed = 2.0f;
			bShot1[i].flag = true;
			cnt++;
			if (cnt >= 18)
			{
				atkAngle += 10;
				return;
			}
		}
	}
}



