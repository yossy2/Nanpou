#pragma once
/*
 * 1�͓GA�̒e�֘A
 */
#define ESHOT1_A_SIZE_X 16		// �摜����X
#define ESHOT1_A_SIZE_Y 16		// �摜����Y
#define ESHOT1_A_NUM 250		// �z��̌�
#define ESHOT1_A_DEF_SPEED 4.0f	// ��{�ړ���
#define ESHOT1_A_MAX_SPEED 8.0f	// �ő�ړ���
#define ESHOT1_A_CNT_MAX 10		// ���Ă̍ő�l

 // extern�錾
#ifdef ESHOT1_A_DEF
#define ESHOT1_A_EX
#else
#define ESHOT1_A_EX extern
#endif

ESHOT1_A_EX EShot eShot1A[ESHOT1_A_NUM];

bool EShotInit1_A(void);		// ������
void EShotCtl1_A(void);			// �X�V����
void DrawEShot1_A(void);		// �`��
