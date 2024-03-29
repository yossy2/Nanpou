#define PSHOT_DEF
#include <math.h>
#include <DxLib.h>
#include "main.h"
#include "Player.h"
#include "PlayerShot.h"

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
		pShot[i].drawFlag = false;
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
		if (pShot[i].drawFlag)
		{
			if (pShot[i].shotID == PSHOT_ID_FIRE && !pShot[i].blastFlag)
			{
				rate = (double)player.shotPowUp;
				pShot[i].rotaAngle++;
			}
			else
			{
				rate = 1.0;
			}

			if (!pShot[i].blastFlag)
			{				
				DrawRotaGraphF(pShot[i].pos.x, pShot[i].pos.y, rate, (double)DEG_TO_RAD(pShot[i].rotaAngle),
					pShotImage[pShot[i].shotID], true, false);
			}
			else
			{
				SetDrawBright(150, 150, 150);
				DrawRotaGraphF(pShot[i].pos.x, pShot[i].pos.y, rate, 0.0,
					bigBlastImg[pShot[i].blastCnt], true, false);
				SetDrawBright(255, 255, 255);
				pShot[i].blastCnt++;
				if (pShot[i].blastCnt >= BIG_BLAST_ANIM_MAX)
				{
					pShot[i].blastFlag = false;
					pShot[i].blastCnt = 0;
					pShot[i].drawFlag = false;
				}
			}
		}
	}
}

// 弾移動
void PlayerShotMove(void)
{
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		if (pShot[i].drawFlag)
		{
			pShot[i].pos.x += pShot[i].move.x;
			pShot[i].pos.y += pShot[i].move.y;
			if (pShot[i].pos.y < pShot[i].endPos)
			{
				pShot[i].drawFlag = false;
			}
		}
	}
}

// 弾が当たった時の処理、返り値は弾のﾀﾞﾒｰｼﾞ
int HitShot(PlayerShot *pShot)
{
	if (pShot->shotID == PSHOT_ID_FIRE)
	{
		pShot->blastFlag = true;
		ChangeVolumeSoundMem(150, bigBlastSound);
		PlaySoundMem(bigBlastSound,DX_PLAYTYPE_BACK,true);
		ChangeVolumeSoundMem(2550, bigBlastSound);
	}
	else
	{
		pShot->drawFlag = false;
	}
	return pShot->damage;
}
