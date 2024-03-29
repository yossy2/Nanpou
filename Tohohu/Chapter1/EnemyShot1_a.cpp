#define ESHOT1_A_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Enemy1_a.h"
#include "EnemyShot1_a.h"
#include "Player.h"

int eShotImg1A;

// 初期化
bool EShotInit1_A(void)
{
	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		eShot1A[i].drawFlag = false;
		eShot1A[i].count = 0;
		eShot1A[i].rotaAngle = 0;
	}

	// 画像読み込み
	eShotImg1A = LoadGraph("image/enemyShot1_A.png");
	if (eShotImg1A == -1)
	{
		AST();
		return false;
	}

	return true;
}

// 更新処理
void EShotCtl1_A(void)
{
	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		if (eShot1A[i].drawFlag)
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

			// 画面外判定
			if (isMoveOut(eShot1A[i].pos))
			{
				eShot1A[i].drawFlag = false;
			}
		}
	}
	// 当たり判定
	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		if (eShot1A[i].drawFlag && player.drawFlag)
		{
			if (CheckHitObj(eShot1A[i].pos, ESHOT1_A_SIZE_X / 2, player.pos, PLAYER_HIT_RAD))
			{
				PlayerDamage();
				eShot1A[i].drawFlag = false;
			}
		}
	}
}

// 描画
void DrawEShot1_A(void)
{
	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		if (eShot1A[i].drawFlag)
		{
			DrawRotaGraphF(eShot1A[i].pos.x, eShot1A[i].pos.y,
				1.0, (double)((float)eShot1A[i].rotaAngle * PI / 180.0f), eShotImg1A, true, false);
			eShot1A[i].rotaAngle++;
		}
	}
}