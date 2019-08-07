#define PSHOT_DEF
#include <math.h>
#include <DxLib.h>
#include "main.h"
#include "Player.h"
#include "PlayerShot.h"

// ｲﾒｰｼﾞ用
int pShotImage[PSHOT_ID_MAX];					// 弾

// 初期化
void PlayerShotInit(void)
{
	// =================ｸﾞﾗﾌｨｯｸ登録
	// 弾の登録
	pShotImage[PSHOT_ID_NORMAL] = LoadGraph("image/playershot1.png");
	if (pShotImage[PSHOT_ID_NORMAL] == -1)
	{
		AST();
		return;
	}

	pShotImage[PSHOT_ID_FIRE] = LoadGraph("image/playershot2.png");
	if (pShotImage[PSHOT_ID_FIRE] == -1)
	{
		AST();
		return;
	}

	// 変数の初期化
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		pShot[i].flag = false;
		pShot[i].pos = { 0.0f, 0.0f };
		pShot[i].speed = PSHOT_DEF_SPEED;
		pShot[i].rotaAngle = 0;
		pShot[i].move = { 0.0f, 0.0f };
		pShot[i].endPos = 0;
	}
}

// 描画
void PlayerShotDraw(void)
{
	double rate;
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		if (pShot[i].flag)
		{
			if (pShot[i].shotID == PSHOT_ID_FIRE)
			{
				rate = (double)player.shotPowUp;
				pShot[i].rotaAngle++;
			}
			else
			{
				rate = 1.0;
			}
			DrawRotaGraphF(pShot[i].pos.x, pShot[i].pos.y, rate, (double)DEG_TO_RAD(pShot[i].rotaAngle),
				pShotImage[pShot[i].shotID], true, false);
		}
	}
}

// 弾移動
void PlayerShotMove(void)
{
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		if (pShot[i].flag)
		{
			pShot[i].pos.x += pShot[i].move.x;
			pShot[i].pos.y += pShot[i].move.y;
			if (pShot[i].pos.y < pShot[i].endPos)
			{
				pShot[i].flag = false;
			}
		}
	}
}

// 弾が当たった時の処理、返り値は弾のﾀﾞﾒｰｼﾞ
int HitShot(PlayerShot *pShot)
{
	pShot->flag = false;
	return pShot->damage;
}
