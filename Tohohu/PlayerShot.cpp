#define PSHOT_DEF
#include <math.h>
#include <DxLib.h>
#include "main.h"
#include "Player.h"
#include "PlayerShot.h"

// ²Ò°¼Ş—p
int pShotImage[PSHOT_ID_MAX];					// ’e

// ‰Šú‰»
void PlayerShotInit(void)
{
	// =================¸Ş×Ì¨¯¸“o˜^
	// ’e‚Ì“o˜^
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

	// •Ï”‚Ì‰Šú‰»
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

// •`‰æ
void PlayerShotDraw(void)
{
	double rate;
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		if (pShot[i].drawFlag)
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

			if (!pShot[i].blastFlag)
			{
				DrawRotaGraphF(pShot[i].pos.x, pShot[i].pos.y, rate, (double)DEG_TO_RAD(pShot[i].rotaAngle),
					pShotImage[pShot[i].shotID], true, false);
			}
			else
			{
				DrawRotaGraphF(pShot[i].pos.x, pShot[i].pos.y, rate, 0.0,
					bigBlastImg[pShot[i].blastCnt], true, false);
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

// ’eˆÚ“®
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

// ’e‚ª“–‚½‚Á‚½‚Ìˆ—A•Ô‚è’l‚Í’e‚ÌÀŞÒ°¼Ş
int HitShot(PlayerShot *pShot)
{
	if (pShot->shotID == PSHOT_ID_FIRE)
	{
		pShot->blastFlag = true;
		PlaySoundMem(bigBlastSound,DX_PLAYTYPE_BACK,true);
	}
	else
	{
		pShot->drawFlag = false;
	}
	return pShot->damage;
}
