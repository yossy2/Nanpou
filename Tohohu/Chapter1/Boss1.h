#pragma once

#define BOSS1_CNT 2500		// �޽���o�������ڰ�
#define BOSS1_ANIM_MAX 4	// �ޯ�޽ײт̱�Ұ��ݐ�

#define BOSS1_SIZE_X 96		// �ޯ�޽ײт̻���X
#define BOSS1_SIZE_Y 96		// �ޯ�޽ײт̻���Y

// extern�錾
#ifdef BOSS1_DEF
#define BOSS1_EX
#else
#define BOSS1_EX extern
#endif

BOSS1_EX Boss boss1;			// 1���޽�ޯ�޽ײ�

bool BossInit1(void);		// ������
void BossCtl1(void);		// �޽�̏���
void BossDraw1(void);		// �`��

void BossAtk1_1(void);		// �U������݂���1�A��]
