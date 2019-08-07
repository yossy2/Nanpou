#define ENEMY1_A_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Enemy1_a.h"
#include "EnemyShot1_a.h"
#include <Player.h>
#include <PlayerShot.h>
#include "Item.h"

int enemyImg1A[ENEMY1_A_ANIM_MAX];			// �GA�̉摜ID
void(*enemyMove1A[ENEMY1_A_MOVE_PTN_MAX])(Enemy*) = {EnemyMove1_A_0, EnemyMove1_A_1, EnemyMove1_A_2, EnemyMove1_A_3 , EnemyMove1_A_4 ,
														EnemyMove1_A_5 , EnemyMove1_A_6 , EnemyMove1_A_7 , EnemyMove1_A_8 };	// �ړ��̎��

// ������
bool EnemyInit1_A(void)
{
	ScanInitData1_A();

	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		enemy1A[i].drawFlag = false;
		enemy1A[i].blastFlag = false;
		enemy1A[i].pos = enemy1A[i].initData.pos;
		enemy1A[i].moveAngle = enemy1A[i].initData.moveAngle;
	}

	// �摜�ǂݍ���
	if (LoadDivGraph("image/enemy1_A_anim.png",
		ENEMY1_A_ANIM_MAX, ENEMY1_A_ANIM_MAX, 1,
		ENEMY1_A_SIZE_X, ENEMY1_A_SIZE_Y, enemyImg1A) == -1)
	{
		AST();
		return false;
	}

	return true;
}

// �X�V����
void EnemyCtl1_A(void)
{
	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		if (enemy1A[i].drawFlag)
		{
			// �ړ��ʌ���
			enemy1A[i].move.x = cosf((float)(enemy1A[i].moveAngle) * PI / 180.0f) * (int)ENEMY1_A_SPEED;
			enemy1A[i].move.y = sinf((float)(enemy1A[i].moveAngle) * PI / 180.0f) * (int)ENEMY1_A_SPEED;

			(*enemyMove1A[enemy1A[i].initData.movePtn])(&enemy1A[i]);
			enemy1A[i].moveCount++;

			// ��ʊO����
			if (isMoveOut(enemy1A[i].pos))
			{
				enemy1A[i].drawFlag = false;
			}

			// ���@�Ƃ̓����蔻��
			if (player.drawFlag)
			{
				if (CheckHitObj(enemy1A[i].pos, (float)ENEMY1_A_SIZE_X / 2.0f, player.pos, PLAYER_HIT_RAD))
				{
					PlayerDamage();
				}
			}

			// �e�Ƃ̓����蔻��
			for (int k = 0; k < PSHOT_NUM; k++)
			{
				if (pShot[k].flag)
				{
					if (CheckHitObj(pShot[k].pos, (float)PSHOT_HIT_RAD, enemy1A[i].pos, (float)ENEMY1_A_SIZE_X / 2.0f))
					{
						pShot[k].flag = false;
						enemy1A[i].drawFlag = false;
						enemy1A[i].blastFlag = true;
						enemy1A[i].animCount = 0;
						if (rand() % 100 >= 30)
						{
							ItemDrop(enemy1A[i].pos);
						}
						PlaySoundMem(blastSound, DX_PLAYTYPE_BACK, true);
						break;
					}
				}
			}
		}
	}

	// �G�o��
	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		if (!enemy1A[i].drawFlag && !enemy1A[i].blastFlag)
		{
			if (enemy1A[i].initData.count == framCnt)
			{
				enemy1A[i].drawFlag = true;
			}
		}
	}
}

// �`��
void DrawEnemy1_A(void)
{
	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		if (enemy1A[i].drawFlag)
		{
			DrawRotaGraphF(enemy1A[i].pos.x + GAME_SCREEN_X, enemy1A[i].pos.y + GAME_SCREEN_Y,
				1.0, 0.0, enemyImg1A[(enemy1A[i].animCount / 10) % ENEMY1_A_ANIM_MAX], true, false);
			enemy1A[i].animCount++;
		}
		else if (enemy1A[i].blastFlag)
		{
			DrawRotaGraphF(enemy1A[i].pos.x + GAME_SCREEN_X, enemy1A[i].pos.y + GAME_SCREEN_Y,
				1.0, 0.0, blastImg[enemy1A[i].animCount % (BLAST_DIV_NUM_X * BLAST_DIV_NUM_Y)], true, false);
			enemy1A[i].animCount++;
			if (enemy1A[i].animCount >= (BLAST_DIV_NUM_X * BLAST_DIV_NUM_Y))
			{
				enemy1A[i].blastFlag = false;
			}
		}
	}
}

// �U��
void EnemyAttack1_A(Vector2 pos)
{
	int count = 0;

	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		if (!eShot1A[i].drawFlag)
		{
			eShot1A[i].drawFlag = true;
			eShot1A[i].pos = pos;
			eShot1A[i].count = 0;
			eShot1A[i].moveAngle = (int)((count - 2) * 25 + atan2f(player.pos.y - pos.y, player.pos.x - pos.x) * 180.0f / PI);
			
			count++;
			if (count >= 5)
			{
				PlaySoundMem(eShotSound, DX_PLAYTYPE_BACK, true);
				return;
			}
		}
	}
}

// �����z�u��ǂݍ���
void ScanInitData1_A(void)
{
	int file;			// ̧�������
	char string[256];	// �ŏ���1�s�ǂݔ�΂��p

	// �t�@�C���ǂݍ���
	file = FileRead_open("�o���p�^�[��/Enemy1_a.csv");
	if (file == 0)
	{
		AST();
		return;
	}

	// 1�s�ǂݔ�΂�
	FileRead_gets(string, 256, file);

	// �����z�u�ݒ�
	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		FileRead_scanf(file, "%d,%d,%f,%f,%d",
			&enemy1A[i].initData.count, &enemy1A[i].initData.movePtn,
			&enemy1A[i].initData.pos.x, &enemy1A[i].initData.pos.y, &enemy1A[i].initData.moveAngle);
	}

	FileRead_close(file);
}

// �ړ�0
void EnemyMove1_A_0(Enemy *enemy)
{
	if (enemy->moveCount < 60 || enemy->moveCount > 150)
	{
		enemy->pos.x += enemy->move.x;
		enemy->pos.y += enemy->move.y;
	}
	else if (enemy->moveCount == 60)
	{
		EnemyAttack1_A(enemy->pos);
	}
	else if (enemy->moveCount == 150)
	{
		enemy->moveAngle = (int)(atan2f(player.pos.y - enemy->pos.y, player.pos.x - enemy->pos.x) * 180 / PI);
	}
}

// �ړ�1
void EnemyMove1_A_1(Enemy *enemy)
{
	enemy->pos.x += enemy->move.x;
	enemy->pos.y += enemy->move.y;
	if (enemy->moveCount == 60)
	{
		EnemyAttack1_A(enemy->pos);
	}
}

// �ړ�2
void EnemyMove1_A_2(Enemy *enemy)
{
	if (enemy->moveCount < 60 || enemy->moveCount > 180)
	{
		enemy->pos.x += enemy->move.x;
		enemy->pos.y += enemy->move.y;
	}
	else if (enemy->moveCount == 100)
	{
		EnemyAttack1_A(enemy->pos);
	}
}

// �ړ�3
void EnemyMove1_A_3(Enemy *enemy)
{
	if (enemy->moveCount < 50)
	{
		enemy->pos.x -= ENEMY1_A_SPEED;
	}
	else if (enemy->moveCount > 100)
	{
		enemy->pos.y -= ENEMY1_A_SPEED;
	}
}

// �ړ�4
void EnemyMove1_A_4(Enemy *enemy)
{
	if (enemy->moveCount < 50)
	{
		enemy->pos.x += ENEMY1_A_SPEED;
	}
	else if (enemy->moveCount > 100)
	{
		enemy->pos.y -= ENEMY1_A_SPEED;
	}
}

// �ړ�5
void EnemyMove1_A_5(Enemy *enemy)
{
	enemy->pos.x += ENEMY1_A_SPEED;
	if (enemy->moveCount == 100)
	{
		EnemyAttack1_A(enemy->pos);
	}
}

// �ړ�6
void EnemyMove1_A_6(Enemy *enemy)
{
	enemy->pos.x -= ENEMY1_A_SPEED;
	if (enemy->moveCount == 100)
	{
		EnemyAttack1_A(enemy->pos);
	}
}

// �ړ�7
void EnemyMove1_A_7(Enemy *enemy)
{
	enemy->pos.x += enemy->move.x;
	enemy->pos.y += enemy->move.y;
	if (enemy->moveCount == 100)
	{
		EnemyAttack1_A(enemy->pos);
	}
}

// �ړ�8
void EnemyMove1_A_8(Enemy *enemy)
{
	enemy->pos.x += enemy->move.x;
	enemy->pos.y += enemy->move.y;
	if (enemy->moveCount == 100)
	{
		EnemyAttack1_A(enemy->pos);
	}
}