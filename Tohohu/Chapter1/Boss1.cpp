#define BOSS1_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Boss1.h"
#include "BossShot1.h"
#include "Enemy1_b.h"
#include <Player.h>
#include <PlayerShot.h>

int bossImg1[BOSS1_ANIM_MAX];		// ‰æ‘œID
int bossLifeImg;					// ÎŞ½‚ÌHPÊŞ°
int atkAngle;						// UŒ‚1‚Ì’e‚Ì”­ËŠp“x
void (*boss1AtkFunc[BOSS1_ATK_PTN])(void) = {BossAtk1_1,BossAtk1_2,BossAtk1_3,BossAtk1_4};			// UŒ‚ŠÖ”Îß²İÀ	

// ‰Šú‰»
bool BossInit1(void)
{
	// ‰æ‘œ“Ç‚İ‚İ
	if (LoadDivGraph("image/boss1_anim.png", BOSS1_ANIM_MAX, BOSS1_ANIM_MAX, 1,
		BOSS1_SIZE_X, BOSS1_SIZE_Y, bossImg1) == -1)
	{
		AST();
		return false;
	}

	bossLifeImg = LoadGraph("image/enemyLife.png");
	if (bossLifeImg == -1)
	{
		AST();
	}

	boss1.pos = { 320.0f,300.0f };
	boss1.life = BOSS1_LIFE_MAX;
	boss1.drawFlag = false;
	boss1.moveCount = 0;
	boss1.moveAngle = 0;
	boss1.animCount = 0;

	atkAngle = 90;

	return true;
}

// ÎŞ½‚Ìˆ—
void BossCtl1(void)
{
	// oŒ»
	if (framCnt == BOSS1_CNT)
	{
		boss1.drawFlag = true;
	}

	if (boss1.drawFlag)
	{
		if (boss1.life % 250 == 0)
		{
			boss1.moveCount = 0;
		}
		(*boss1AtkFunc[(BOSS1_ATK_PTN - 1) - boss1.life / 250])();

		boss1.moveCount++;
		boss1.animCount++;

		// ’e‚Æ‚Ì“–‚½‚è”»’è
		for (int k = 0; k < PSHOT_NUM; k++)
		{
			if (pShot[k].flag)
			{
				if (CheckHitObj(pShot[k].pos, (float)PSHOT_HIT_RAD, boss1.pos, (float)BOSS1_SIZE_X / 2.0f))
				{
					pShot[k].flag = false;
					boss1.life --;
					if (boss1.life <= 0)
					{
						boss1.drawFlag = false;
					}
				}
			}
		}
	}
}

// •`‰æ
void BossDraw1(void)
{
	// ÎŞ½
	DrawRotaGraphF(boss1.pos.x + GAME_SCREEN_X,boss1.pos.y + GAME_SCREEN_Y,
		1.0,0.0,bossImg1[(boss1.animCount / 10) % BOSS1_ANIM_MAX],true,false);

	// HP
	DrawRectGraph(GAME_SCREEN_X, 20, 0, 0, (int)(boss1.life * GAME_SCREEN_SIZE_X / BOSS1_LIFE_MAX), 10, bossLifeImg, true, false);

}

// ˆÚ“®‚µ‚È‚ª‚ç’e‚ğ”­Ë
void BossAtk1_1(void)
{
	if ((boss1.moveCount / 60) % 3 != 1)
	{
		return;
	}
	else if (boss1.moveCount % 60 == 0)
	{
		boss1.moveAngle -= 60;
	}
	boss1.speed = 3.0f - (float)(boss1.moveCount % 60) / 20.0f;

	boss1.move.x = boss1.speed * cosf(DEG_TO_RAD(boss1.moveAngle));
	boss1.move.y = boss1.speed * sinf(DEG_TO_RAD(boss1.moveAngle));

	boss1.pos.x += boss1.move.x;
	boss1.pos.y += boss1.move.y;

	float angle = atan2f(player.pos.y - boss1.pos.y, player.pos.x - boss1.pos.x);

	//if(boss1.moveCount % 10 != 0)
	//{
	//	return;
	//}

	// ’e‚ğˆê”­
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

// ’e‚ğ‰~ó‚É”­Ë
void BossAtk1_2(void)
{
	if (fabsf((int)(boss1.pos.x - (float)GAME_SCREEN_SIZE_X / 2.0f)) > 0 ||
		fabsf((int)(boss1.pos.y - (float)GAME_SCREEN_SIZE_Y / 2.0f)) > 0)
	{
		MoveCenter();
		boss1.moveCount = 0;
		return;
	}

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

// ‰ñ“]
void BossAtk1_3(void)
{
	if (boss1.moveCount < 180 || boss1.moveCount % 2 != 0)
	{
		return;
	}

	int cnt = 0;
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (!bShot1[i].flag)
		{
			bShot1[i].count = 0;
			bShot1[i].moveAngle = atkAngle;
			bShot1[i].rotaAngle = 0;
			bShot1[i].pos = { boss1.pos.x , boss1.pos.y + BOSS1_SHOT_OFSET };
			bShot1[i].speed = 2.0f;
			bShot1[i].flag = true;
			atkAngle += 120;
			cnt++;
			if (cnt >= 3)
			{
				atkAngle += 13;
				return;
			}
		}
	}
}

// ½×²Ñ‘åsi
void BossAtk1_4(void)
{
	if (boss1.moveCount < 180 || boss1.moveCount % 10 != 0)
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
			enemy1B[i].animCount = 0;
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

// ’†‰›‚ÉˆÚ“®
void MoveCenter(void)
{
	Vector2 length = { (float)(GAME_SCREEN_SIZE_X / 2 - boss1.pos.x),(float)(GAME_SCREEN_SIZE_Y / 2 - boss1.pos.y) };
	boss1.moveAngle = RAD_TO_DEG(atan2f(length.y, length.x));

	boss1.speed = (length.x+ length.y) / 20.0f;

	boss1.pos.x += boss1.speed * cosf(DEG_TO_RAD(boss1.moveAngle));
	boss1.pos.y += boss1.speed * sinf(DEG_TO_RAD(boss1.moveAngle));

}



