#pragma once

#define BSHOT1_NUM 1000		// �ޯ�޽ײт̒e��

// extern�錾
#ifdef BSHOT1_DEF
#define BSHOT1_EX
#else
#define BSHOT1_EX extern
#endif

BSHOT1_EX EShot bShot1[BSHOT1_NUM];		// �ޯ�޽ײт̒e

bool BShotInit(void);		// ������
void BShotCtl1(void);		// �޽1�̒e�̏���
void BShotDraw1(void);		// �޽1�̒e�̕`��
