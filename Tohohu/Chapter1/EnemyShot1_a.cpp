#define ESHOT1_A_DEF
#include <math.h>
#include "DxLib.h"
#include "main.h"
#include "Enemy1_a.h"
#include "EnemyShot1_a.h"

int eShotImg1A;

// èâä˙âª
bool EShotInit1_A(void)
{
	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		eShot1A[i].flag = false;
		eShot1A[i].count = 0;
		eShot1A[i].rotaAngle = 0;
	}

	// âÊëúì«Ç›çûÇ›
	eShotImg1A = LoadGraph("image/enemyShot1_A.png");
	if (eShotImg1A == -1)
	{
		AST();
		return false;
	}

	return true;
}

// çXêVèàóù
void EShotCtl1_A(void)
{
	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		if (eShot1A[i].flag)
		{
			float speed = ESHOT1_A_DEF_SPEED;
			if (eShot1A[i].count < ESHOT1_A_CNT_MAX)
			{
				speed += ESHOT1_A_MAX_SPEED * cosf(eShot1A[i].count * PI / (float)(ESHOT1_A_CNT_MAX * 2));
				eShot1A[i].count++;
			}

			eShot1A[i].speed.x = speed * cosf(eShot1A[i].moveAngle);
			eShot1A[i].speed.y = speed * sinf(eShot1A[i].moveAngle);

			eShot1A[i].pos.x += eShot1A[i].speed.x;
			eShot1A[i].pos.y += eShot1A[i].speed.y;

			// âÊñ äOîªíË
			if (eShot1A[i].pos.x < -(float)ESHOT1_A_SIZE_X ||
				eShot1A[i].pos.x >(float)(GAME_SCREEN_SIZE_X + ESHOT1_A_SIZE_X) ||
				eShot1A[i].pos.y < -(float)ESHOT1_A_SIZE_X ||
				eShot1A[i].pos.y >(float)(GAME_SCREEN_SIZE_Y + ESHOT1_A_SIZE_X))
			{
				eShot1A[i].flag = false;
			}

		}
	}
}

// ï`âÊ
void DrawEShot1_A(void)
{
	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		if (eShot1A[i].flag)
		{
			DrawRotaGraphF(eShot1A[i].pos.x + GAME_SCREEN_X, eShot1A[i].pos.y + GAME_SCREEN_Y,
				1.0, (double)((float)eShot1A[i].rotaAngle * PI / 180.0f), eShotImg1A, true, false);
			eShot1A[i].rotaAngle++;
		}
	}
}