#pragma once

#define BOSS_CNT 2500		// �޽���o�������ڰ�

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
