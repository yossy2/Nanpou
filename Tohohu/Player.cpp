#define PL_DEF
#include <math.h>
#include "DxLib.h"
#include "main.h"
#include "Player.h"

// ���@�̏�����
bool PlayerInit(void)
{
	player.pos.x = (float)(GAME_SCREEN_SIZE_X) / 2.0f;
	player.pos.y = (float)(GAME_SCREEN_SIZE_Y - PLAYER_SIZE_Y/2);
	player.speed = PLAYER_DEF_SPEED;

	// ���ݒ�
	keyList.move[DIR_UP] = KEY_INPUT_UP;
	keyList.move[DIR_RIGHT] = KEY_INPUT_RIGHT;
	keyList.move[DIR_DOWN] = KEY_INPUT_DOWN;
	keyList.move[DIR_LEFT] = KEY_INPUT_LEFT;

	keyList.slow = KEY_INPUT_LCONTROL;

	// �摜�̓ǂݍ���
	playerImg = LoadGraph("image/player.png");
	if (playerImg == -1)
	{
		AST();
		return false;
	}
	return true;
}

// ���@�̏���
void PlayerCtl(void)
{
	PlayerMove();
}

// ���@�̕`��
void PlayerDraw(void)
{
	DrawRotaGraphF(player.pos.x + GAME_SCREEN_X, player.pos.y + GAME_SCREEN_Y,1.0,0.0, playerImg,true,false);
}

// ���@�̈ړ�
void PlayerMove(void)
{
	// ========== �ᑬӰ�ޔ���
	if (CheckHitKey(keyList.slow))
	{
		player.speed = PLAYER_DEF_SPEED / 2;
	}
	else
	{
		player.speed = PLAYER_DEF_SPEED;
	}

	// ==========�ړ��p�x����
	// �E�ړ�
	if (CheckHitKey(keyList.move[DIR_RIGHT]))
	{
		if (CheckHitKey(keyList.move[DIR_UP]) && !CheckHitKey(keyList.move[DIR_DOWN]))
		{
			// �㉺���̓��ゾ��������Ă����ꍇ
			if (!CheckHitKey(keyList.move[DIR_LEFT]))
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
		else if (CheckHitKey(keyList.move[DIR_DOWN]))
		{
			// ����������Ă�����
			if (!CheckHitKey(keyList.move[DIR_LEFT]))
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
		else if (!CheckHitKey(keyList.move[DIR_LEFT]))
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
	else if (CheckHitKey(keyList.move[DIR_LEFT]))
	{
		if (CheckHitKey(keyList.move[DIR_UP]) && !CheckHitKey(keyList.move[DIR_DOWN]))
		{
			// �㉺���̓��ゾ��������Ă����ꍇ����ړ�
			player.moveAngle = -PI * 3.0f / 4.0f;
		}
		else if (CheckHitKey(keyList.move[DIR_DOWN]))
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
	else if (CheckHitKey(keyList.move[DIR_UP]))
	{
		if (!CheckHitKey(keyList.move[DIR_DOWN]))
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
	else if (CheckHitKey(keyList.move[DIR_DOWN]))
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