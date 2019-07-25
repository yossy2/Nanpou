#define ESHOT1_A_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Enemy1_a.h"
#include "EnemyShot1_a.h"
#include "Player.h"

int eShotImg1A;

// ‰Šú‰»
bool EShotInit1_A(void)
{
	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		eShot1A[i].drwaFlag = false;
		eShot1A[i].count = 0;
		eShot1A[i].rotaAngle = 0;
	}

	// ‰æ‘œ“Ç‚İ‚İ
	eShotImg1A = LoadGraph("image/enemyShot1_A.png");
	if (eShotImg1A == -1)
	{
		AST();
		return false;
	}

	return true;
}

// XVˆ—
void EShotCtl1_A(void)
{
	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		if (eShot1A[i].drwaFlag)
		{
			float speed = ESHOT1_A_DEF_SPEED;
			if (eShot1A[i].count < ESHOT1_A_CNT_MAX)
			{
				speed += ESHOT1_A_MAX_SPEED * cosf(eShot1A[i].count * PI / (float)(ESHOT1_A_CNT_MAX * 2));
				eShot1A[i].count++;
			}

			eShot1A[i].move.x = speed * cosf(eShot1A[i].moveAngle * PI / 180.0f);
			eShot1A[i].move.y = speed * sinf(eShot1A[i].moveAngle * PI / 180.0f);

			eShot1A[i].pos.x += eShot1A[i].move.x;
			eShot1A[i].pos.y += eShot1A[i].move.y;

			// ‰æ–ÊŠO”»’è
			if (isMoveOut(eShot1A[i].pos))
			{
				eShot1A[i].drwaFlag = false;
			}
		}
	}
	// “–‚½‚è”»’è
	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		if (eShot1A[i].drwaFlag && player.flag)
		{
			if (CheckHitObj(eShot1A[i].pos, ESHOT1_A_SIZE_X / 2, player.pos, PLAYER_HIT_RAD))
			{
				PlayerDamage();
				eShot1A[i].drwaFlag = false;
			}
		}
	}
}

// •`‰æ
void DrawEShot1_A(void)
{
	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		if (eShot1A[i].drwaFlag)
		{
			DrawRotaGraphF(eShot1A[i].pos.x + GAME_SCREEN_X, eShot1A[i].pos.y + GAME_SCREEN_Y,
				1.0, (double)((float)eShot1A[i].rotaAngle * PI / 180.0f), eShotImg1A, true, false);
			eShot1A[i].rotaAngle++;
		}
	}
}