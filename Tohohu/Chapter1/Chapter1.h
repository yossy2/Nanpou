#pragma once

// extern�錾
#ifdef CP1_DEF
#define CP1_EX
#else
#define CP1_EX extern
#endif

CP1_EX int chapter1Bgm;
CP1_EX int bossBgm;

bool ChapterInit1(void);		// 1�͏�����
void Chapter1(void);			// 1�͏���
void DrawChapter1(void);		// 1�͕`��
void Chapter1Sound(void);		// ����ލĐ�

void StopBgm(void);		// ���y���~�߂�
