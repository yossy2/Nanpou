#pragma once

#define BOSS1_CNT 2900		// �޽���o�������ڰ�
#define BOSS1_ANIM_MAX 4	// �ޯ�޽ײт̱�Ұ��ݐ�
#define BOSS1_ANIM_SPEED 10	// �ޯ�޽ײт̱�Ұ��ݽ�߰��

#define BOSS1_SIZE_X 96		// �ޯ�޽ײт̻���X
#define BOSS1_SIZE_Y 96		// �ޯ�޽ײт̻���Y

#define BOSS1_HIT_RAD 40	// �޽�̓����蔻��̔��a
#define BOSS1_LIFE_MAX 1500	// �޽�̍ő�̗�
#define BOSS1_ATK_PTN 4		// �޽�̍U������ݐ�

#define BOSS1_SHOT_OFSET 20.0f	// �e���o��ʒu�����̈ʒu�ɒ���

// enum
// �޽��HP�̐F
enum BOSS_LIFE
{
	BOSS_LIFE_BLUE,
	BOSS_LIFE_GREEN,
	BOSS_LIFE_YELLOW,
	BOSS_LIFE_RED
};

// extern�錾
#ifdef BOSS1_DEF
#define BOSS1_EX
#else
#define BOSS1_EX extern
#endif

BOSS1_EX Boss boss1;			// 1���޽�ޯ�޽ײ�
BOSS1_EX bool bossStartFlag1;	// �޽�̓o���׸�

bool BossInit1(void);		// ������
void BossCtl1(void);		// �޽�̏���
void BossDraw1(void);		// �`��

void BossAtk1_1(void);		// �ړ����Ȃ���e�𔭎�
void BossAtk1_2(void);		// �e���~��ɔ���
void BossAtk1_3(void);		// ��]
void BossAtk1_4(void);		// �ײё�s�i

void MoveCenter(void);		// �����Ɉړ�
void ShotDelete(void);		// �U������݂������Ƃ��e����U����
