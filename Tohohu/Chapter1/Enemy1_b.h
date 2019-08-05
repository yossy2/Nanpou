#pragma once

#define ENEMY1_B_SIZE_X 32		// �G1_B�̻���X
#define ENEMY1_B_SIZE_Y 32		// �G1_B�̻���Y
#define ENEMY1_B_NUM	40		// �G1_B�̏o����
#define ENEMY1_B_SPEED	4.0f	// �G1_B�̈ړ���
#define ENEMY1_B_MAX 500

#define ENEMY1_B_ANIM_MAX 4		// �G1_B�̱�Ұ��ݐ�

#define ENEMY1_B_MOVE_PTN_MAX 4	// �G1_B�̈ړ�����ݐ�

// extern�錾
#ifdef ENEMY1_B_DEF
#define ENEMY1_B_EX
#else
#define ENEMY1_B_EX extern
#endif

ENEMY1_B_EX Enemy enemy1B[ENEMY1_B_MAX];

bool EnemyInit1_B(void);				// ������
void EnemyCtl1_B(void);					// �X�V����
void DrawEnemy1_B(void);				// �`��

void ScanInitData1_B(void);				// �����z�u��ǂݍ���

void EnemyMove1_B_0(Enemy* enemy);		// �ړ������0
void EnemyMove1_B_1(Enemy* enemy);		// �ړ������1
void EnemyMove1_B_2(Enemy * enemy);		// �޽��p�ړ�
void EnemyMove1_B_3(Enemy * enemy);		// �޽�o��
