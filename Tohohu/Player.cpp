#define PL_DEF
#include <math.h>
#include <DxLib.h>
#include "main.h"
#include "Player.h"
#include "PlayerShot.h"

int revivalCnt;		// ��������

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
	player.shotPtn = PSHOT_NORMAL;

	// ���ݒ�
	keyList.move[DIR_UP] = KEY_INPUT_UP;
	keyList.move[DIR_RIGHT] = KEY_INPUT_RIGHT;
	keyList.move[DIR_DOWN] = KEY_INPUT_DOWN;
	keyList.move[DIR_LEFT] = KEY_INPUT_LEFT;
	keyList.shot = KEY_INPUT_Z;
	keyList.slow = KEY_INPUT_LCONTROL;

	// ��ڲ԰���Ă̏�����
	PlayerShotInit();

	// �摜�̓ǂݍ���
	if (LoadDivGraph("image/player_anim.png", PLAYER_ANIM_MAX, PLAYER_ANIM_MAX, 1,
		PLAYER_SIZE_X, PLAYER_SIZE_Y, playerImg) == -1)
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
	else if (player.power >= 100)
	{
		player.shotPowUp = 2;
	}

	if (player.drawFlag || (player.revivalFlag && (revivalCnt > PLAYER_REVIVAL_CNT)))
	{
		PlayerMove();
	}
	PlayerShotFunc();
}

// ���@�̕`��
void PlayerDraw(void)
{
	PlayerShotDraw();
	if (player.drawFlag)
	{
		DrawRotaGraphF(player.pos.x + GAME_SCREEN_X, player.pos.y + GAME_SCREEN_Y,
			1.0, 0.0, playerImg[(++player.animCnt / 5) % PLAYER_ANIM_MAX], true, false);
	}
	else if (player.blastFlag)
	{
		DrawRotaGraphF(player.pos.x + GAME_SCREEN_X, player.pos.y + GAME_SCREEN_Y,
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
			DrawRotaGraphF(player.pos.x + GAME_SCREEN_X, player.pos.y + GAME_SCREEN_Y,
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