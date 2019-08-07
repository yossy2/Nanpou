#define BSHOT1_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Boss1.h"
#include "BossShot1.h"
#include <Player.h>

int bShotImg1;		// �ޯ�޽ײт̒e

// ������
bool BShotInit(void)
{
	bShotImg1 = LoadGraph("image/bossShot1.png");
	if (bShotImg1 == -1)
	{
		AST();
		return false;
	}

	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		bShot1[i].drawFlag = false;
	}

	return true;
}

// �޽1�̒e�̏���
void BShotCtl1(void)
{
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (bShot1[i].drawFlag)
		{
			bShot1[i].move.x = bShot1[i].speed * cosf(bShot1[i].moveAngle * PI / 180.0f);
			bShot1[i].move.y = bShot1[i].speed * sinf(bShot1[i].moveAngle * PI / 180.0f);

			bShot1[i].pos.x += bShot1[i].move.x;
			bShot1[i].pos.y += bShot1[i].move.y;

			if (player.drawFlag)
			{
				if (CheckHitObj(bShot1[i].pos, BSHOT1_SIZE_X / 3, player.pos, PLAYER_HIT_RAD))
				{
					PlayerDamage();
					bShot1[i].drawFlag = false;
				}
			}

			// ��ʊO����
			if (isMoveOut(bShot1[i].pos))
			{
				bShot1[i].drawFlag = false;
			}
		}
	}
}

// �޽1�̒e�̕`��
void BShotDraw1(void)
{
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (bShot1[i].drawFlag)
		{
			DrawRotaGraphF(bShot1[i].pos.x, bShot1[i].pos.y,
				1.0, (double)((float)bShot1[i].rotaAngle * PI / 180.0f), bShotImg1, true, false);
		}
		else 
			if (bShot1[i].blastFlag)
			{
				DrawRotaGraphF(bShot1[i].pos.x, bShot1[i].pos.y, 1.0,
					(double)((float)bShot1[i].rotaAngle * PI / 180.0f),
					blastImg[(bShot1[i].count / 2) % (BLAST_DIV_NUM_X * BLAST_DIV_NUM_Y)], true, false);

				bShot1[i].count++;
				if (bShot1[i].count >= 2 * BLAST_DIV_NUM_X * BLAST_DIV_NUM_Y)
				{
					bShot1[i].blastFlag = false;
				}
			}
	}
}