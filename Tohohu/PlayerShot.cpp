#define PSHOT_DEF
#include <math.h>
#include <DxLib.h>
#include "main.h"
#include "Player.h"
#include "PlayerShot.h"

// ²Ò°¼Ş—p
int pShotImage;					// •`‰æ“o˜^—p•Ï”

// ¹Ş°Ñ—p
int pShotCnt;						// ”­ËŠÔŠuŠÇ—

// ‰Šú‰»
void PlayerShotInit(void)
{
	// ¸Ş×Ì¨¯¸“o˜^
	pShotImage = LoadGraph("image/playershot1.png");
	if (pShotImage == -1)
	{
		AST();
		return;
	}

	// •Ï”‚Ì‰Šú‰»
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		pShot[i].flag = false;
		pShot[i].pos = { 0, 0 };
		pShot[i].speed = PSHOT_DEF_SPEED;
		pShot[i].endPos = 0;
	}
}

// ˆ—
void PlayerShotFunc(void)
{
	PlayerShotMove();
	pShotCnt++;
}

// •`‰æ
void PlayerShotDraw(void)
{
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		if (pShot[i].flag)
		{
			DrawRotaGraphF(pShot[i].pos.x + GAME_SCREEN_X, pShot[i].pos.y + GAME_SCREEN_Y, 1.0, 0.0, pShotImage, true, false);
		}
	}
}

// ˆÚ“®ˆ—
void PlayerShotMove(void)
{
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		if (pShot[i].flag)
		{
			pShot[i].pos.y -= pShot[i].speed;
			if (pShot[i].pos.y < pShot[i].endPos)
			{
				pShot[i].flag = false;
			}
		}
	}
	if (!CheckHitKey(keyList.shot) || pShotCnt < PSHOT_TIME || !player.flag)
	{
		return;
	}
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		if (!pShot[i].flag)
		{
			pShot[i].pos.x = player.pos.x;
			pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
			pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
			pShot[i].flag = true;
			pShotCnt = 0;
			break;
		}
	}
}