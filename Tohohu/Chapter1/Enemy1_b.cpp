#define ENEMY1_B_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Enemy1_b.h"
#include <Player.h>

int enemyImg1B;			// �GA�̉摜ID

						// ������
bool EnemyInit1_B(void)
{
	ScanInitData1_B();

	for (int i = 0; i < ENEMY1_B_NUM; i++)
	{
		enemy1B[i].drawFlag = false;
		enemy1B[i].pos = enemy1B[i].initData.pos;
		enemy1B[i].moveAngle = enemy1B[i].initData.moveAngle;
	}

	// �摜�ǂݍ���
	enemyImg1B = LoadGraph("image/enemy1_B.png");
	if (enemyImg1B == -1)
	{
		AST();
		return false;
	}

	return true;
}

// �X�V����
void EnemyCtl1_B(void)
{
	// �G�ړ�
	for (int i = 0; i < ENEMY1_B_NUM; i++)
	{
		if (enemy1B[i].drawFlag)
		{
			// �ړ��ʌ���
			enemy1B[i].move.x = cosf((float)(enemy1B[i].moveAngle) * PI / 180.0f) * (int)ENEMY1_B_SPEED;
			enemy1B[i].move.y = sinf((float)(enemy1B[i].moveAngle) * PI / 180.0f) * (int)ENEMY1_B_SPEED;

			enemy1B[i].pos.x += enemy1B[i].move.x;
			enemy1B[i].pos.y += enemy1B[i].move.y;
			enemy1B[i].moveCount++;

			// ��ʊO����
			if (isMoveOut(enemy1B[i].pos))
			{
				enemy1B[i].drawFlag = false;
			}

			if (enemy1B[i].moveCount % 2 == 0)
			{
				enemy1B[i].moveAngle++;
			}
		}
	}

	// �G�o��
	for (int i = 0; i < ENEMY1_B_NUM; i++)
	{
		if (!enemy1B[i].drawFlag)
		{
			if (enemy1B[i].initData.count == flamCnt)
			{
				enemy1B[i].drawFlag = true;
			}
		}
	}
}

// �`��
void DrawEnemy1_B(void)
{
	for (int i = 0; i < ENEMY1_B_NUM; i++)
	{
		if (enemy1B[i].drawFlag)
		{
			DrawRotaGraphF(enemy1B[i].pos.x + GAME_SCREEN_X, enemy1B[i].pos.y + GAME_SCREEN_Y,
				1.0, 0.0, enemyImg1B, true, false);
		}
	}
}

// �����z�u��ǂݍ���
void ScanInitData1_B(void)
{
	int file;			// ̧�������
	char string[256];		// �ŏ���1�s�ǂݔ�΂��p

	// �t�@�C���ǂݍ���
	file = FileRead_open("�o���p�^�[��/Enemy1_b.csv");
	if (file == 0)
	{
		AST();
		return;
	}

	// 1�s�ǂݔ�΂�
	FileRead_gets(string, 256, file);

	// �����z�u�ݒ�
	for (int i = 0; i < 10; i++)
	{
		FileRead_scanf(file, "%d,%d,%f,%f,%d",
			&enemy1B[i].initData.count, &enemy1B[i].initData.movePtn,
			&enemy1B[i].initData.pos.x, &enemy1B[i].initData.pos.y, &enemy1B[i].initData.moveAngle);
	}
	
	FileRead_close(file);

}