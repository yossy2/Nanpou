#define PSHOT_DEF
#include <math.h>
#include <DxLib.h>
#include "main.h"
#include "Player.h"
#include "PlayerShot.h"

// ｲﾒｰｼﾞ用
int pShotImage;					// 描画登録用変数

// ｹﾞｰﾑ用
int pShotCnt;						// 発射間隔管理

// 初期化
void PlayerShotInit(void)
{
	// ｸﾞﾗﾌｨｯｸ登録
	pShotImage = LoadGraph("image/playershot1.png");
	if (pShotImage == -1)
	{
		AST();
		return;
	}

	// 変数の初期化
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		pShot[i].flag = false;
		pShot[i].pos = { 0, 0 };
		pShot[i].speed = PSHOT_DEF_SPEED;
		pShot[i].endPos = 0;
	}
}

// 処理
void PlayerShotFunc(void)
{
	PlayerShotMove();
	pShotCnt++;
}

// 描画
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

// 移動処理
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
	if (keyFram[keyList.shot] == 0 || pShotCnt < PSHOT_TIME || !player.flag)
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