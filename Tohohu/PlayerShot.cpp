#define PSHOT_DEF
#include <math.h>
#include <DxLib.h>
#include "main.h"
#include "Player.h"
#include "PlayerShot.h"

// ²Ò°¼Ş—p
int pShotImage;					// ’e
int beamImage[BEAM_ANIM_NUM];		// ËŞ°Ñ

// ¹Ş°Ñ—p
int pShotCnt;						// ”­ËŠÔŠuŠÇ—

// ‰Šú‰»
void PlayerShotInit(void)
{
	// =================¸Ş×Ì¨¯¸“o˜^
	// ’e‚Ì“o˜^
	pShotImage = LoadGraph("image/playershot1.png");
	if (pShotImage == -1)
	{
		AST();
		return;
	}

	// ËŞ°Ñ‚Ì“o˜^
	if (LoadDivGraph("image/beam.png", BEAM_ANIM_NUM, BEAM_ANIM_NUM, 1, BEAM_SIZE_X, BEAM_SIZE_Y, beamImage) == -1)
	{
		AST();
		return;
	}

	// •Ï”‚Ì‰Šú‰»
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		pShot[i].flag = false;
		pShot[i].pos = { 0.0f, 0.0f };
		pShot[i].speed = PSHOT_DEF_SPEED;
		pShot[i].moveAngle = -90;
		pShot[i].move = { 0.0f, 0.0f };
		pShot[i].endPos = 0;
	}

	beam.animCnt = 0;
	beam.drawFlag = false;
	beam.hitFlag = false;
	beam.pos = { 0.0f, 0.0f };
}

// ˆ—
void PlayerShotFunc(void)
{
	switch (player.shotPtn)
	{
	case (PSHOT_NORMAL):
		PlayerShotMove();
		break;
	case (PSHOT_WIDE):
		PShotPtn1();
		break;
	case (PSHOT_BEAM):
		PShotPtn2();
		break;
	}
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
	if (beam.drawFlag)
	{
		beam.animCnt = beam.animFram / 10;
		if (beam.animCnt >= BEAM_ANIM_NUM)
		{
			beam.hitFlag = true;
			beam.animCnt = 3;
		}
		DrawRotaGraphF(GAME_SCREEN_X + beam.pos.x, GAME_SCREEN_Y + beam.pos.y, 1.0, 0.0, beamImage[beam.animCnt], true, false);
		beam.animFram++;
	}
}

// ˜AËÉ°ÏÙ
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

	// ‰Ÿ‚µ‚Ä‚È‚©‚Á‚½‚çˆ—I—¹
	if (keyFram[keyList.shot] == 0 || pShotCnt < PSHOT_TIME || !player.drawFlag)
	{
		return;
	}

	int powUp = 1;

	for (int i = 0; i < PSHOT_NUM; i++)
	{
		if (!pShot[i].flag)
		{
			if (player.shotPowUp == 1)
			{
				pShot[i].pos.x = player.pos.x;
				pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
				pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
				pShot[i].flag = true;
				pShotCnt = 0;
				break;
			}
			else if (player.shotPowUp == 2)
			{
				if (powUp == 1)
				{
					pShot[i].pos.x = player.pos.x - PSHOT_SIZE_X;
					pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
					pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
					pShot[i].flag = true;
				}
				else if (powUp == 2)
				{
					pShot[i].pos.x = player.pos.x + PSHOT_SIZE_X;
					pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
					pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
					pShot[i].flag = true;
					pShotCnt = 0;
					powUp = 0;
					break;
				}
				powUp++;
			}
		}
	}
}

// ˜AËÊßÀ°İ1
void PShotPtn1(void)
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

	// ‰Ÿ‚µ‚Ä‚È‚©‚Á‚½‚çˆ—I—¹
	if (keyFram[keyList.shot] == 0 || pShotCnt < PSHOT_TIME || !player.drawFlag)
	{
		return;
	}

	int powUp = 1;

	for (int i = 0; i < PSHOT_NUM; i++)
	{
		if (!pShot[i].flag)
		{
			if (powUp == 1)
			{
				pShot[i].pos.x = player.pos.x - PSHOT_SIZE_X;
				pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
				pShot[i].move.x = pShot[i].speed * cosf(pShot[i].moveAngle * PI / 180.0f);
				pShot[i].move.y = pShot[i].speed * sinf(pShot[i].moveAngle * PI / 180.0f);
				pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
				pShot[i].flag = true;
			}
			else if (powUp == 2)
			{
				pShot[i].pos.x = player.pos.x + PSHOT_SIZE_X;
				pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
				pShot[i].move.x = pShot[i].speed * cosf(pShot[i].moveAngle * PI / 180.0f);
				pShot[i].move.y = pShot[i].speed * sinf(pShot[i].moveAngle * PI / 180.0f);
				pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
				pShot[i].flag = true;
			}
			else if (powUp == 3)
			{
				pShot[i].pos.x = player.pos.x - PSHOT_SIZE_X;
				pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
				pShot[i].move.x = pShot[i].speed * cosf((pShot[i].moveAngle - 20) * PI / 180.0f);
				pShot[i].move.y = pShot[i].speed * sinf((pShot[i].moveAngle - 20) * PI / 180.0f);
				pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
				pShot[i].flag = true;
			}
			else if (powUp == 4)
			{
				pShot[i].pos.x = player.pos.x + PSHOT_SIZE_X;
				pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
				pShot[i].move.x = pShot[i].speed * cosf((pShot[i].moveAngle + 20) * PI / 180.0f);
				pShot[i].move.y = pShot[i].speed * sinf((pShot[i].moveAngle + 20) * PI / 180.0f);
				pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
				pShot[i].flag = true;
				pShotCnt = 0;
				powUp = 0;
				break;
			}
			powUp++;
		}
	}
}

// ˜AËÊßÀ°İ2
void PShotPtn2(void)
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

	beam.pos.x = player.pos.x;
	beam.pos.y = player.pos.y - ((BEAM_SIZE_Y + PLAYER_SIZE_Y) / 2);

	// ‰Ÿ‚µ‚Ä‚È‚©‚Á‚½‚çˆ—I—¹
	if (keyFram[keyList.shot] == 0 || !player.drawFlag)
	{
		beam.drawFlag = false;
		beam.hitFlag = false;
		return;
	}

	if (!beam.drawFlag)
	{
		beam.animCnt = 0;
		beam.animFram = 0;
		beam.drawFlag = true;
	}

	if (pShotCnt < PSHOT_TIME)
	{
		return;
	}

	int powUp = 1;

	for (int i = 0; i < PSHOT_NUM; i++)
	{
		if (!pShot[i].flag)
		{
			if (powUp == 1)
			{
				pShot[i].pos.x = player.pos.x - PSHOT_SIZE_X;
				pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
				pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
				pShot[i].flag = true;
			}
			else if (powUp == 2)
			{
				pShot[i].pos.x = player.pos.x + PSHOT_SIZE_X;
				pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
				pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
				pShot[i].flag = true;
				pShotCnt = 0;
				powUp = 0;
				break;
			}
			powUp++;
		}
	}
}

// ËŞ°Ñ‚Ì“–‚½‚è”»’è
bool BeamCheckHit(Vector2 pos, float hitrad)
{
	bool hitFlag = false;

	if (!beam.hitFlag)
	{
		return hitFlag;
	}

	float a = sqrtf((beam.pos.x * pos.y) - (beam.pos.y * pos.x));
	float b = sqrtf((pos.x * pos.x) + (pos.y * pos.y));
	float c = hitrad + BEAM_HIT;

	if (a / b <= c)
	{
		hitFlag = true;
	}

	return hitFlag;
}