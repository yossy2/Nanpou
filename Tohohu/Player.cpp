#define PL_DEF
#include <math.h>
#include <DxLib.h>
#include "main.h"
#include "Player.h"
#include "PlayerShot.h"

int revivalCnt;		// ��������
int pShotCnt;		// ���ˊԊu�Ǘ�

// se�p
int pShotSound;		// ���������̉�

// ���@�̏�����
bool PlayerInit(void)
{
	player.pos.x = (float)(GAME_SCREEN_SIZE_X) / 2.0f;
	player.pos.y = (float)(GAME_SCREEN_SIZE_Y - PLAYER_SIZE_Y/2);
	player.speed = PLAYER_DEF_SPEED;
	player.life = PLAYER_DEF_LIFE;
	player.power = 0;
	player.drawFlag = true;
	player.blastFlag = false;
	player.revivalFlag = false;
	player.shotPowUp = 1;
	player.animCnt = 0;
	player.shotPtn = PSHOT_ID_NORMAL;

	// ���ݒ�
	keyList.move[DIR_UP] = KEY_INPUT_UP;
	keyList.move[DIR_RIGHT] = KEY_INPUT_RIGHT;
	keyList.move[DIR_DOWN] = KEY_INPUT_DOWN;
	keyList.move[DIR_LEFT] = KEY_INPUT_LEFT;
	keyList.shot = KEY_INPUT_Z;
	keyList.slow = KEY_INPUT_LCONTROL;
	keyList.change = KEY_INPUT_SPACE;

	// ��ڲ԰���Ă̏�����
	PlayerShotInit();

	// �摜�̓ǂݍ���
	if (LoadDivGraph("image/player_anim.png", PLAYER_ANIM_MAX, PLAYER_ANIM_MAX, 1,
		PLAYER_SIZE_X, PLAYER_SIZE_Y, playerImg) == -1)
	{
		AST();
		return false;
	}

	// se
	if ((pShotSound = LoadSoundMem("se/pshot.mp3")) == -1)
	{
		AST();
		return false;
	}

	if ((plPowUpSound = LoadSoundMem("se/playerpowerup.mp3")) == -1)
	{
		AST();
		return false;
	}

	revivalCnt = 0;
	return true;
}

// ���@�̏���
void PlayerCtl(void)
{
	if (player.power < 100)
	{
		player.shotPowUp = 1;
	}
	else if (player.power >= 100 && player.power < 400)
	{
		player.shotPowUp = 2;
	}
	else if (player.power >= 400)
	{
		player.shotPowUp = 3;
	}

	if (player.drawFlag || (player.revivalFlag && (revivalCnt > PLAYER_REVIVAL_CNT)))
	{
		PlayerMove();
		if (keyFram[keyList.shot] != 0 && pShotCnt > PSHOT_TIME_NORMAL)
		{
			switch (player.shotPtn)
			{
			case PSHOT_ID_NORMAL:
				PlayerAttack1();			
				break;
				
			case PSHOT_ID_FIRE:
				if (pShotCnt > PSHOT_TIME_FIRE)
				{
					PlayerAttack2();
				}
				break;

			default:
				AST();
				break;
			}
			
		}
	}

	if (keyFram[keyList.change] == 1)
	{
		player.shotPtn = (PSHOT_ID)((int)player.shotPtn + 1);
		if (player.shotPtn >= PSHOT_ID_MAX)
		{
			player.shotPtn = PSHOT_ID_NORMAL;
		}
	}
	pShotCnt++;
}

// ���@�̕`��
void PlayerDraw(void)
{
	PlayerShotDraw();
	if (player.drawFlag)
	{
		DrawRotaGraphF(player.pos.x, player.pos.y,
			1.0, 0.0, playerImg[(++player.animCnt / 5) % PLAYER_ANIM_MAX], true, false);
	}
	else if (player.blastFlag)
	{
		DrawRotaGraphF(player.pos.x, player.pos.y,
			1.0, 0.0, blastImg[player.animCnt % (BLAST_DIV_NUM_X * BLAST_DIV_NUM_Y)], true, false);
		player.animCnt++;
		if (player.animCnt >= (BLAST_DIV_NUM_X * BLAST_DIV_NUM_Y))
		{
			player.blastFlag = false;
			player.revivalFlag = true;
		}
	}
	else if(player.revivalFlag)
	{
		if (revivalCnt > PLAYER_REVIVAL_CNT && ((revivalCnt / 2) % 2))
		{
			DrawRotaGraphF(player.pos.x, player.pos.y,
				1.0, 0.0, playerImg[(++player.animCnt / 5) % PLAYER_ANIM_MAX], true, false);
		}
		else if (revivalCnt == PLAYER_REVIVAL_CNT)
		{
			player.pos.x = (float)(GAME_SCREEN_SIZE_X) / 2.0f;
			player.pos.y = (float)(GAME_SCREEN_SIZE_Y - PLAYER_SIZE_Y / 2);
			player.animCnt = 0;
		}

		if (++revivalCnt >= PLAYER_REVIVAL_CNT * 3)
		{
			revivalCnt = 0;
			player.revivalFlag = false;
			player.drawFlag = true;
		}
	}
}

// ���@�̈ړ�
void PlayerMove(void)
{
	// ========== �ᑬӰ�ޔ���
	if (keyFram[keyList.slow])
	{
		player.speed = PLAYER_DEF_SPEED / 2;
	}
	else
	{
		player.speed = PLAYER_DEF_SPEED;
	}

	// ==========�ړ��p�x����
	// �E�ړ�
	if (keyFram[keyList.move[DIR_RIGHT]])
	{
		if (keyFram[keyList.move[DIR_UP]] && keyFram[keyList.move[DIR_DOWN]] == 0)
		{
			// �㉺���̓��ゾ��������Ă����ꍇ
			if (keyFram[keyList.move[DIR_LEFT]] == 0)
			{
				// ����������Ă��Ȃ�������E��ړ�
				player.moveAngle = -PI / 4.0f;
			}
			else
			{
				// ����������Ă������ړ�
				player.moveAngle = -PI / 2.0f;
			}
		}
		else if (keyFram[keyList.move[DIR_DOWN]])
		{
			// ����������Ă�����
			if (keyFram[keyList.move[DIR_LEFT]] == 0)
			{
				// ����������Ă��Ȃ�������E���ړ�
				player.moveAngle = PI / 4.0f;
			}
			else
			{
				// ����������Ă����牺�ړ�
				player.moveAngle = PI / 2.0f;
			}
		}
		else if (keyFram[keyList.move[DIR_LEFT]] == 0)
		{
			// �E����������Ă������E�ړ��i2�΁j
			player.moveAngle = PI * 2.0f;
		}
		else
		{
			// ����������Ă������͈ړ����Ȃ�()
			player.moveAngle = 0.0f;
		}
	}
	// ���ړ�
	else if (keyFram[keyList.move[DIR_LEFT]])
	{
		if (keyFram[keyList.move[DIR_UP]] && keyFram[keyList.move[DIR_DOWN]] == 0)
		{
			// �㉺���̓��ゾ��������Ă����ꍇ����ړ�
			player.moveAngle = -PI * 3.0f / 4.0f;
		}
		else if (keyFram[keyList.move[DIR_DOWN]])
		{
			// ����������Ă����������ړ�
			player.moveAngle = PI * 3.0f / 4.0f;
		}
		else
		{
			// ������������Ă����ꍇ���ړ�
			player.moveAngle = PI;
		}
	}
	// ��ړ�
	else if (keyFram[keyList.move[DIR_UP]])
	{
		if (keyFram[keyList.move[DIR_DOWN]] == 0)
		{
			//�ゾ��������Ă������ړ�
			player.moveAngle = -PI / 2.0f;
		}
		else
		{
			// ����������Ă�����ړ����Ȃ�
			player.moveAngle = 0.0f;
		}
	}
	// ���ړ�
	else if (keyFram[keyList.move[DIR_DOWN]])
	{
		// ������������Ă����牺�ړ�
		player.moveAngle = PI / 2.0f;
	}
	else
	{
		//����������ĂȂ�������ړ����Ȃ�
		player.moveAngle = 0.0f;
	}

	// ===========�ړ��ʌ���
	if (player.moveAngle)
	{
		player.move.x = player.speed * cosf(player.moveAngle);
		player.move.y = player.speed * sinf(player.moveAngle);
	}
	else
	{
		player.move.x = 0.0f;
		player.move.y = 0.0f;
	}

	// ==========��ʊO����
	// ���E
	if (player.pos.x + player.move.x < (float)(PLAYER_SIZE_X / 2))
	{
		// ��
		if ((int)player.move.y < 0)
		{
			player.moveAngle = -PI / 2.0f;
			
		}
		else if ((int)player.move.y > 0)
		{
			player.moveAngle = PI / 2.0f;
		}
		player.move.y = player.speed * sinf(player.moveAngle);
		player.move.x = 0.0f;
		player.pos.x = (float)(PLAYER_SIZE_X / 2);
	}
	else if (player.pos.x + player.move.x > (float)(GAME_SCREEN_SIZE_X - PLAYER_SIZE_X / 2))
	{
		// �E
		if ((int)player.move.y < 0)
		{
			player.moveAngle = -PI / 2.0f;

		}
		else if ((int)player.move.y > 0)
		{
			player.moveAngle = PI / 2.0f;
		}
		player.move.y = player.speed * sinf(player.moveAngle);
		player.move.x = 0.0f;
		player.pos.x = (float)(GAME_SCREEN_SIZE_X - PLAYER_SIZE_X / 2);
	}

	//�㉺
	if (player.pos.y + player.move.y < (float)(PLAYER_SIZE_Y / 2))
	{
		// ��
		if ((int)player.move.x < 0)
		{
			player.moveAngle = PI;

		}
		else if ((int)player.move.x > 0)
		{
			player.moveAngle = PI * 2.0f;
		}
		player.move.x = player.speed * cosf(player.moveAngle);
		player.move.y = 0.0f;
		player.pos.y = (float)(PLAYER_SIZE_Y / 2);
	}
	else if ((player.pos.y + player.move.y) > (float)(GAME_SCREEN_SIZE_Y - PLAYER_SIZE_Y / 2))
	{
		// ��
		if ((int)player.move.x < 0)
		{
			player.moveAngle = PI;

		}
		else if ((int)player.move.x > 0)
		{
			player.moveAngle = PI * 2.0f;
		}
		player.move.x = player.speed * cosf(player.moveAngle);
		player.move.y = 0.0f;
		player.pos.y = (float)(GAME_SCREEN_SIZE_Y - PLAYER_SIZE_Y / 2);
	}

	// ==========�ړ�
	if (player.moveAngle != 0)
	{
		player.pos.x += player.move.x;
		player.pos.y += player.move.y;
	}
}

// ��Ұ�ނ��󂯂��Ƃ��̏���
void PlayerDamage(void)
{
	player.drawFlag = false;
	player.blastFlag = true;
	player.animCnt = 0;
	PlaySoundMem(blastSound, DX_PLAYTYPE_BACK, true);
	if (player.life > 0)
	{
		player.life--;
	}
}

// ��ڲ԰���Ă̋���
void PlayerPowUp(void)
{
	player.power += 10;
	if (player.power >= PLAYER_POWER_MAX)
	{
		player.power = PLAYER_POWER_MAX;
	}
}

// �U��
void PlayerAttack1(void)
{
	int cnt = 0;
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		if (!pShot[i].drawFlag)
		{
			pShot[i].shotID = PSHOT_ID_NORMAL;
			pShot[i].damage = 1;
			pShot[i].rad = PSHOT_HIT_RAD;
			pShot[i].speed = PSHOT_DEF_SPEED;
			switch (player.shotPowUp)
			{
			case 1:
				PlaySoundMem(pShotSound, DX_PLAYTYPE_BACK, true);
				pShot[i].pos.x = player.pos.x;
				pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
				pShot[i].moveAngle = -90;
				pShot[i].move.x = pShot[i].speed * cosf(DEG_TO_RAD(pShot[i].moveAngle));
				pShot[i].move.y = pShot[i].speed * sinf(DEG_TO_RAD(pShot[i].moveAngle));
				pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
				pShot[i].drawFlag = true;
				pShot[i].rotaAngle = 0;
				pShotCnt = 0;
				return;
			case 2:
				pShot[i].pos.x = player.pos.x - PSHOT_SIZE_X + cnt * 2 * PSHOT_SIZE_X;
				pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
				pShot[i].moveAngle = -90;
				pShot[i].move.x = pShot[i].speed * cosf(DEG_TO_RAD(pShot[i].moveAngle));
				pShot[i].move.y = pShot[i].speed * sinf(DEG_TO_RAD(pShot[i].moveAngle));
				pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
				pShot[i].drawFlag = true;
				pShot[i].rotaAngle = 0;

				if (cnt == 1)
				{
					PlaySoundMem(pShotSound, DX_PLAYTYPE_BACK, true);
					pShotCnt = 0;
					return;
				}
				break;
			case 3:
				pShot[i].pos.x = player.pos.x - PSHOT_SIZE_X + (cnt % 2) * 2 * PSHOT_SIZE_X;
				pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
				pShot[i].moveAngle = -90;
				pShot[i].rotaAngle = 0;
				if (cnt >= 2)
				{
					pShot[i].moveAngle += (-20 + (cnt % 2) * 40);
					pShot[i].rotaAngle = (-20 + (cnt % 2) * 40);
				}
				pShot[i].move.x = pShot[i].speed * cosf(DEG_TO_RAD(pShot[i].moveAngle));
				pShot[i].move.y = pShot[i].speed * sinf(DEG_TO_RAD(pShot[i].moveAngle));
				pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
				pShot[i].drawFlag = true;
				if (cnt >= 4)
				{
					PlaySoundMem(pShotSound, DX_PLAYTYPE_BACK, true);
					pShotCnt = 0;
					return;
				}
				break;
			default:
				AST();
				break;
			}

			cnt++;
		}
	}
}

void PlayerAttack2(void)
{
	for (int i = 0; i < PSHOT_NUM; i++)
	{
		if (!pShot[i].drawFlag)
		{
			pShot[i].rad = (float)(PSHOT_HIT_RAD * player.shotPowUp);
			pShot[i].damage = 10;
			PlaySoundMem(pShotSound, DX_PLAYTYPE_BACK, true);
			pShot[i].speed = (float)PSHOT_DEF_SPEED / 2.0f;
			pShot[i].shotID = PSHOT_ID_FIRE;
			pShot[i].pos.x = player.pos.x;
			pShot[i].pos.y = player.pos.y - PSHOT_SIZE_Y - PLAYER_SIZE_Y / 2;
			pShot[i].moveAngle = -90;
			pShot[i].move.x = pShot[i].speed * cosf(DEG_TO_RAD(pShot[i].moveAngle));
			pShot[i].move.y = pShot[i].speed * sinf(DEG_TO_RAD(pShot[i].moveAngle));
			pShot[i].endPos = player.pos.y - (GAME_SCREEN_SIZE_Y - PSHOT_SIZE_Y);
			pShot[i].drawFlag = true;
			pShot[i].blastFlag = false;
			pShot[i].rotaAngle = 0;
			pShotCnt = 0;
			return;
		}
	}
}