#pragma once

// extern�錾
#ifdef GAME_DEF
#define GAME_EX
#else
#define GAME_EX extern
#endif

GAME_EX void(*chapterFunc)(void);		// �͂�؂�ւ���֐��߲��

GAME_EX int systemImg;					// ����Ȃǂ�\�������ʘg

bool GameInit(void);		// �ްѼ�ݏ�����
void GameScene(void);		// �ްѼ�ݏ���
void GameDraw(void);		// �ްѼ�ݕ`��