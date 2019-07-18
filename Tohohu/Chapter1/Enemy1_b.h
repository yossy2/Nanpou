#pragma once

#define ENEMY1_B_SIZE_X 32		// �G1_B�̻���X
#define ENEMY1_B_SIZE_Y 32		// �G1_B�̻���Y
#define ENEMY1_B_NUM	50		// �G1_B�̔z���
#define ENEMY1_B_SPEED	4.0f	// �G1_B�̈ړ���

// �\���̒�`
// �G�̔z�u���
struct EnemyInit
{
	int count;		// �o�������ڰ�
	int movePtn;	// �ړ������
	Vector2 pos;	// �������W
	int moveAng;	// �ړ��p�x
};

// extern�錾
#ifdef ENEMY1_B_DEF
#define ENEMY1_B_EX
#else
#define ENEMY1_B_EX extern
#endif

ENEMY1_B_EX Enemy enemy1B[ENEMY1_B_NUM];

bool EnemyInit1_B(void);				// ������
void EnemyCtl1_B(void);					// �X�V����
void DrawEnemy1_B(void);				// �`��