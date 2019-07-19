#define BSHOT1_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Boss1.h"
#include "BossShot1.h"
#include <Player.h>

int bShotImg1;		// ËŞ¯¸Ş½×²Ñ‚Ì’e

// ‰Šú‰»
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
		bShot1[i].flag = false;
	}

	return true;
}

// ÎŞ½1‚Ì’e‚Ìˆ—
void BShotCtl1(void)
{
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (bShot1[i].flag)
		{
			bShot1[i].move.x = bShot1[i].speed * cosf(bShot1[i].moveAngle * PI / 180.0f);
			bShot1[i].move.y = bShot1[i].speed * sinf(bShot1[i].moveAngle * PI / 180.0f);

			bShot1[i].pos.x += bShot1[i].move.x;
			bShot1[i].pos.y += bShot1[i].move.y;

			// ‰æ–ÊŠO”»’è
			if (isMoveOut(bShot1[i].pos))
			{
				bShot1[i].flag = false;
			}
		}
	}
}

// ÎŞ½1‚Ì’e‚Ì•`‰æ
void BShotDraw1(void)
{
	for (int i = 0; i < BSHOT1_NUM; i++)
	{
		if (bShot1[i].flag)
		{
			DrawRotaGraph(bShot1[i].pos.x, bShot1[i].pos.y, 1.0, (double)((float)bShot1[i].rotaAngle * PI / 180.0f), bShotImg1, true, false);
		}
	}
}