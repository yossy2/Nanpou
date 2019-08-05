#define PSHOT_DEF
#include <math.h>
#include <DxLib.h>
#include "main.h"
#include "Player.h"
#include "PlayerShot.h"

// �Ұ�ޗp
int pShotImage;					// �e

// se�p
int pShotSound;					// ���������̉�

// �ްїp
int pShotCnt;						// ���ˊԊu�Ǘ�

// ������
void PlayerShotInit(void)
{
	// =================���̨���o�^
	// �e�̓o�^
	pShotImage = LoadGraph("image/playershot1.png");
	if (pShotImage == -1)
	{
		AST();
		return;
	}

	// se
	if ((pShotSound = LoadSoundMem("se/pshot.mp3")) == -1)
	{
		AST();
		return;
	}

	// �ϐ��̏�����
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		pShot[i].flag = false;
		pShot[i].pos = { 0.0f, 0.0f };
		pShot[i].speed = PSHOT_DEF_SPEED;
		pShot[i].moveAngle = -90;
		pShot[i].move = { 0.0f, 0.0f };
		pShot[i].endPos = 0;
	}
}

// ����
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
	}
	pShotCnt++;
}

// �`��
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

// �A��ɰ��
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

	// �����ĂȂ������珈���I��
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
				PlaySoundMem(pShotSound, DX_PLAYTYPE_BACK, true);
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
					PlaySoundMem(pShotSound, DX_PLAYTYPE_BACK, true);
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

// �A�������1
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

	// �����ĂȂ������珈���I��
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
				PlaySoundMem(pShotSound, DX_PLAYTYPE_BACK, true);
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
