#define ENEMY1_A_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Enemy1_a.h"
#include "EnemyShot1_a.h"
#include <Player.h>

int enemyImg1A;			// “GA‚Ì‰æ‘œID

// ‰Šú‰»
bool EnemyInit1_A(void)
{
	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		enemy1A[i].drawFlag = false;
	}

	// ‰æ‘œ“Ç‚İ‚İ
	enemyImg1A = LoadGraph("image/enemy1_A.png");
	if (enemyImg1A == -1)
	{
		AST();
		return false;
	}

	return true;
}

// XVˆ—
void EnemyCtl1_A(void)
{
	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		if (enemy1A[i].drawFlag && !enemy1A[i].atkFlag)
		{
			enemy1A[i].pos.y += ENEMY1_A_SPEED;
			

			if (enemy1A[i].pos.y >= 200)
			{
				enemy1A[i].atkFlag = true;
				EnemyAttack1_A(enemy1A[i].pos);
				enemy1A[i].move.x = ENEMY1_A_SPEED * (1 - 2 * (rand() % 2));
			}
		}
		else if (enemy1A[i].atkFlag && ++enemy1A[i].moveCount > 60)
		{
			enemy1A[i].pos.x += enemy1A[i].move.x;
		}

		// ‰æ–ÊŠO”»’è
		if (enemy1A[i].pos.x < -(float)ENEMY1_A_SIZE_X ||
			enemy1A[i].pos.x >(float)(GAME_SCREEN_SIZE_X + ENEMY1_A_SIZE_X) ||
			enemy1A[i].pos.y < -(float)ENEMY1_A_SIZE_X ||
			enemy1A[i].pos.y >(float)(GAME_SCREEN_SIZE_Y + ENEMY1_A_SIZE_X))
		{
			enemy1A[i].drawFlag = false;
		}

	}

	if (flamCnt % ENEMY1_A_INV == 0 && (flamCnt / ENEMY1_A_INV) < ENEMY1_A_NUM)
	{
		enemy1A[flamCnt / ENEMY1_A_INV].drawFlag = true;
		enemy1A[flamCnt / ENEMY1_A_INV].pos.x = (float)((rand() % (GAME_SCREEN_SIZE_X - ENEMY1_A_SIZE_X)) + ENEMY1_A_SIZE_X / 2);
		enemy1A[flamCnt / ENEMY1_A_INV].pos.y = -ENEMY1_A_SIZE_Y;
	}
	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		if (enemy1A[i].drawFlag && player.flag)
		{
			if (CheckHitObj(enemy1A[i].pos, ENEMY1_A_SIZE_X / 2, player.pos, PLAYER_HIT_RAD))
			{
				player.flag = false;
			}
		}
	}
}

// •`‰æ
void DrawEnemy1_A(void)
{
	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		if (enemy1A[i].drawFlag)
		{
			DrawRotaGraphF(enemy1A[i].pos.x + GAME_SCREEN_X, enemy1A[i].pos.y + GAME_SCREEN_Y,
				1.0, 0.0, enemyImg1A, true, false);
		}
	}
}

// UŒ‚
void EnemyAttack1_A(Vector2 pos)
{
	int count = 0;

	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		if (!eShot1A[i].flag)
		{
			eShot1A[i].flag = true;
			eShot1A[i].pos = pos;
			eShot1A[i].moveAngle = (count - 2) * PI / 8.0f + atan2f(player.pos.y - pos.y, player.pos.x - pos.x);
			
			count++;
			if (count >= 5)
			{
				return;
			}
		}
	}
}
