#pragma once

#define ENEMY1_A_SIZE_X 32		// �G1_A�̻���X
#define ENEMY1_A_SIZE_Y 32		// �G1_A�̻���Y
#define ENEMY1_A_NUM	50		// �G1_A�̔z���
#define ENEMY1_A_SPEED	4.0f	// �G1_A�̈ړ���

#define ENEMY1_A_MOVE_PTN_MAX 1	// �G1_A�̈ړ�����ݐ�

#define ENEMY1_A_INV 20			// �G1_A�̏o���Ԋu

// extern�錾
#ifdef ENEMY1_A_DEF
#define ENEMY1_A_EX
#else
#define ENEMY1_A_EX extern
#endif

ENEMY1_A_EX Enemy enemy1A[ENEMY1_A_NUM];

bool EnemyInit1_A(void);				// ������
void EnemyCtl1_A(void);					// �X�V����
void DrawEnemy1_A(void);				// �`��
void EnemyAttack1_A(Vector2 pos);		// �U��

void ScanInitData1_A(void);				// �����z�u��ǂݍ���		

void EnemyMove1_A_0(Enemy * enemy);		// �ړ������0
