#pragma once

#define SCORE_NUM 10				// ��������̐�
#define SCORE_NUM_SIZE_X 32			// ��������̻���X
#define SCORE_NUM_SIZE_Y 40			// ��������̻���Y
#define PLAYER_LIFE_STATS 2			// �c�@�̕\�����
#define PLLIFE_SIZE_X 24			// �c�@(ʰ�)�̻���X
#define PLLIFE_SIZE_Y 24			// �c�@(ʰ�)�̻���Y
#define POWGARGE_POS_X 670			// ��ܰ�ް�ނ̍��W
#define HIGHSCORE_DEF 5000			// ʲ�������̫��

// =======================�֐��������ߐ錾=========================
void UiInit(void);				// ������
void ScoreUpdate(void);			// ����
void DrawScore(void);			// �`��
